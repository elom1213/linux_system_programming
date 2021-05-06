// p203 copy argv[1] to argv[2] by fgetc fputc

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	FILE* fp1, *fp2;
	char data;
	char buf[BUFSIZ];

	if(argc < 2)
	{
		fprintf(stderr, "Use ./%s source dist", argv[0]);
		exit(1);
	}

	if((fp1 = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "%s Open fail", argv[1]);
		exit(2);
	}

	fp2 = fopen(argv[2], "w+");

	while((data = fgetc(fp1)) != EOF)
		fputc(data, fp2);

	// print fp2 by fputs
	fseek(fp2, 0, SEEK_SET);
	while(fgets(buf, BUFSIZ, fp2) != NULL)	
		fputs(buf, stdout);
	
	fclose(fp1);
	fclose(fp2);
	exit(0);
}
