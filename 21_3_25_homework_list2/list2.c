#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

// p155 print size submission block etc... same with ls -als

void printStat(char* filename, struct stat*);
char getType(mode_t);
char* getPermission(mode_t);

int main(int argc, char* argv[])
{
	DIR* dp;
	char* dir;
	struct stat st;
	struct dirent* dent;
	char path[BUFSIZ + 1];

	if(argc == 1)
		dir = ".";
	else
		dir = argv[1];
	
	if((dp = opendir(dir)) == NULL)
	{
		perror(dir);
		//exit(1);
	}

	while((dent = readdir(dp)) != NULL)
	{
		sprintf(path, "%s/%s", dir, dent->d_name);
		if(lstat(path, &st) < 0)
			perror(path);
		else
			printStat(dent->d_name, &st);
	}

	closedir(dp);
	exit(0);
}

void printStat(char* filename, struct stat* st)
{
	printf(" %5ld", st->st_blocks);
	printf(" %c%s", getType(st->st_mode), getPermission(st->st_mode));
	printf(" %3ld", st->st_nlink);
	printf(" %s", getpwuid(st->st_uid)->pw_name);
	printf(" %s", getgrgid(st->st_gid)->gr_name);
	printf(" %9ld", st->st_size);
	printf(" %.12s", ctime(&st->st_mtime)+4);
	//printf(" %12.*s", '\n', ctime(&st->st_mtim.tv_sec)+4);
	printf(" %s", filename);

	if(S_ISDIR(st->st_mode))
		putchar('/');
	putchar('\n');
}

char getType(mode_t mode)
{
	if(S_ISREG(mode))
		return('-');
	if(S_ISDIR(mode))
		return('d');
	if(S_ISCHR(mode))
		return('c');
	if(S_ISBLK(mode))
		return('b');
	if(S_ISLNK(mode))
		return('l');
	if(S_ISFIFO(mode))
		return('p');
	if(S_ISSOCK(mode))
		return('s');
}

char* getPermission(mode_t mode)
{
	static char perm[10] = "---------";

	for(int i = 0; i < 3; i++)
	{
		if(mode & (S_IRUSR >> i*3))
			perm[i*3] = 'r';
		if(mode & (S_IWUSR >> i*3))
			perm[i*3 + 1] = 'w';
		if(mode & (S_IXUSR >> i*3))
			perm[i*3 + 2] = 'x';
	}
	return(perm);
}
