#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 200

// PROTOTYPES

int	check_newline(char *line);
char	*get_next_line(int fd);
char	*ft_read_line(int fd);
int	ft_strlen(char *str);
char	*ft_strjoin(char *buf, char *line);

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
	static char	buf[BUFFER_SIZE + 1];
	int	readed;
	char	*line;
	
	if (fd < 0 || fd < -1 || readed == -1)
		return (NULL);
	line = ft_strjoin(buf, line);
	while (!check_newline(line) && readed != 0)
	{
		line = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (line == NULL)
			return (NULL);
		readed = read(fd, line, BUFFER_SIZE);
		if (readed == 0)
		{
			free(line);
			return (NULL);
		}
		line = ft_strjoin(buf, line);
		line[readed] = '\0';
	}
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
		else 
			return (0);
		i++;
	}
	return (0);
}

// Ecrire un strjoin qui va me permettre de deplacer mes lignes dans mon buffer
char	*ft_strjoin(char *buf, char *line)
{
	int	len;
	int	i;
	char	*tab;
	
	len = (ft_strlen(buf) + ft_strlen(line));
	buf = (char *)malloc(sizeof(char) * len + 1);
	if (!buf)
		return (NULL);
	i = 0;
	while (line[i] != '\0')
	{
		buf[i] = line[i];
		i++;
	}
	return (buf);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while(str[len] != '\0')
		len++;
	return (len);
}
