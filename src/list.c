/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:33:16 by alvutina          #+#    #+#             */
/*   Updated: 2024/09/24 11:33:22 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_lstnew(char *str)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->str = str;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **link, t_list *new)
{
	t_list	*head;

	head = *link;
	if (head && new)
	{
		while (head->next)
			head = head->next;
		head->next = new;
	}
}

int	lst_size(t_list *link)
{
	int		count;

	count = 0;
	while (link)
	{
		count++;
		link = link->next;
	}
	return (count);
}

void	free_list(t_list**link)
{
	t_list	*tmp;

	while (*link)
	{
		tmp = *link;
		*link = (*link)->next;
		free(tmp);
	}
}

void	free_str_in_list(t_list *list)
{
	while (list)
	{
		if (list->str)
			free(list->str);
		list = list->next;
	}
}
