/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:31:03 by alvutina          #+#    #+#             */
/*   Updated: 2024/09/24 11:31:04 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*free_two_str(char *s1, char *s2)
{
	free(s1);
	free(s2);
	return (NULL);
}

char	*free_three_str(char *s1, char *s2, char *s3)
{
	free(s1);
	free(s2);
	free(s3);
	return (NULL);
}

void	free_pipes(t_pipe_node **pipes)
{
	t_pipe_node	*tmp;

	while (*pipes)
	{
		free_array((*pipes)->arg);
		free((*pipes)->heredoc);
		tmp = *pipes;
		*pipes = (*pipes)->next;
		free(tmp);
	}
	(*pipes) = NULL;
}

void	free_array(char **array)
{
	int	i;

	if (array)
	{
		i = 0;
		while (array[i])
			free(array[i++]);
		free(array);
	}
}
