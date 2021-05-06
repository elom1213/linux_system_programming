// p264 uid.c
#include <stdio.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

int main()
{
	printf("real user ID => %d(%s)\n", getuid(), getpwuid(getuid())->pw_name);
	printf("effective user ID => %d(%s)\n", geteuid(), getpwuid(geteuid())->pw_name );
	printf("real group ID => %d(%s)\n", getgid(), getgrgid(getgid())->gr_name );
	printf("effective group ID => %d(%s)\n", getegid(), getgrgid(getegid())->gr_name);
}
