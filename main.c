#include "get_next_line.h"

int	main(int argc, char **argv)
{
	char	*buf;
	int	fd;
	int	readed;

	buf = (char *)malloc(sizeof(BUFFER_SIZE));
	if (argc == 0)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (buf == NULL || fd < 0)
		return (0);
	buf = get_next_line(fd);
	buf[readed] = '\0';
	write(1, buf, readed);
	free(buf);
	return (0);
}

