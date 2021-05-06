// p280 forkwait.c
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int pid, child, status;

	printf("[%d] 부모 프로세스 시작\n", getpid());
	pid = fork();
	if(pid == 0)
	{
		printf("[%d] 자식 프로세스 시작\n", getpid());
		sleep(3);
		exit(3);
	}


	child = wait(&status);
	printf("[%d] 자식 프로세스 %d  종류\n", getpid(), child);
	printf("\t종류코드 %d\n", status>>8);
}
