/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:30:42 by alvutina          #+#    #+#             */
/*   Updated: 2024/09/24 11:39:54 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# define _GNU_SOURCE
# define SHELL_NAME "minishell% "
# define QUOTE "Error! Unclosed quote"
# define DQUOTE "Error! Unclosed dquote"
# define ERROR_NAME "minishell"
# define TOKEN "Error! Unclosed pipe"
# define IN "syntax error near unexpected token `<'"
# define OUT "syntax error near unexpected token `>'"
# define PIPE "syntax error near unexpected token `|'"
# define NEW "syntax error near unexpected token `newline'"

extern int	g_exit;

typedef struct s_join_params {
	char	*start;
	char	*dollar_value;
	char	*mid;
	int		*index;
	int		orig_mid_len;
}			t_join_params;

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}					t_list;

typedef struct s_env_var
{
	char				*key;
	char				*value;
	struct s_env_var	*next;
	int					sign_exp;
}						t_env_var;

typedef struct s_pipe_node
{
	int					index;
	char				**arg;
	char				*heredoc;
	struct s_pipe_node	*next;
	int					fd_in;
	int					fd_out;
	int					is_heredoc;
	int					is_was_dollar;
}		t_pipe_node;

typedef struct s_shell_context
{
	int			exit;
	char		**env;
	char		*heredoc;
	int			is_pipe;
	int			fd_in;
	int			fd_out;
	int			is_heredoc;
	int			is_was_dollar;
	int			pipe_index;
	t_env_var	*env_st;
	t_pipe_node	*pipes;
	int			**pipe_fds;
	int			origin_fd_in;
	int			origin_fd_out;
	int			pid_last_cmd;
	int			counter;
	t_list		*list;

}			t_shell_context;

void			close_fd(t_shell_context *o);
int				ft_printf(const char *format, ...);
void			pars(char *input, t_shell_context *o);
char			*parse_command_string(int i, char *input, \
t_shell_context *o, int *err);
char			*space_remove(char *input);
char			*remove_end_spaces(char *input);
char			*remove_start_spaces(char *input);
void			free_list(t_list**link);
void			free_str_in_list(t_list *list);
void			free_pipes(t_pipe_node **pipes);
void			free_array(char **array);
void			put_list_to_pipe(t_shell_context *o);
char			**put_list_to_arg(int size, t_shell_context *o);
int				pipes_size(t_pipe_node *pipes);
void			pipes_add_back(t_pipe_node **pipes, t_pipe_node *new);
t_pipe_node		*pipes_new_node(char **arg, t_shell_context *o);
char			*parse_for_quote(char *input, int *index, int *err);
char			*extract_quote_prefix(int *i, int *index, char *input);
char			*free_two_str(char *s1, char *s2);
char			*free_three_str(char *s1, char *s2, char *s3);
char			*parse_for_dquote(char *input, int *index, \
t_shell_context *o, int *err);
char			*extract_dquote_prefix(int *i, int *index, char *input);
void			put_str_to_list(char *str, t_shell_context *o);
char			*find_dollar(char *mid, t_shell_context *o);
char			*parse_dollar(char *mid, int *index, t_shell_context *o);
char			*get_env_value(const char *key, t_shell_context *o);
char			*redirects(char *input, int *i, t_shell_context *o, int *err);
char			*parse_pipe(char *input, int *index, \
t_shell_context *o, int *err);
int				check_unclosed_pipe(char *input, char *end, int *err);
int				check_for_pipe_error(char *input, int i, int *err);
int				validate_pipe_conditions(char *input, \
t_shell_context *o, int *err);
void			skip_leading_spaces(char *input, int *i);
char			*parse_spaces(char *input, int *index, t_shell_context *o);
char			*parse_heredoc(char *input, int *index, \
t_shell_context *o, int *err);
int				read_heredoc_lines(char *limit, t_shell_context *o);
int				check_str(char *str, char *limit, char *res);
int				process_heredoc_result(char *res, char *limit, \
char *str, t_shell_context *o);
void			skip_until_token_or_space(char *input, int *i);
int				validate_non_empty(char *s);
char			*setup_redirect_start(int *i, int *index, char *input);
int				validate_token(char token);
char			*parse_in_redirect(char *input, int *index, \
t_shell_context *o, int *err);
char			*initialize_redirect_start(int *i, int *index, char *input);
int				open_file_for_reading(char *file, t_shell_context *o);
int				validate_redirection_token(char token, int *err);
char			*create_error_message(char *file);
char			*expand_file(char *file, t_shell_context *o);
char			*parse_rewrite_redirect(char *input, int *index, \
t_shell_context *o, int *err);
int				open_append_file(char *file, t_shell_context *o);
char			*parse_out_redirect(char *input, int *index, \
t_shell_context *o, int *err);
int				open_file_for_writing(char *file, t_shell_context *o, int *err);
int				main(int argc, char **argv, char **env);
void			loop(t_shell_context *o);
void			sig_handler(void);
void			free_env_struct(t_shell_context *o);
t_shell_context	*init_o(char **env);
int				lst_size(t_list *link);
void			ft_lstadd_back(t_list **link, t_list *new);
t_list			*ft_lstnew(char *str);
int				lst_add_back(t_shell_context	*o, t_env_var *lst);
void			re_init_o_fd(t_shell_context *o);
t_env_var		*parse_key_val(const char *env, \
t_shell_context *o, int sign_exp);
char			*ft_strndup(const char *s, size_t n);
void			free_all(t_shell_context *o);
int				execute(t_shell_context *o);
int				exec_echo(t_pipe_node *pipe, t_shell_context *o);
int				exec_cd(t_pipe_node *pipe, t_shell_context *o);
int				exec_pwd(t_pipe_node *pipe, t_shell_context *o);
int				exec_export(t_pipe_node *pipe, t_shell_context *o);
int				exec_unset(t_pipe_node *pipe, t_shell_context *o);
int				exec_env(t_pipe_node *pipe, t_shell_context *o);
int				exec_exit(t_pipe_node *pipe, t_shell_context *o);
void			init_builtin_arrs(char **builtin_str, \
int (**builtin_func)(t_pipe_node *pipe, t_shell_context *o));
void			create_upd_env_st(char **arg, t_shell_context *o, int sign_exp);
void			add_or_update_env_var(t_shell_context *o, t_env_var *new_var);
int				is_valid_key(const char *key);
t_env_var		*find_env_var_by_key(t_env_var *env_list, const char *key);
int				set_env_st(char *key, char *value, t_env_var *env);
int				str_is_num(const char *str);
char			**create_env_arr(t_shell_context *o);
void			free_env_arr(char **env_arr);
void			free_fd_pipes(int **pipe_fds, int i);
int				create_fd_pipes(t_shell_context *o);
void			close_all_pipes_fd(t_shell_context *o);
void			set_pipes_fd(t_shell_context *o, int i, \
t_pipe_node *pipe, int is_main_procs);
void			free_fd_pipes(int **pipe_fds, int i);
void			save_original_pipes(t_shell_context *o);
void			return_to_original_pipes(t_shell_context *o);
void			err_msg_cmd(char *command, char *error_message);
void			err_msg_cmd_2(char *command, char *var, char *error_message);
char			*create_path_to_cmd(char **str, t_shell_context *o);
void			exec_child(char **arg, t_pipe_node *pipe, \
int j, t_shell_context *o);
int				allocate_pipe_fds(t_shell_context *o, int n);
char			*check_and_free_empty_string(char *str);
char			*check_and_free_empty_input(char *input);
int				check_input_validity(char *input, int i, int *err);
int				handle_file_error(int fd, char *file_name);
void			free_existing_heredoc(t_shell_context *o);
int				allocate_key_val(t_env_var *new_var, const char *env, \
char *equals_sign);
int				handle_env_var_allocation_failure(t_env_var *new_var);
char			*get_start_and_dollar_value(char *mid, int *index, \
t_shell_context *o, char **start);
char			*join_parts(t_join_params *params);
int				run_builtin_single(t_pipe_node *pipe, int j, \
t_shell_context *o, int (*builtin_func)(t_pipe_node *, t_shell_context *));

#endif
