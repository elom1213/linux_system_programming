// p 205 open file argv[1] using fopen. print line using fgets
#include <stdio.h>
#define MAXLINE 80

int main(int argc, char* argv[])
{
	FILE* fp;
	int line = 0;
	char buffer[MAXLINE];
	
	if(argc < 2)
	{
		fprintf(stderr, "Use : %s filename\n", argv[0]);
		return 1;
	}

	if((fp = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "error : fopenf\n");
		return 2;		
	}

	while(fgets(buffer, MAXLINE, fp) != NULL)
	{
		line++;
		printf("%3d %s", line, buffer);
	}

	fclose(fp);
	return 0;
}
