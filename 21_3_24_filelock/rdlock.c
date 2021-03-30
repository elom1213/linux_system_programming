// p179 lock type F_RDLCK, print record of student whose id is argv[1]
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "student.h"

int main(int argc, char* argv[])
{
	int fd, id;
	struct student rec;
	struct flock lock;

	if(argc < 2)
	{
		fprintf(stderr, "Use %s filename", argv[0]);
		exit(1);
	}

	if((fd = open(argv[1], O_RDONLY)) == -1)
	{
		perror(argv[1]);
		exit(2);
	}

	printf("\ntype id => ");
	while(scanf("%d", &id) == 1)
	{
		lock.l_type = F_RDLCK;
		lock.l_whence = SEEK_SET;
		lock.l_start = (id - START_ID)*sizeof(rec);
		lock.l_len = sizeof(rec);
		if(fcntl(fd, F_SETLK, &lock) == -1)
		{
			perror(argv[1]);
			close(fd);
			exit(3);
		}
		
		lseek(fd, (id - START_ID)*sizeof(rec), SEEK_SET);
		if(read(fd, &rec, sizeof(rec)) > 0 && rec.id != 0)
			printf("name : %s\tid : %d\tscore : %d\n", rec.name, rec.id, rec.score);
		else
			printf("unknown record\n");

		lock.l_type = F_UNLCK;
		fcntl(fd, F_SETLK, &lock);
		printf("\ntype id => ");
	}

	close(fd);
	exit(0);
}
