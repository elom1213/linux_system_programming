// p181 set the option of F_WRLCK and lock the file argv[1]. write score into argv[1]
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"

int main(int argc, char* argv[])
{
	int id, fd;
	struct student rec;
	struct flock lock;

	if(argc < 2)
	{
		fprintf(stderr, "Use : %s filename", argv[0]);
		exit(1);
	}

	if((fd = open(argv[1], O_RDWR)) < 0)
	{
		perror(argv[1]);
		exit(2);
	}
	
	printf("type id for modification => ");
	while(scanf("%d", &id) == 1)
	{
		lock.l_type = F_WRLCK;
		lock.l_whence = SEEK_SET;
		lock.l_start = (id - START_ID)*sizeof(rec);
		lock.l_len = sizeof(rec);
		if(fcntl(fd, F_SETLKW, &lock) == -1)
		{
			perror(argv[1]);
			close(fd);
			exit(3);
		}

		lseek(fd, (id - START_ID)*sizeof(rec), SEEK_SET);
		if(read(fd, &rec, sizeof(rec)) > 0 && rec.id != 0)
			printf("name : %s\tid : %d\t score : %d\n", rec.name, rec.id, rec.score);
		else
			printf("unknown id\n");

		printf("set score => ");
		scanf("%d", &rec.score);
		lseek(fd, (long)-sizeof(rec), SEEK_CUR);
		write(fd, &rec, sizeof(rec));		

		lock.l_type = F_UNLCK;
		fcntl(fd, F_SETLK, &lock);
		printf("\ntype id for modification => ");
	}

	close(fd);
	exit(0);
}
