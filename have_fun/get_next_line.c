/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:26:12 by nlorion           #+#    #+#             */
/*   Updated: 2022/05/27 17:41:00 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char	*line;
	
	line = NULL;
	if (fd < 0 || read(fd, buf, 0) == -1)	
		return (NULL);
	line = ft_read_line(fd, line, buf);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*ft_read_line(int fd, char *line, char *buf)
{
	int	readed;

	readed = 1;
	line = ft_strjoin(line, buf);
	while (readed != 0)
	{
		readed = read(fd, buf, BUFFER_SIZE + 1);
		buf[readed] = '\0';
		line = ft_strjoin(line, buf);
		if (ft_strchr(line, '\n'))
		{	
			buf = ft_check_last_line(line, buf);
			line = ft_check_line(line);
			break ;
		}
		if (line == NULL)
			return (NULL);
	}
	return (line);
}

char	*ft_check_line(char *line)
{
	int	i;
	
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	i++;
	line[i] = '\0';
	return (line);
}

char	*ft_check_last_line(char *line, char *buf)
{
	int	i;
	int	j;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	j = 0;
	if (line[i] == '\n')
	{
		i++;
		while (line[i])
		{
			buf[j] = line[i];
			i++;
			j++;
		}
		buf[j] = '\0';
	}
	return (buf);
}
/*
int	main(int argc, char **argv)
{
	int	fd;
	char	*readed;

	if (argc == 0)
		return (0);
	if (fd < 0 || fd == -1)
		return (0);
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		readed = get_next_line(fd);
		printf("%s\n", readed);
		if (!readed)
			break ;
	}
	return (0);
}
*/
