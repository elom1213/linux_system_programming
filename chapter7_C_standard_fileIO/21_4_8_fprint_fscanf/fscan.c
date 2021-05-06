// p 209 fscanf from argv[1], printf each record 
#include <stdio.h>
#include "student.h"

int main(int argc, char* argv[])
{
	struct student rec;
	FILE* fp;
	
	if(argc != 2)
	{
		fprintf(stderr, "Use : %s filename", argv[1]);
		return 1;
	}

	fp = fopen(argv[1], "r"); 
	printf("%-9s %-7s %-4s\n", "id", "name", "score");

	while(fscanf(fp, "%d %s %d", &rec.id, rec.name, &rec.score) == 3)
		printf("%d %s %d\n", rec.id, rec.name, rec.score);

	fclose(fp);
	return 0;
}
