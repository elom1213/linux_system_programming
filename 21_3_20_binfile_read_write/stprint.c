// print student db argv[1]
#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main(int argc, char* argv[])
{
	FILE* fp;
	struct student rec;

	if(argc < 2 )
	{
		fprintf(stderr, "Use : %s filename\n", argv[0]);
		exit(1);
	}

	if((fp = fopen(argv[1], "rw")) == NULL)
	{
		fprintf(stderr, "open fail");
		exit(2);
	}

	while(fread(&rec, sizeof(rec), 1, fp) > 0)
		if(rec.id > 0)
			printf("%10d %6s %6d\n", rec.id, rec.name, rec.score);

	fclose(fp);
	exit(0);
}
