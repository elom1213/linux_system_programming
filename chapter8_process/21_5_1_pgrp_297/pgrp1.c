// pgrp1.c
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int pid, gid, status;

	printf("[PARENT] PID = %d GID = %d\n", getpid(), getpgrp());
	pid = fork();
	if(pid == 0)
	{
		printf("[CHILD] PID = %d GID = %d\n", getpid(), getpgrp());
		execlp("ps","ps", "-Lf", (void*)0);
	}
	wait(&status);
}
