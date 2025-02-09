#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	char *env = getenv("PATH");
	if (env && *env)
		printf("%s\n", env);
	else
		printf("no path");
}

// PATH=/home/ruzhang/bin:/home/ruzhang/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin

// /home/ruzhang/bin:/home/ruzhang/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin

// getenv(VAR) = echo $VAR
