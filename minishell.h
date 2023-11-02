/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idryab <idryab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:25:51 by osabir            #+#    #+#             */
/*   Updated: 2023/08/09 14:24:04 by idryab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <dirent.h>
# include <sys/types.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <limits.h>
# include "libft/libft.h"
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

# define ERROR_FILE "minishell: No such file or directory"
# define ERROR_COMMAD "minishell: command not found: "

typedef struct s_glob
{
	char	**str;
	char	*file;
	char	*buffer;
	int		flag;
	int		flag_herd;
	int		null;
	int		cunt;
	int		ignore;
	int		fre;
	int		stop;
	int		herd_expand;
	int		exit_status;
}			t_glob;

t_glob		g_var;

typedef enum e_info
{
	PIPE = 1,
	WHITE = 2,
	SIGQ_STR = 3,
	DUBQ_STR = 4,
	ENV_VAR = 5,
	ENV_SPSH = 6,
	WORD = 7,
	REDI_IN = 8,
	REDI_OUT = 9,
	HERDQ = 10,
	DELIMITER = 11,
	APPEN = 12
}			t_info;

typedef struct s_pipz
{
	int					**pipez;
	struct s_pipz		*next;
}				t_pipz;

typedef struct s_exp
{
	char	**key1;
	char	*value1;
	char	*tmp;
	int		plus;
	char	*rem_plus;
}				t_exp;

typedef struct s_link
{
	struct s_link	*next;
	char			*cmd;
	t_info			type;
}				t_link;

typedef struct s_tmp
{
	int		input;
	int		output;
}			t_tmp;

typedef struct s_var
{
	int		i;
	int		j;
	int		curr;
	int		len;
}				t_var;

typedef struct s_cmd
{
	struct s_cmd	*next;
	char			**cmd;
	int				file_input;
	int				file_output;
}				t_cmd;

typedef struct s_env
{
	struct s_env	*next;
	char			*key;
	char			*value;
}				t_env;

//========EXEC=============================//

//========Tools=============================//
void		add_back(t_env **envr, t_env *new);
void		free_func(char **input);
int			count_cmds(t_cmd *data);
int			redirect_stdout_n_save_cpy(t_cmd *data);
char		*get_completed_cmd(char **path, char *cmd);
char		**join_env(t_env *env);
char		*ft_strjoin3(char *s1, char *s2);
char		*tolower_buil(char *str);
int			function2(char *str, t_env **envire);
void		err_n_exit(char	*file);

//========Export Tools=============================//
char		*get_value(const char *s);
void		add_to_bottom(t_env *env, t_env *new);
char		*ft_strdup2(char *s1);
char		*rm_plus(char *key);
int			equal_after_plus(char *key);
int			check_identifier(char *key);
void		if_not_arg(t_env *env);

//========Cd Tools=============================//
void		change_a_var_in_env(t_env **env, char *key, char *value);
char		*get_path(t_env *env, char *var);

//========EXECUTION MAIN FUNCTIONS=============================//
void		final_func(t_cmd **_data, t_env **envire);
int			run_builtins(t_cmd *data, t_env **envire);
void		run_process(t_cmd *data, int num_cmd, t_env **env);
void		run_execv(char **cmds_splitted, t_env *env);
void		free_pipes(void **s, int numpipe);
void		close_fds(int **fds, int num_cmd);
char		*get_path(t_env *env, char *var);

//========Built-ins==============================================//
void		ft_cd(char *path, t_env *env);
void		ft_echo(char **cmd);
void		ft_pwd(t_env **env);
void		ft_env(t_env *env);
void		ft_export(t_env *env, char *key_value);
void		ft_unset(t_env *data, char *unseter);
int			ft_exitt(t_cmd *data);

//========From_libft=============================//
size_t		ft_strcspn(const char *s, const char *reject);
int			ft_strcmp(const char *s1, const char *s2);
size_t		ft_strlen(const char *s);
char		*ft_strjoin2(char *s1, char *s2);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);

/*          --------> parsing <--------          */

void		ft_syntax_error(char *s, int *flag);
void		ft_syntax_error1(char *s, int *flag, int *i);
void		fun2sky(char *s, int *i, int c);
void		skyp(char *s, int *i, int *flag);
void		globle_error(int *flag);
void		ft_redi_output(char *s, int *flag, int *i);
void		ft_redi_input(char *s, int *flag, int *i);
void		ft_append(char *s, int *flag, int *i);
void		ft_herdo(char *s, int *flag, int *i);
void		ft_duble_quotes(char *s, int *flag, int *i);
void		ft_singel_quotes(char *s, int *flag, int *i);
void		ft_doller_varble(char *s, int *flag, int *i);
void		check_pipe2(char *s, int *word, int *pipe, int *i);
void		check_pipe(char *s, int *flag);

