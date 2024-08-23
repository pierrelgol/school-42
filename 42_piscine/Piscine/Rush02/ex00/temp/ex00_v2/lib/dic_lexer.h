#ifndef DIC_LEXER_H
#define DIC_LEXER_H

#include "dic_base.h"
#include "dic_help.h"
#include "dic_tokenizer.h"

t_lexer *lexer_init(char *source);
int	lexer_count(char *source);
void *lexer_dispose(t_lexer *self);

#endif
