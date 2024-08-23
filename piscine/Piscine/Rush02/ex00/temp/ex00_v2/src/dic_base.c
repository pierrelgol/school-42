#include "../lib/dic_base.h"
#include "../lib/dic_file.h"
#include "../lib/dic_lexer.h"

int	main(int argc, char **argv)
{
	t_file *file;
	t_lexer *lex;

	if (argc == 2)
	{
		file = file_init("./numbers.dict", O_RDWR);
		printf("%d\n",atoi(argv[1]));
		printf("%s\n",file->buf);
		lex = lexer_init(file->buf);
		for (int i = 0; i < lex->token_count; ++i)
		{
			printf("[%d][%s]\n",i,lex->tokenized[i].content);
		}
		lex = lexer_dispose(lex);
		file = file_dispose(file);		
	}
	else
		printf("err\n");
	return (0);
}
