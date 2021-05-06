#include <stdio.h>
#include <stdlib.h>

// p202 fopen from argv[1] and putc to stdout

int main(int argc, char* argv[])
{
	FILE* fp;
	int data;

	if(argc < 2) fp = stdin;
	else fp = fopen(argv[1], "r");

	while((data = getc(fp)) != EOF)
		putc(data, stdout);

	fclose(fp);
	exit(0);
}
