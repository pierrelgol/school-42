#ifndef DIC_TOKENIZER_H
#define DIC_TOKENIZER_H

#include "dic_base.h"

int		tokenizer_tokenize(t_lexer *source);
void	tokenizer_tok(t_token *tok, char *src, int line);
t_type	tokenizer_identify(char *source);
int		tokenizer_toklen(char *source);



#endif
