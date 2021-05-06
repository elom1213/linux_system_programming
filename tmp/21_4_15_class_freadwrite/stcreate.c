#include <stdio.h>
#include "student.h"

int main(int argc, char* argv[])
{
	struct student rec;
	FILE *fp;

	fp = fopen(argv[1], "wb");

	while((scanf("%d %s %d", &rec.id, rec.name, &rec.score)) == 3)
	{
		fseek(fp, (rec.id - START_ID)*sizeof(rec), SEEK_SET);
		fwrite(&rec, sizeof(rec), 1, fp);
	}

	fclose(fp);
	return 0;
}
