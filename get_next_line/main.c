#include "get_next_line.h"

// int	main(void)
// {
// 	// char *str;
// 	int i = 0;

// 	int fd = open("test.txt", O_RDONLY);
// 	// str = get_next_line(fd);
// 	while (i < 5)
// 	{
// 		printf("%s", get_next_line(fd));
// 		i++;
// 	}
// 	printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	return (0);
// };

int	main(void)
{
	int fd;
	char *str;

	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	close(fd);
	return (0);
};
