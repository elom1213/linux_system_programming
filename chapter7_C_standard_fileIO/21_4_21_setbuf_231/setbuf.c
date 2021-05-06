// p231 setbuf.c
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	printf("안녕하세요, ");sleep(2);
	printf("리눅스입니다!");sleep(2);
	printf("\n");sleep(2);

	setbuf(stdout, NULL);
	printf("여러분, ");sleep(2);
	printf("반갑습니다.");sleep(2);
	printf("^^");sleep(2);
	printf("\n");sleep(2);
}
