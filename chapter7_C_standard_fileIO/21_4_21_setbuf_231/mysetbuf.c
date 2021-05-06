// p231 setbuf.c
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	char buf[5];
	printf("Hello ");sleep(2);
	printf("Whatup everyboy");sleep(2);
	printf("\n");sleep(2);

	setbuf(stdout, NULL);
	printf("I just set buf to NUll ");sleep(2);
	printf("Let's see how printf works. ");sleep(2);
	printf("Did set buf works well?");sleep(2);
	printf("\n");sleep(2);

	setvbuf(stdout, buf, _IOFBF, 5 );
	printf("set buf to setvbuf. ");sleep(2);
	printf("I'm gonna print long string like this one you know. ");sleep(2);
	printf("\n ");sleep(2);
}
