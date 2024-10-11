/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:31:13 by alvutina          #+#    #+#             */
/*   Updated: 2024/09/24 11:31:14 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*parse_command_string(int i, char *input, t_shell_context *o, int *err)
{
	while (input[i])
	{
		if (input[i] == '\'')
			input = parse_for_quote(input, &i, err);
		else if (input[i] == '"')
			input = parse_for_dquote(input, &i, o, err);
		else if (input[i] == '$'
			&& (ft_isalnum(input[i + 1]) || input[i + 1] == '?'))
			input = parse_dollar(input, &i, o);
		else if (input[i] == '<' || input[i] == '>')
			input = redirects(input, &i, o, err);
		else if (input[i] == '|')
			input = parse_pipe(input, &i, o, err);
		else if (input[i] == ' ')
			input = parse_spaces(input, &i, o);
		if (!input)
			break ;
		if (ft_strlen(input) == 0)
			break ;
		i++;
	}
	if (input)
		put_str_to_list(input, o);
	put_list_to_pipe(o);
	return (input);
}

void	pars(char *input, t_shell_context *o)
{
	int		i;
	int		err;

	if (input[0] == 0)
	{
		free(input);
		return ;
	}
	input = space_remove(input);
	i = 0;
	err = -1;
	input = parse_command_string(i, input, o, &err);
	if (err > 1)
	{
		free_str_in_list(o->list);
		free_list(&o->list);
		free_pipes(&o->pipes);
		g_exit = 258;
	}
	if (err == 1)
		g_exit = 0;
}
