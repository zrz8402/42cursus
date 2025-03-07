#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

int	main(void)
{
	char	*line;

	line = readline("> ");
	printf("%s\n", line);
	free(line);
}

// cc readline.c -lreadline -o test