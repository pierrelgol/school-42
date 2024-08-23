#include "../lib/dic_lexer.h"

t_lexer	*lexer_init(char *source)
{
	t_lexer *self;

	if (!source)
		return (NULL);
	self = (t_lexer*) malloc(sizeof(t_lexer) * 1);
	if (!self)
		return (NULL);
	self->raw = source;
	self->token_count = lexer_count(source);
	self->line_count = 0;
	self->tokenized = malloc(sizeof(t_token) * self->token_count + 1);
	if (!self->tokenized)
		return (lexer_dispose(self));
	tokenizer_tokenize(self);
	return (self);
}

int	lexer_count(char *source)
{
	int count;
	int	index;

	index = 0;
	count = 0;
	while (source[index])
	{
		while(source[index] && help_isnum(source[index]))	
			++index;
		while(source[index] && help_isspace(source[index]))
			++index;
		if (source[index] != '\0' && help_issep(source[index++]))
			++count;
		while(source[index] && help_isspace(source[index]))
			++index;
		while(source[index] && help_isalnum(source[index]))
			++index;
		if (source[index] != '\0' && help_issep(source[index++]))
			++count;
	}
	return (count);
}

void	*lexer_dispose(t_lexer *self)
{
	int i;

	if (!self)
		return (NULL);
	if (self->tokenized)
	{
		i = 0;
		while (i < self->token_count)
		{
			if (self->tokenized[i].content)
				free(self->tokenized[i].content);
			++i;
		}
		free(self->tokenized);
	}
	free(self);
	return (NULL);
}