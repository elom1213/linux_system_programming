// p292 syscall.c
//#include "mysystem.c"
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
	int status;
	if((status = system("date")) < 0)
		perror("system() 오류");
	printf("종류코드 %d\n", WEXITSTATUS(status));

	if((status = system("ps -Lf;hello")) < 0)
		perror("system() 오류");
	printf("종류코드 %d\n", WEXITSTATUS(status));

	if((status = system("who;exit 44")) < 0)
		perror("system() 오류");
	printf("종류코드 %d\n", WEXITSTATUS(status));

}
