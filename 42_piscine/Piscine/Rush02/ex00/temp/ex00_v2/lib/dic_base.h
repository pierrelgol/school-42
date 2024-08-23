#ifndef DIC_BASE_H
#define DIC_BASE_H

# include <fcntl.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>


#define BUFFER_SIZE 4096

typedef	struct	s_file
{
	short	fd;
	bool	open;
	long	size;
	char	*buf;

}				t_file;

typedef	enum	e_type
{
	DEFF = 0,
	WORD = 1,
	NUMB = 2,
}				t_type;

typedef	struct	s_token
{
	t_type	type;
	bool	valid;
	int		line;
	int		len;
	char	*content;
}				t_token;

typedef	struct	s_lexer
{
	int		token_count;
	int		line_count;
	char	*raw;
	t_token	*tokenized;
}				t_lexer;


#endif
