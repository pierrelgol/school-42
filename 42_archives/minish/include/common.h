/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:15:08 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 11:15:09 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
#define COMMON_H

#include <errno.h>
#include <fcntl.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef INIT_VALUE
#define INIT_VALUE -1
#endif

typedef struct s_node            t_node;
typedef struct s_list            t_list;
typedef struct s_entry           t_entry;
typedef struct s_hashmap         t_hashmap;
typedef struct s_token           t_token;
typedef struct s_list_iter       t_list_iter;
typedef struct s_builtins        t_builtins;
typedef struct s_builtins_env    t_builtins_env;
typedef struct s_builtins_export t_builtins_export;
typedef struct s_builtins_unset  t_builtins_unset;
typedef struct s_builtins_cd     t_builtins_cd;
typedef struct s_builtins_pwd    t_builtins_pwd;
typedef struct s_builtins_echo   t_builtins_echo;
typedef struct s_exec            t_exec;

typedef struct s_expression t_expression;
typedef struct s_shell      t_shell;
typedef struct s_envmap     t_envmap;
typedef struct s_backend    t_backend;

typedef struct s_tokenizer t_tokenizer;
typedef struct s_lexer     t_lexer;
typedef struct s_parser    t_parser;
typedef struct s_linker    t_linker;
typedef struct s_resolver  t_resolver;
typedef struct s_cmd_table t_cmd_table;

typedef enum e_output_kind
{
	APPEND,
	TRUNC,
	INPUT,

} t_output_kind;

struct s_exec
{
	char       **envp;
	t_list      *ctl;
	t_cmd_table *table;
	uint64_t     pipe_count;
	int32_t    **pipe_array;
	int32_t      pid;
	bool         is_dirty;
};

struct s_tokenizer
{
	t_list *token_pool;
	char  **tokens;
	bool    is_dirty;
};

struct s_lexer
{
	t_envmap    *map;
	t_list      *token_pool;
	t_list_iter *it;
	bool         is_dirty;
};

struct s_parser
{
	t_list *token_pool;
	t_list *expr_list;
	bool    is_dirty;
};

struct s_resolver
{
	t_envmap    *map;
	t_list      *token_pool;
	char        *input;
	char       **paths;
	t_list_iter *it;
	t_list      *path;
};

struct s_linker
{
	t_envmap *envmap;
	t_list   *token_pool;
	t_list   *token_pool_linked;
	bool      is_dirty;
};

typedef enum e_token_kind
{
	KIND_NO_KIND,
	KIND_SPC,
	KIND_APPEND,
	KIND_ARG,
	KIND_BLTN,
	KIND_CMD,
	KIND_DQUOTE,
	KIND_EQL,
	KIND_FILE,
	KIND_SLASH,
	KIND_HERE_DOC,
	KIND_HERE_DOC_DELIM,
	KIND_ID,
	KIND_LRDIR,
	KIND_PATH,
	KIND_PIPE,
	KIND_QUOTE,
	KIND_RRDIR,
	KIND_UNKOWN,
	KIND_VAR,
	KIND_END_TOKEN,
	KIND_ERROR,

} t_token_kind;

typedef enum e_expression_kind
{
	EXPR_UNKOWN,
	EXPR_APPEND,
	EXPR_ASSIGNMENT,
	EXPR_BUILTIN,
	EXPR_COMMAND,
	EXPR_DOUBLE_QUOTES,
	EXPR_HERE_DOC,
	EXPR_LEFT_REDIR,
	EXPR_PIPE,
	EXPR_QUOTES,
	EXPR_RIGHT_REDIR,

} t_expression_kind;

typedef struct s_expr_assignment
{
	char *variable;
	char *value;
} t_expr_assignment;

typedef struct s_expr_command
{
	char             *cmd_absolute_path;
	char             *cmd_basename;
	char            **cmd_argv;
	int32_t           cmd_argc;
	t_expression_kind next;
	t_expression_kind prev;
} t_expr_command;

