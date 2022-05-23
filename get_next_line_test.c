/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:19:12 by nlorion           #+#    #+#             */
/*   Updated: 2022/05/23 16:45:10 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Tant que je ne rencontre pas de \n, je stock la ligne dans un pointeur temporaire qui est le content de t_list */
/* Une fois tomber sur le \n, je stock la ligne dans le buffer et free mon pointeur temporaire */
/* Je stock dans mon buffer toutes les lignes  */

char	*get_next_line(int fd)
{
	//static t_list	*line;
	char		*buf;
	int		readed;
	
	buf = (char *)malloc(sizeof(buf) * BUFFER_SIZE + 1);
	//line = NULL;
	if (!buf)
		return (NULL);
	readed = read(fd, buf, BUFFER_SIZE);
	
	buf[readed] = '\0';
	return (buf);
}

/*
void	read_and_stash(char **stash, int *readed)
{
	char	*buf;
	int	i;

	while (stash)
	{
		buf = (char *)malloc(sizeof(buf) * BUFFER_SIZE + 1);
		if (!buf || *readed < 0 || *readed < -1)
			return ;
		while (*stash->content[i])
		{
			buf[i] = stash->content[i]
		}		
		*readed = (int)read(fd, buf, BUFFER_SIZE);
	}
}*/

int	main(int argc, char **argv)
{
	int	fd;
	char	*buffer;

	buffer = (char *)malloc(sizeof(BUFFER_SIZE));	

	/* On ouvre le fichier : on recupere un fd sur le fichier */
	/* Il ne peut pas y avoir de fd negatif, si c est le cas l ouverture a echoue : dans ce cas on sort du programme  */ 
	
	if (argc == 0)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (!buffer || fd < 0)
		return (0);
;
	/* Apres la lecture -> on passe a read : le fd, le buffer et la taille du buffer  */
	/* Si la taille du buffer est plus grand que la taille du buffer lui meme, le programme devient sensible au overflow  */ 

	buffer = get_next_line(fd);

	/* On finis par le caractere 0 pour avoir une chaine finis */
	/* Line correspond au dernier caractere de buffer + 1 */

	printf("%s", buffer);
	buffer[fd] = '\0';

	free(buffer);	
	return (0);
}
