#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
	char buf[BUFSIZ];
	int numread;

	numread = readlink(argv[1], buf, BUFSIZ);
	if(numread > 0)
	{
		write(STDOUT_FILENO, buf, numread);
		putchar('\n');
		exit(0);
	} else
	{ 
		fprintf(stderr, "error : cannot find link\n");
		exit(1);
	}
}
