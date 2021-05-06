// p 208 fprintf to argv[1]
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

	fp = fopen(argv[1], "w"); 
	printf("%-9s %-7s %-4s\n", "id", "name", "score");

	while(scanf("%d %s %d", &rec.id, rec.name, &rec.score) == 3)
		fprintf(fp, "%d %s %d ", rec.id, rec.name, rec.score);

	fclose(fp);
	return 0;
}
