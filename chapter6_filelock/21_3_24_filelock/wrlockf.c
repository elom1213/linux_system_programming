// p185 wrlockf.c
// lock file using lockf
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"

int main(int argc, char* argv[])
{
	int id, fd;
	struct student rec;

	if(argc < 2)
	{
		fprintf(stderr, "Use : %s filename\n", argv[0]);
		exit(1);
	}

	if((fd = open(argv[1], O_RDWR)) == -1)
	{
		perror(argv[1]);
		exit(2);
	}

	printf("\ntype id for modification => ");
	while(scanf("%d", &id) == 1)
	{
		lseek(fd, (long)(id - START_ID)*sizeof(rec), SEEK_SET);
		if(lockf(fd, F_LOCK, sizeof(rec)) == -1)
		{
			perror(argv[1]);
			close(fd);
			exit(3);
		}
		
		if(read(fd, &rec, sizeof(rec)) > 0 && rec.id != 0)
			printf("\nname : %s\tid : %d\tscore : %d", rec.name, rec.id, rec.score);
		else
			printf("\nunknown record : %d", id);

		printf("\nset score => ");
		scanf("%d", &rec.score);
		lseek(fd, (long)-sizeof(rec), SEEK_CUR);
		write(fd, &rec, sizeof(rec));
	
		lseek(fd, (long)(id - START_ID)*sizeof(rec), SEEK_SET);
		lockf(fd, F_ULOCK, sizeof(rec));
		printf("\ntype id for modification => ");	
	}

	close(fd);
	exit(0);	
}
