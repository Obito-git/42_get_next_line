#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int ac, char **av)
{
	int fd_open1;
	int fd_open2;
	fd_open1 = open("test/test.txt", 'r');
	printf("%s", get_next_line(fd_open1));
	printf("%s", get_next_line(fd_open1));
//	printf("%s", get_next_line(fd_open1));
//	print_list();
	close(fd_open1);
//	close(fd_open2);
//	char *test = "123456789";
//	printf("%d\n", find_char(test));
}
