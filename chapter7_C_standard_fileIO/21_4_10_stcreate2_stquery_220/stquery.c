// p222 stquery.c
// query a record using fseek 
#include <stdio.h>
#include "student.h"

int main(int argc, char* argv[])
{
	struct student rec;
	FILE* fp;
	int id;
	int loop = 0;

	if(argc !=2)
	{
		fprintf(stderr, "Use : %s filename\n", argv[0]);
		return 1;
	}

	if((fp = fopen(argv[1], "rb")) == NULL)
	{
		fprintf(stderr, "open error\n");
		return 2;
	}

	do
	{
		printf("type id => ");
		if(scanf("%d", &id) == 1)
		{
			fseek(fp, (id - START_ID)*sizeof(rec), SEEK_SET);
			if(fread(&rec, sizeof(rec), 1, fp) > 0 && rec.id != 0)
				printf("id : %-8d name : %-4s score : %-4d\n", rec.id, rec.name, rec.score);
			else
				printf("unknown record : %d\n", id);

		}else
			printf("unknown id\n");

		printf("Continue : 1, Stop : 0\n");
		scanf("%d", &loop);

	}while(loop == 1);
	
	fclose(fp);
	return 0;
}
