/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:48:58 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 13:35:06 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#ifndef DEBUG
#define DEBUG 0
#endif

#include "common.h"
#include "library.h"

/******************************************************************************/
/* ENVMAP                                                                     */
/******************************************************************************/
t_envmap *envmap_create(char **envp);

void  envmap_print_one(t_envmap *const self, char *key);
char *envmap_get(t_envmap *const self, char *key);
bool  envmap_set(t_envmap *const self, char *key, char *value);

t_envmap *envmap_destroy(t_envmap *const self);

/******************************************************************************/
/* SHELL                                                                      */
/******************************************************************************/
t_shell *shell_create(int32_t argc, char **argv, char **envp);

bool shell_expression_to_cmd_table(t_list *table_list, t_list *expr_list);
bool shell_readline(t_shell *self, char *prompt);
bool shell_clear(t_shell *self);
bool shell_process(t_shell *self);

t_shell *shell_destroy(t_shell *self);

/******************************************************************************/
/* TOKENIZER                                                                  */
/******************************************************************************/
t_tokenizer *tokenizer_create(t_list *token_pool);

bool tokenizer_tokenize(t_tokenizer *const self, char *input);
bool tokenizer_clear(t_tokenizer *const self);

t_tokenizer *tokenizer_destroy(t_tokenizer *self);

/******************************************************************************/
/* LEXER                                                                      */
/******************************************************************************/
t_lexer *lexer_create(t_list *token_pool, t_envmap *const map);

bool lexer_clear(t_lexer *const self);
bool lexer_lex(t_lexer *const self);
void lexer_identify_all_identifiers(t_list_iter *const it);
void lexer_identify_all_eql(t_list_iter *const it);
void lexer_identify_all_spaces(t_list_iter *const it);
void lexer_identify_all_slashes(t_list_iter *const it);
void lexer_identify_all_builtins(t_list_iter *const it);
void lexer_identify_all_quotes(t_list_iter *const it);
void lexer_identify_all_redirs(t_list_iter *const it);
void lexer_identify_all_pipes(t_list_iter *const it);
void lexer_identify_all_dollar(t_list_iter *const it);
bool lexer_relex(t_lexer *const self);
void lexer_identify_all_appends(t_list_iter *const it);
void lexer_identify_all_here_docs(t_list_iter *const it);
void lexer_identify_all_arguments(t_list_iter *const it);

t_lexer *lexer_destroy(t_lexer *self);

/******************************************************************************/
/* LINKER                                                                     */
/******************************************************************************/
t_linker *linker_create(t_list *token_pool, t_envmap *envmap);

bool linker_clear(t_linker *const self);
bool linker_link(t_linker *const self);
void linker_link_all_left_redirs(t_list *const token_pool, t_list *const token_pool_linked);
void linker_link_all_right_redirs(t_list *const token_pool, t_list *const token_pool_linked);
void linker_link_all_single_quotes(t_list *const token_pool, t_list *const token_pool_linked);
void linker_link_all_double_quotes(t_list *const token_pool, t_list *const token_pool_linked);
void linker_link_all_slash_id(t_list *const token_pool, t_list *const token_pool_linked);
void linker_link_all_path(t_list *const token_pool, t_list *const token_pool_linked);
void linker_remove_all_spaces(t_list *const token_pool, t_list *const token_pool_linked);
void linker_link_all_variables(t_list *const token_pool, t_list *const token_pool_linked);
void linker_expand_all_variables(t_linker *const self, t_list *const token_pool, t_list *const token_pool_linked);
void linker_link_all_remaining_slash(t_list *const token_pool, t_list *const token_pool_linked);

t_linker *linker_destroy(t_linker *self);

/******************************************************************************/
/* PARSER                                                                     */
/******************************************************************************/
t_parser *parser_create(t_list *token_pool);

bool parser_clear(t_parser *const self);
bool parser_parse(t_parser *const self);

t_parser *parser_destroy(t_parser *self);

/******************************************************************************/
/* RESOLVER                                                                   */
/******************************************************************************/

t_resolver *resolver_create(t_list *token_pool, t_envmap *envmap);

bool resolve_exe(t_resolver *self, t_token *maybe_exe);
bool resolve_path(t_resolver *self, t_token *maybe_path);
bool resolve_file(t_resolver *self, t_token *maybe_file);

t_resolver *resolver_destroy(t_resolver *self);

