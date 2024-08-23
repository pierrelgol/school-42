#ifndef NUM_BASE_H
# define NUM_BASE_H

# include <fcntl.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

#define BUFFER_SIZE 16384

/*
	@e_flag :

	The goal of the type t_flag, is to have an expresive and consistent way
	to describe and treat errors :

	@DEFAULTV : Use to instantiate object with a default non conflicting value
	@ERR_ARGS : Use to signal error(s) relative to (argc/argv)
	@ERR_DICT : Use to signal error(s) relative to the dictionnary
	@ERR_NEGA : Use to signal error(s) relative to the number being negative
	@ERR_FIND : Use to signal error(s) relative to the solution resolution
	@ERR_FNAM : Use to signal error(s) relative to path of the file
	@ERR_PERM : Use to signal error(s) relative to the permission system

*/

typedef enum e_flag
{
	DEFAULTV = 0,
	ERR_ARGS = 1,
	ERR_DICT = 2,
	ERR_NEGA = 3,
	ERR_NUMB = 4,
	ERR_FIND = 5,
	ERR_FNAM = 6,
	ERR_PERM = 7,

}			t_flag;

/*
	@s_file

	The struct s_file and the type t_file will be the struct responsible for
	opening a file, loading it's content inside a buffer and handling the
	lifetime of the object while processing it's content :

	@fd 		: short  : fd is an integer representing the file descriptor.
	@is_open 	: bool   : is_open is a boolean representing the state of the file
	@status  	: enum   : suppose to be a signal in case of an error.
	@byte_read  : long   : store the result of the read() function.
	@buffer		: char * : array of char to store the content read from the file.

*/

typedef struct s_file
{
	short	fd;
	bool	is_open;
	t_flag	status;
	long	byte_read;
	char	*buffer;
}			t_file;

/*
	@s_slice

	The struct s_slice will be used to begin the first stage of parsing of our
	input, the idea is to slice a given number into smaller segment in order
	to create a meaningful intermediate representation.

	for example for the number : 123456789
	to simplify the processing of that number we could have three slices
	each holding a segment of our initial input such as :

	s1 --> dec_len = 3								s2 --> dec_len = 3                      	s3 --> dec_len = 3
	s1 --> dec_slice = [7][8][9]					s2 --> dec_slice = [4][5][6]            	s3 --> dec_slice = [1][2][3]
	s1 --> chr_len = 3								s2 --> chr_len = 3                      	s3 --> chr_len = 3
	s1 --> chr_slice = ['7']['8']['9']['\0']		s2 --> chr_slice = ['4']['5']['6']['\0']	s3 --> chr_slice = ['1']['2']['3']['\0']

	@status    : enum  : suppose to be a signal in case of an error.
	@chr_len   : short : length of our chr_slice (doesn't include the null terminated character)
	@chr_slice : char* : pointer to our slice of char
	@dec_len   : short : length of our dec_slice
	@dec_slice : short*: pointer to our slice of short

*/

typedef struct s_slice
{
	t_flag	status;
	short	chr_len;
	char	*chr_slice;
	short	dec_len;
	short	*dec_slice;
}			t_slice;

/*
	@s_stack

	the stack is a data structure,
	that works with the FILO principe (First In Last Out) I think it is a very
	simple to implement and understand data structure,
	that might be usefull when dealing with the conversion
	of decimal value to char and vice-versa

	@capacity : int   : represent the maximum size of our stack object
	@count	  : int   : represent the current count of elements within our object
	@status   : enum  : suppose to be a signal in case of an error.
	@elems	  : void* : will be our pointer holding our elements.

*/

typedef struct s_stack
{
	int		capacity;
	int		count;
	t_flag	status;
	char	*elems;
}			t_stack;

typedef	enum	s_type
{
	DEFAULT = 0,
	NUMBER = 1,
	TEXT = 2,
	SEP = 3,
}				t_type;

typedef	struct	s_token
{
	t_type	symbol_type;
	int		line;
	int		length;
	char	*identifier;
}				t_token;

typedef struct	s_entry
{
	t_token	*lexer_raw;
	int		col;
	int		row;
}				t_entry;

typedef	struct	s_ast
{
	int		dict_rows;
	int		disct_cols;
	t_entry **ast;
}				t_ast;

#endif
