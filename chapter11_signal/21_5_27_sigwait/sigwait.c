// sigwait.c
#include <signal.h>
#include <stdio.h>
#include <errno.h>

void main()
{
    sigset_t set;
    int sig;
    int *sigptr = &sig;
    int ret_val;
    sigemptyset(&set);
    //sigfillset(&set);
    sigaddset(&set, SIGINT);
    //sigdelset(&set, SIGINT);
    sigprocmask(SIG_BLOCK, &set, NULL);

    printf("waiting for a SIGINT signal\n");
    ret_val = sigwait(&set, sigptr);
    if(ret_val == -1)
	perror("sigwait falied\n");
    else
    {
	if(*sigptr == 2)
	    printf("SIGINT was received\n");
	else
	    printf("sigwait returned with sig :%d\n", *sigptr);
    }
}
