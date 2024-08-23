/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:43:00 by pollivie          #+#    #+#             */
/*   Updated: 2024/07/04 13:37:07 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARY_H
#define LIBRARY_H

#include "common.h"

/*********/
/* ascii */
/*********/
bool is_command(const int32_t ch);
bool is_argument(const int32_t ch);
bool is_variable(const int32_t ch);
bool is_assignment(const int32_t ch);
bool is_identifier(const int32_t ch);
bool is_identifier_start(const int32_t ch);
bool is_left_redir(const int32_t ch);
bool is_right_redir(const int32_t ch);
bool is_pipe(const int32_t ch);
bool is_special(const int32_t ch);
bool is_quote(const int32_t ch);
bool is_alpha(const int32_t ch);
bool is_alnum(const int32_t ch);
bool is_space(const int32_t ch);
bool is_ctrl(const int32_t ch);
bool is_ascii(const int32_t ch);
bool is_print(const int32_t ch);
bool is_newline(const int32_t ch);
bool is_punct(const int32_t ch);
bool is_digit(const int32_t ch);
bool is_lower(const int32_t ch);
bool is_upper(const int32_t ch);
bool is_hex(const int32_t ch);
bool is_graph(const int32_t ch);

/**********/
/* STRING */
/**********/

uint64_t string_length(const char *const source);
uint64_t string_copy(char *const dest, const char *const source, const uint64_t dsize);
uint64_t string_concat(char *const dest, const char *const source, const uint64_t dsize);
uint64_t string_span(const char *const source, const char *const delimiters);
uint64_t string_count(const char *const source, const char *const delimiters);
uint64_t string_wcount(const char *const source, const char *const delimiters);
uint64_t string_cspan(const char *const source, const char *const delimiters);
int64_t  string_index_of(const char *source, const int32_t ch);
int64_t  string_compare(const char *const source1, const char *const source2);
int64_t string_ncompare(const char *const source1, const char *const source2, const uint64_t n);
char *string_clone(const char *const source);
char *string_nclone(const char *const source, const uint64_t n);
char *string_join(const char *const source1, const char *const source2);
char *string_search(const char *const haystack, const char *const needle, const uint64_t n);
char **string_split(const char *const source, const char *const delimiters);
char **string_tokenize(const char *const source, const char *const delimiters);
char **string_split_create(const uint64_t size);
char **string_split_destroy(char **split);
uint64_t split_size(char **split);
t_list  *split_to_list(char **split);
bool     string_contains(const char *const string, const char ch);
bool     string_is_all(const char *const string, bool(predicate)(int32_t ch));
bool string_starts_with(const char *const string, bool(predicate)(int32_t ch));
bool string_ends_with(const char *const string, bool(predicate)(int32_t ch));

/**********/
/* memory */
/**********/

int64_t memory_compare(const void *const source1, const void *const source2, const uint64_t n);
void *memory_search(const void *const source, const int32_t byte, const uint64_t ssize);
void *memory_ccopy(void *const dest, const int32_t byte, const void *const source, const uint64_t dsize);
void *memory_copy(void *const dest, const void *const source, const uint64_t bytes);
void *memory_move(void *const dest, const void *const src, const uint64_t bytes);
void *memory_fill(void *const dest, const int32_t byte, const uint64_t dsize);
void *memory_zero(void *const dest, const uint64_t dsize);
void *memory_alloc(const uint64_t size);
void *memory_dupe(const void *const source, const uint64_t size);
void *memory_dupz(const void *const source);
void  memory_dealloc(void *const ptr);

