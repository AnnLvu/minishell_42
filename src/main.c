/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:33:27 by alvutina          #+#    #+#             */
/*   Updated: 2024/09/24 11:33:28 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit = 0;

void	handler_sigint(int sig)
{
	(void)sig;
	rl_on_new_line();
	rl_redisplay();
	write(1, "  \n", 3);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_exit = 130;
}

void	sig_handler(void)
{
	struct sigaction	sa;
	struct sigaction	sq;

	ft_memset(&sq, 0, sizeof(sq));
	sq.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sq, NULL);
	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = handler_sigint;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
}

void	loop(t_shell_context *o)
{
	char	*input;

	sig_handler();
	while (1)
	{
		input = readline(SHELL_NAME);
		if (!input)
		{
			ft_putstr_fd("exit\n", 1);
			break ;
		}
		if (ft_strlen(input) != 0)
			add_history(input);
		pars(input, o);
		g_exit = execute(o);
		free_fd_pipes(o->pipe_fds, pipes_size(o->pipes) - 1);
		o->pipe_fds = NULL;
		free_pipes(&o->pipes);
		o->pipes = NULL;
		o->pid_last_cmd = -1;
		o->counter = 0;
	}
}

int	main(int argc, char **argv, char **env)
{
	t_shell_context	*o;

	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("Error: minishell does'n accept arguments\n", 2);
		return (0);
	}
	if (!isatty(STDIN_FILENO) || !isatty(STDOUT_FILENO))
	{
		ft_putstr_fd("Error: Non-interactive mode is prohibited\n", 2);
		return (0);
	}
	g_exit = 0;
	o = init_o(env);
	if (!o)
		exit(EXIT_FAILURE);
	loop(o);
	free_all(o);
	o = NULL;
	return (g_exit);
}