typedef struct s_expr_builtin
{
	char   *bltn_name;
	char  **bltn_argv;
	char   *bltn_output;
	int32_t bltn_argc;
} t_expr_builtin;

typedef struct s_expr_quotes
{
	char *quoted_content;
	bool  is_double_quote;
} t_expr_quotes;

typedef struct s_expr_redirection
{
	char *redir_file;
	int   redir_fd;
} t_expr_redirection;

typedef struct s_expr_pipe
{
	struct s_expression *left_expr;
	struct s_expression *right_expr;
} t_expr_pipe;

typedef struct s_expr_here_doc
{
	char *delimiter;
	char *content;
} t_expr_here_doc;

struct s_expr
{
	t_expression_kind expr_kind;
	t_list           *expr_toklist;
	uint64_t          id;
	bool              is_complete;
	union
	{
		t_expr_assignment  assignment;
		t_expr_command     command;
		t_expr_builtin     builtin;
		t_expr_quotes      quotes;
		t_expr_redirection left_redir;
		t_expr_redirection right_redir;
		t_expr_redirection append;
		t_expr_here_doc    here_doc;
		t_expr_pipe        pipe;
	} expr;
};

struct s_expr_pool
{
	t_list  *expr_list;
	uint64_t size;
};

struct s_envmap
{
	t_hashmap *map;
	char     **envp;
	t_list    *keys;
	t_list    *values;
};

struct s_shell
{
	t_envmap    *envmap;
	t_list      *token_pool;
	t_tokenizer *tokenizer;
	t_resolver  *resolver;
	t_parser    *parser;
	t_lexer     *lexer;
	t_linker    *linker;
	t_list      *table_list;
	int32_t      argc;
	int32_t      index;
	char       **argv;
	char       **envp;
	char        *line;
	bool         is_dirty;
};

struct s_token
{
	t_token_kind kind;
	char        *string;
	int64_t      len;
	uint64_t     uid;
};

struct s_expression
{
	t_expression_kind kind;
	t_list           *tokens;
	uint64_t          size;
	bool              is_complete;
};

struct s_token_pool
{
	t_list  *pool;
	uint64_t size;
	bool     is_dirty;
};

struct s_expression_pool
{
	t_list  *pool;
	uint64_t size;
	bool     is_dirty;
};

struct s_list_iter
{
	int64_t end_idx;
	int64_t curr_idx;
	t_node *curr_node;
	int64_t saved_idx;
	t_node *saved_node;
};

struct s_node
{
	struct s_node *next;
	struct s_node *prev;
	uintptr_t      data;
};

struct s_list
{
	t_node  *head;
	t_node  *tail;
	uint64_t size;
};

struct s_entry
{
	char     *key;
	uintptr_t value;
};

struct s_hashmap
{
	uint64_t size;
	uint64_t capacity;
	t_entry *body;
};

struct s_builtins
{
	t_envmap          *env;
	t_builtins_cd     *blt_cd;
	t_builtins_env    *blt_env;
	t_builtins_echo   *blt_echo;
	t_builtins_export *blt_export;
	t_builtins_unset  *blt_unset;
	t_builtins_pwd    *blt_pwd;
};

struct s_builtins_cd
{
	t_envmap *env;
	char     *pwd;
	char     *cwd;
	char     *opwd;
};

struct s_builtins_echo
{
	t_envmap *env;
	int32_t   fd;
};

struct s_builtins_env
{
	t_envmap    *env;
	t_list      *list;
	t_list_iter *it;
};

struct s_builtins_export
{
	t_envmap *env;
};

struct s_builtins_unset
{
	t_envmap *env;
};

struct s_builtins_pwd
{
	t_envmap *env;
	char     *pwd;
};

struct s_cmd_table
{
	t_expression_kind kind;
	t_output_kind     output_type;
	uint64_t          id;
	int32_t           fd_array[3];
	char             *cmd_absolute_path;
	char             *cmd_basename;
	char            **cmd_argv;
	int32_t           cmd_argc;
};

#endif
