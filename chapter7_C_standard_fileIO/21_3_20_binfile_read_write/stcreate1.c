// p212 stcreate.c
// scan id name score and save them to argv[1]
#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main(int argc, char* argv[])
{
	FILE* fp;
	struct student rec;
	
	if(argc < 2)
	{
		fprintf(stderr, "Use : %s filename\n", argv[1]);
		exit(1);	
	}

	fp = fopen(argv[1], "wb");
	printf("%-9s %-7s %-4s\n", "id", "name", "score");
	while(scanf("%d %s %d", &rec.id, rec.name, &rec.score) == 3)
		fwrite(&rec, sizeof(rec), 1, fp);

	fclose(fp);
	exit(0);
}
