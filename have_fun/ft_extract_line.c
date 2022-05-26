#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 200

// PROTOTYPES

char	*ft_check_line(char *line);
char	*ft_check_last_line(char *buf, char *line);
char	*get_next_line(int fd);
char	*ft_read_line(int fd, char *buf, char *line);
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
	
	if (fd < 0 || fd < -1 || read(fd, buf, BUFFER_SIZE) <= -1)
		return (NULL);
	line = ft_read_line(fd, buf, line);
	if (line == NULL)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*ft_read_line(int fd, char *buf, char *line)
{
	int	readed;

	readed = 1;
	line = ft_strjoin(buf, line);
	while (readed != 0)
	{
		if (readed == 0)
			return (NULL);
		printf("1 : %s\n", line);
		readed = read(fd, line, BUFFER_SIZE);
		if (!line || !buf)
		{
			free(line);
			return (NULL);
		}
		ft_check_line(line);
		ft_check_last_line(buf, line);
		printf("2 : %s\n", line);
		line = ft_strjoin(buf, line);
		line[readed] = '\0';
	}
	return (line);
}

// Check si on rencontr un \n a la fin d une ligne
char	*ft_check_line(char *line)
{
	int	i;
	
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	line[i] = '\0';
	return (line);
}

char	*ft_check_last_line(char *buf, char *line)
{
	int	i;
	int	j;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] && line[i] == '\n')
	{
		i++;
		j = 0;
		while (line[i])
		{
			buf[j] = line[i];
			i++;
			j++;
		}
		line[i] = '\0';
	}
	return (line);
}

// Ecrire un strjoin qui va me permettre de deplacer mes lignes dans mon buffer
char	*ft_strjoin(char *buf, char *line)
{
	int	len;
	int	i;
	char	*tab;
	char	*newstr;

	newstr = NULL;	
	len = (ft_strlen(buf) + ft_strlen(line));
	tab = (char *)malloc(len + sizeof(char) + 1);
	newstr = tab;
	if (!newstr)
		return (NULL);
	i = 0;
	while (*buf != '\0')
		*tab++ = *buf++;
	while (line[i] != '\0')
		*tab++ = *line++;
	*tab = '\0';
	return (newstr);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return (i);
}



