// p147 change mode of file argv[2] to argv[1]

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{
	long strtol();
	int newmode;

	newmode = (int)strtol(argv[1], (char**)NULL, 8);
	if(chmod(argv[2], newmode) == -1)
	{
		perror(argv[2]);
		exit(1);
	}

	exit(0);
}
