#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"

int main(int argc, char* argv[])
{
	int fd, id;
	char input;
	struct student rec;

	if(argc < 2)
	{
		fprintf(stderr, "type file name => %s filename\n", argv[0]);
		exit(1);
	}

	if((fd = open(argv[1], O_RDONLY)) == -1)
	{
		perror(argv[1]);
		exit(1);
	}

	do
	{
		printf("\ntype id => ");
		if(scanf("%d", &id) == 1)
		{
			lseek(fd, (id - START_ID)*sizeof(rec), SEEK_SET);
			if(read(fd, &rec, sizeof(rec)) > 0 && rec.id != 0)
				printf("id : %d\tname : %s\tscore : %d\n", rec.id, rec.name, rec.score);
			else 
				printf("unknown record\n");	
		}else printf("wrong input number\n");
		
		printf("continue? (Y/N) : ");
		scanf(" %c", &input);

	}while(input == 'Y');	

	close(fd);
	exit(0);
}
