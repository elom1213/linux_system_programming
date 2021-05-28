// 342p almhandler.c
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void alarmHandler(int signo);

int main()
{
    int sec = 0;

    signal(SIGALRM, alarmHandler);
    alarm(5);
    printf("무한 루프\n");
    while(1)
    {
	sleep(1);
	printf("%d 초 경과 \n", ++sec);
    }
    printf("실행되지 않음 \n");
}

void alarmHandler(int signo)
{
    printf("일어나세요\n");
    exit(0);
}
