/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:30:59 by alvutina          #+#    #+#             */
/*   Updated: 2024/09/24 11:31:00 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_pipe_node	*pipes_new_node(char **arg, t_shell_context *o)
{
	t_pipe_node	*new;

	(void)o;
	new = malloc(sizeof(t_pipe_node));
	if (!new)
		return (NULL);
	new->index = o->pipe_index;
	new->arg = arg;
	if (o->heredoc)
		new->heredoc = ft_strdup(o->heredoc);
	else
		new->heredoc = NULL;
	new->next = NULL;
	new->fd_in = o->fd_in;
	new->fd_out = o->fd_out;
	new->is_heredoc = o->is_heredoc;
	new->is_was_dollar = o->is_was_dollar;
	return (new);
}

void	pipes_add_back(t_pipe_node **pipes, t_pipe_node *new)
{
	t_pipe_node	*head;

	head = *pipes;
	if (head && new)
	{
		while (head->next)
			head = head->next;
		head->next = new;
	}
}

int	pipes_size(t_pipe_node *pipes)
{
	int		count;

	count = 0;
	while (pipes)
	{
		count++;
		pipes = pipes->next;
	}
	return (count);
}

char	**put_list_to_arg(int size, t_shell_context *o)
{
	int		i;
	char	**res;

	res = malloc(sizeof(char *) * (size + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (o->list)
	{
		res[i] = o->list->str;
		o->list = o->list->next;
		i++;
	}
	res[i] = NULL;
	return (res);
}

void	put_list_to_pipe(t_shell_context *o)
{
	t_list	*tmp;
	int		size;
	char	**arg;

	size = lst_size(o->list);
	tmp = o->list;
	arg = put_list_to_arg(size, o);
	if (!o->pipes)
		o->pipes = pipes_new_node(arg, o);
	else
	{
		pipes_add_back(&o->pipes, pipes_new_node(arg, o));
		o->is_pipe = 1;
	}
	o->pipe_index++;
	re_init_o_fd(o);
	free_list(&tmp);
	o->list = NULL;
}
