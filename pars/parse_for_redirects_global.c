/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_for_redirects_global.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:31:43 by alvutina          #+#    #+#             */
/*   Updated: 2024/09/24 11:31:44 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*redirects(char *input, int *i, t_shell_context *o, int *err)
{
	if (input[*i] == '<' && (input[*i + 1] == '<' || \
	(input[*i + 1] == '<' && input[*i + 2] == '-')))
		input = parse_heredoc(input, i, o, err);
	else if (input[*i] == '<')
		input = parse_in_redirect(input, i, o, err);
	else if (input[*i] == '>' && input[*i + 1] == '>')
		input = parse_rewrite_redirect(input, i, o, err);
	else if (input[*i] == '>')
		input = parse_out_redirect(input, i, o, err);
	return (input);
}
