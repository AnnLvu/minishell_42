/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:29:17 by alvutina          #+#    #+#             */
/*   Updated: 2024/09/24 11:38:54 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	The function excutes a builtin-funcion and return its result or
	-1 if it's not a builtin. */
int	exec_builtin(t_pipe_node *pipe, int j, t_shell_context *o, \
				int is_single_cmd)
{
	int		i;
	int		res;
	char	*builtin_str[8];
	int		(*builtin_func[7])(t_pipe_node *, t_shell_context *o);

	res = -1;
	init_builtin_arrs(builtin_str, builtin_func);
	i = 0;
	while (builtin_str[i])
	{
		if ((ft_strlen(builtin_str[i]) == ft_strlen(pipe->arg[0])) && \
			(ft_strncmp(builtin_str[i], pipe->arg[0], \
										ft_strlen(builtin_str[i])) == 0))
		{
			if (is_single_cmd == 1)
				return (run_builtin_single(pipe, j, o, builtin_func[i]));
			else
				res = (*builtin_func[i])(pipe, o);
			break ;
		}
		i++;
	}
	return (res);
}

void	exec_child(char **arg, t_pipe_node *pipe, int j, t_shell_context *o)
{
	int		res;
	char	*path;
	char	**env_arr;

	set_pipes_fd(o, j, pipe, 0);
	res = -1;
	if (pipes_size(o->pipes) != 1)
		res = exec_builtin(pipe, j, o, 0);
	if (res != -1)
	{
		close_fd(o);
		free_all(o);
		exit (res);
	}
	path = create_path_to_cmd(&arg[0], o);
	env_arr = create_env_arr(o);
	if (!(path) || execve(path, arg, env_arr) == -1)
	{
		err_msg_cmd(arg[0], "command not found");
		free_env_arr(env_arr);
		free(path);
		close_fd(o);
		free_all(o);
		exit(1);
	}
}

int	exec_cmd(char **arg, t_shell_context *o, int j, t_pipe_node *pipe)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		err_msg_cmd("fork", strerror(errno));
		return (1);
	}
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		exec_child(arg, pipe, j, o);
	}
	if (!pipe->next)
		o->pid_last_cmd = pid;
	return (0);
}

/*waiting when all processes will be finished*/
int	wait_child_process_complete(t_shell_context *o, int res_one_builtin)
{
	pid_t		wpid;
	int			status;
	int			res;

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	close_all_pipes_fd(o);
	close_fd(o);
	res = res_one_builtin;
	wpid = waitpid(-1, &status, 0);
	while (wpid > 0)
	{
		if (wpid == o->pid_last_cmd)
		{
			if (WIFSIGNALED(status))
				res = 128 + WTERMSIG(status);
			else if (WIFEXITED(status))
				res = WEXITSTATUS(status);
			else
				res = status;
			g_exit = res;
		}
		wpid = waitpid(-1, &status, 0);
	}
	return (sig_handler(), res);
}

int	execute(t_shell_context *o)
{
	t_pipe_node	*tmp_pipe;
	int			res;
	int			j;

	if (!o->pipes)
		return (g_exit);
	create_fd_pipes(o);
	tmp_pipe = o->pipes;
	j = 0;
	while (tmp_pipe != NULL)
	{
		res = -1;
		if (pipes_size(o->pipes) == 1)
			res = exec_builtin(tmp_pipe, j, o, 1);
		if (res == -1)
			res = exec_cmd(tmp_pipe->arg, o, j, tmp_pipe);
		tmp_pipe = tmp_pipe->next;
		j++;
	}
	res = wait_child_process_complete(o, res);
	return (res);
}