t_node  *node_create(const uintptr_t data);
t_node  *node_destroy(t_node *const self);
t_node  *node_get_nchild(t_node *const self, const uint64_t n);
void     node_insert_child(t_node *const self, t_node *const child);
t_node  *node_remove_child(t_node *const self);
uint64_t node_count_child(t_node *const self);
t_list  *list_create(void);
t_list  *list_destroy(t_list *const self);
void     list_insert_front(t_list *const self, t_node *const new_head);
void list_copy(t_list *const dest, t_list *const src, uintptr_t (*ctor)(uintptr_t data));
void list_concat(t_list *const dest, t_list *const src);
void list_insert_at(t_list *const self, t_node *const node, const uint64_t index);
void list_insert_back(t_list *const self, t_node *const new_tail);
void list_push_front(t_list *const self, const uintptr_t data);
void list_push_at(t_list *const self, const uintptr_t data, const uint64_t index);
void list_push_back(t_list *const self, const uintptr_t data);
void list_sort(t_node **list, int64_t (*compare)(uintptr_t d1, uintptr_t d2));
t_node   *list_remove_front(t_list *const self);
t_node   *list_remove_back(t_list *const self);
t_node   *list_remove_at(t_list *const self, const uint64_t index);
uintptr_t list_pop_front(t_list *const self);
uintptr_t list_pop_back(t_list *const self);
uintptr_t list_pop_at(t_list *const self, const uint64_t index);
uintptr_t list_peek_front(t_list *const self);
uintptr_t list_peek_back(t_list *const self);
uintptr_t list_peek_at(t_list *const self, const uint64_t index);
uint64_t  list_size(const t_list *const self);
bool      list_is_empty(const t_list *const self);
void      list_map(t_list *const self, void(fn)(uintptr_t data));
void list_clear_retain_capacity(const t_list *const self, uintptr_t (*dtor)(uintptr_t data));
void list_clear(t_list *const self, uintptr_t (*dtor)(uintptr_t data));
void list_dump(t_list *const dest, t_list *const src);
int64_t list_index_of(const t_list *const self, const uintptr_t data, int64_t (*compare)(uintptr_t d1, uintptr_t d2));
char **list_to_split(t_list *const self);

t_hashmap *hashmap_create(uint64_t capacity);
void       hashmap_destroy(t_hashmap *self);
void       hashmap_put(t_hashmap *self, char *key, uintptr_t value);
uintptr_t  hashmap_get(t_hashmap *self, char *key);
uint64_t   hashmap_hash(char *str);
t_entry   *hashmap_body_create(uint64_t capacity);
void       hashmap_body_remove(t_hashmap *self, char *key);
void       hashmap_body_resize(t_hashmap *self, uint64_t capacity);
uint64_t   hashmap_body_find_empty(t_hashmap *self, char *key);

bool     is_prime(uint64_t num);
uint64_t find_next_prime(uint64_t num);

t_token     *token_endtok(void);
t_token     *token_create(void);
t_token     *token_clone(const t_token *const self);
t_token     *token_destroy(t_token *const self);
t_token     *token_expand(t_token *const key, t_envmap *map);
void         token_set_str(t_token *const self, const char *const string);
void         token_set_kind(t_token *const self, const t_token_kind kind);
char        *token_get_str(t_token *const self);
t_token_kind token_get_kind(t_token *const self);
int64_t      token_compare_uid(uintptr_t tok1, uintptr_t tok2);
int64_t      token_compare_string(uintptr_t tok1, uintptr_t tok2);
int64_t      token_compare_kind(uintptr_t tok1, uintptr_t tok2);
t_token *token_join(const t_token *const tok1, const t_token *const tok2, const char *const sep);
uintptr_t token_dtor(uintptr_t token);
uintptr_t token_ctor(uintptr_t token);
void      token_print(t_token *token);

t_expression *expression_create(void);
t_expression *expression_join(t_expression *const expr1, t_expression *const expr2);
t_expression *expression_destroy(t_expression *const self);
uintptr_t     expression_ctor(uintptr_t expr);
uintptr_t     expression_dtor(uintptr_t self);

bool expression_is_start_token(t_expression_kind expr_kind, t_token_kind tok_kind);
bool expression_is_interior_token(t_expression_kind expr_kind, t_token_kind tok_kind);
bool expression_is_terminal_token(t_expression_kind expr_kind, t_token_kind tok_kind);
void expression_collect(t_expression *const self, t_list *const token_list, t_expression_kind kind);
void expression_print(t_expression *const self, uint64_t i);

t_list_iter *list_iter_create(t_list *const list);
bool         it_end(const t_list_iter *const self);
void        *it_peek_curr(const t_list_iter *const self);
void        *it_peek_prev(const t_list_iter *const self);
void        *it_peek_next(const t_list_iter *const self);
void         it_advance(t_list_iter *const self);
void         it_rollback(t_list_iter *const self);
void         it_save(t_list_iter *const self);
void         it_restore(t_list_iter *const self);
t_list_iter *list_iter_destroy(t_list_iter *const self);

t_cmd_table *cmd_table_create(t_expression *const expr, const uint64_t id);
t_cmd_table *cmd_table_destroy(t_cmd_table *const self);

#endif
