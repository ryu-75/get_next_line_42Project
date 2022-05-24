#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 200

// PROTOTYPES

int	check_newline(char *line);
char	*get_next_line(int fd);
char	*ft_read_line(int fd, char *stash);

int	main(int argc, char **argv)
{
	int	fd;
	char	*readed;

	if (argc == 0)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || fd < -1)
		return (0);
	while (1)
	{
		readed = get_next_line(fd);
		printf("%s", readed);
		if (!readed)
			break ;
		free(readed);
	}
	return (0);
}

// Ma fonction get next line
char	*get_next_line(int fd)
{
	static char	*line;
	char		*stash;
	int	readed;
	
	if (fd < 0 || fd < -1 || readed == -1)
		return (NULL);
	readed = 1;
	ft_read_line(fd, line);
	return (line);
}
// Check si on rencontr un \n a la fin d une ligne
int	check_newline(char *line)
{
	int	i;
	
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (1);
		i++;	
	}
	return (0);
}

char	*ft_read_line(int fd, char *stash)
{
	char	*line;
	int	readed;
	
	while (!check_newline(line) != 1 && readed != 0)
	{
		line = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (line == NULL)
			return (NULL);
		readed = read(fd, line, BUFFER_SIZE);
		if (readed == 0 && stash == NULL)
		{
			free(line);
			return (NULL);
		}
		line[readed] = '\0';
	}
	return (line);
}
