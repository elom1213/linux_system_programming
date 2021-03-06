// 376p pexec2.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXLINE 100

int main(int argc, char *argv[])
{
	char line[MAXLINE];
	FILE *fpin;

	if((fpin = popen(argv[1], "r")) == NULL)
	{
		perror("popen fail");
		exit(1);
	}

	printf("자식 프로세스로부터 받은 결과\n");
	while(fgets(line, MAXLINE, fpin))
		fputs(line, stdout);

	pclose(fpin);
	exit(0);
}
