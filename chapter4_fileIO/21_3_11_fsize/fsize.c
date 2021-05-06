#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFSIZE	512

int main(int argc, char* argv[])
{
	int fd, cnt=0;
	char buf[BUFZISE];
	ssize_t total = 0;

	if((fd = open(argv[1], O_RDONLY)) == -1)
		perror(argv[1]);

	printf("%d\n", fd);

	while((nread = read(fd, buf, BUFSEZE)) > 0)
	{
		cnt ++;
		total += nread;
	}
	
	printf("fiie => %s , %ld bytes", argv[1], total);
	close(fd);
	exit(0);
}