/*          -------->  link  <--------          */

void		ft_tokenizer(t_link **cmd, t_env **env, char *s);
void		ft_tokenizer1(t_link **cmd, t_env **env, char *s, int *i);
void		give_info(t_link **_cmd, char *s, t_info type);
void		ft_tokenizer_cmd(t_link **cmd, char *s, t_info type);
void		ft_token_word(t_link **cmd, t_env **_env, char *s, int *i);
char		*ft_token_word1(t_env **_env, char *s, int *i);
void		ft_token_herdo(t_link **cmd, char *s, int *i);
void		ft_delimiter(t_link **cmd, char *s, int *i);
char		*ft_delimiter1(char *s, int *i);
char		*ft_deli_duble_singl(char *s, int *i, int c);
void		ft_token_append(t_link **cmd, int *i);
void		ft_token_redi_output(t_link **cmd, int *i);
void		ft_token_redi_input(t_link **cmd, int *i);
void		ft_token_singel_quotes(t_link **cmd, t_env **_env, char *s, int *i);
char		*ft_token_singel_quotes1(t_env **_env, char *s, char *s1, int *i);
void		ft_token_duble_quotes(t_link **cmd, t_env **_env, char *s, int *i);
void		ft_token_doller(t_link **cmd, t_env **_env, char *s, int *i);
void		ft_token_doller1(t_link **cmd, t_env **_env, char *s, int *i);
char		*ft_dubleq1(t_env **_env, char *s, int *flag, int *i);
char		*ft_dubleq2(char *s, int *flag, int *i);
void		ft_dubleq3(char **s1, char *s, int *flag, int *i);
void		ft_dubleq4(char **s1, char *s, int *flag, int *i);
void		ft_dubl_q_only(int *i, int *flag);
int			mt_line(char *s, int *i);
void		ft_token_pipe(t_link **cmd, int *i);
char		*ft_sing(char *s, int *i);
char		*ft_expandvar(t_env **_env, char *s, int *i);
char		*special_char(t_env **_env, char *s, int *i);
void		special_char1(char **s1, char *s, int *i);
void		special_char2(t_env **_env, char **s1, char *s, int *i);
void		special_char3(t_env **_env, char **s1, char *s, int *i);
char		*ft_duble(t_env **_env, char *s, int *i);
void		check(char c1, char c2);

/*          -------->  env  <--------           */

void		ft_link_env(t_env **_env, char *_key, char *_value);
void		ft_take_to_env(t_env **env, char *s);
void		ft_take_env(t_env **env, char **_env);
void		chlvl(t_env **_env);
void		chlvl1(t_env **_env);

/*          -------->  env -i <--------           */

void		ft_env_null(t_env **env);
void		ft_link_env1(t_env **_env, char *_key, char *_value);

/*			-----------  FINAL LIST  -----------			*/

void		final_list(t_cmd **_cmd, t_link **_link, t_env **env);
t_link		*final_list2(t_link *link, t_tmp *tmp, int j, t_env **env);
int			ft_tmp(t_link *link, t_tmp *tmp);
int			ft_size(t_link *link);
void		ft_void(char **s, int i);
char		**ft_str_two_ptr(char **s);
t_link		*ft_about_type(t_link *link, t_tmp *tmp, t_env **env);
void		file(t_tmp *tmp, char *operator, char *file);
void		ft_cmd_final(t_cmd **_cmd, t_tmp *tmp);
void		herd(t_tmp *tmp, char *delimiter, t_env **env);
void		herd1(char *input, t_env **env);
long		file_herd(void);
void		ft_free(char **s);
void		tofree(void);
void		herd_expand(char *input, t_env **env);
void		herd_not_expand(char *input);
char		*ft_strjoin_herd(char *s1, char *s2);

/*			-----------  SIGNAL  -----------			*/
void		handler(int sig_nal);
void		sig_handler(int sig_num);
/*			-----------  FREE  -----------			*/

void		free_env(t_env *_free);
void		free_cmd(t_cmd **_free);
void		free_link(t_link **_free);
char		*ft_exit_status(char *s, int *i);
void		ign(int ac, char **av);
void		malloc_exit(void);
void		dup_exit(void);

#endif
