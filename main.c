#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int ac, char **av)
{

	int fd_open1;
	int fd_open2;
	char *res;
	fd_open1 = open("gnlTester/files/multiple_nlx5", 'r');
	if (fd_open1 <= 0)
		printf("XYU");
	else
	{
		res = get_next_line(fd_open1);
		int i = 1;
		while (res)
		{
		printf("%d: %s", i++, res);
		if (res)
			free(res);		
		res = get_next_line(fd_open1);
		}
		close(fd_open1);
	}
}
