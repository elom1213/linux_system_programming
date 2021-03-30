#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

// print size(bytes) and path name(argv[1])

int main(int argc, char* argv[])
{
	DIR* dp;
	struct dirent* dent;
	struct stat st;
	char* dir;
	char path[BUFSIZ + 1];

	if(argc == 1)
		dir = ".";
	else
		dir = argv[1];
	
	if((dp = opendir(dir)) == NULL)
	{
		perror(dir);
		exit(1);
	}

	while((dent = readdir(dp)) != NULL)
	{
		sprintf(path, "%s/%s", dir, dent->d_name);
		if(lstat(path, &st) < 0)
			perror(path);
		else
			printf("%5ld %s\n", st.st_size, dent->d_name);
	}
	closedir(dp);
	exit(0);
}