/******************************************************************************/
/* BUILTIN                                                                    */
/******************************************************************************/
t_builtins *builtins_create(t_envmap *env);

t_builtins *builtins_destroy(t_builtins *self);

/******************************************************************************/
/* BUILTIN UNSET                                                              */
/******************************************************************************/
t_builtins_unset *unset_create(t_envmap *env);

bool unset_unset(t_builtins_unset *self, char *k);

t_builtins_unset *unset_destroy(t_builtins_unset *self);

/******************************************************************************/
/* BUILTIN PWD                                                                */
/******************************************************************************/
t_builtins_pwd *pwd_create(t_envmap *env);

bool pwd_print(t_builtins_pwd *self);

t_builtins_pwd *pwd_destroy(t_builtins_pwd *self);

/******************************************************************************/
/* BUILTIN EXPORT                                                             */
/******************************************************************************/
t_builtins_export *export_create(t_envmap *env);

bool export_export(t_builtins_export *self, char *k, char *v);

t_builtins_export *export_destroy(t_builtins_export *self);

/******************************************************************************/
/* BUILTIN ENV                                                                */
/******************************************************************************/
t_builtins_env *env_create(t_envmap *env);

bool env_put(t_builtins_env *self, char *variable, char *value);
bool env_print_one(t_builtins_env *self, char *variable);
bool env_print_all(t_builtins_env *self);

t_builtins_env *env_destroy(t_builtins_env *self);

/******************************************************************************/
/* BUILTIN ECHO                                                               */
/******************************************************************************/
t_builtins_echo *echo_create(t_envmap *env);

bool echo_print(t_builtins_echo *self, char *message, bool flag);

t_builtins_echo *echo_destroy(t_builtins_echo *self);

/******************************************************************************/
/* BUILTIN CD                                                                 */
/******************************************************************************/
t_builtins_cd *cd_create(t_envmap *env);

bool cd_change_directory(t_builtins_cd *self, char *target);

t_builtins_cd *cd_destroy(t_builtins_cd *self);

/******************************************************************************/
/* BUILTIN ENV                                                                */
/******************************************************************************/
t_builtins_env *env_create(t_envmap *env);

bool env_put(t_builtins_env *self, char *variable, char *value);
bool env_print_one(t_builtins_env *self, char *variable);
bool env_print_all(t_builtins_env *self);

t_builtins_env *env_destroy(t_builtins_env *self);

/******************************************************************************/
/* DEBUG                                                                      */
/******************************************************************************/
void dbg_tokenizer(t_tokenizer *const self);
void dbg_lexer(t_lexer *const self);
void dbg_parser(t_parser *const self);
void dbg_linker(t_linker *const self);

/******************************************************************************/
/* SIGNALS                                                                    */
/******************************************************************************/
void signal_init(void);
void signals_ctrl_handler(void);
void signals_sigint_handler(int signal);
void signals_sigquit_handler(int signal);
void signals_handle_eof(char *input);
void signals_setup_handlers(void);
void signal_init(void);

/******************************************************************************/
/* EXEC                                                                       */
/******************************************************************************/

void exec_init(t_exec *const self ,t_list *const expression_list, char **envp);

bool      exec_clear(t_exec *const self);

bool exec_is_first_cmd(t_exec *const self);
bool exec_is_middle_cmd(t_exec *const self);
bool exec_is_last_cmd(t_exec *const self);
bool exec_is_builtin_cmd(t_exec *const self);
bool exec_is_the_only_cmd(t_exec *const self);

bool exec_cmd_has_input_redirect(t_exec *const self);
bool exec_cmd_has_output_redirect(t_exec *const self);
bool exec_cmd_has_append_redirect(t_exec *const self);

void exec_parent_process(t_list *const ctl, char **envp);
void exec_child_process(t_exec *const self);
void exec_launch_child_process(t_exec *const self);

int32_t **pipe_array_create(const uint64_t pipe_count);
int32_t **pipe_array_destroy(int32_t **pipe_array, const uint64_t pipe_count);
void      exec_close_pipe(t_exec *const self);
void      exec_open_pipe(t_exec *const self);

void exec_execute(t_exec *const self);
void exec_execute_first_cmd(t_exec *const self);
void exec_execute_middle_cmd(t_exec *const self);
void exec_execute_last_cmd(t_exec *const self);

void exec_deinit(t_exec *const self);

#endif
