/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:19:12 by nlorion           #+#    #+#             */
/*   Updated: 2022/05/23 11:50:48 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* On écrit une fonction qui va pour permettre de lire les lignes de notre fichier et de les stocker dans stack*/
/*
void	ft_read_files(int fd, t_list *stack, int *reads)
{
	char	*buf;

	buf = malloc(sizeof(t_list) * BUFFER_SIZE + 1);
	if (!buf)
		return ;
	while (!ft_find_newline(stack) && *reads != 0)
	{
		*reads = (int)read(fd, buf, BUFFER_SIZE);
		if (stack == NULL || *read < 0 || *reads < -1)
		{
			free(buf);
			return ;
		}
		buf[*reads] = '\0';
	}
}
*/
/* Une fonction qui va vérifier si on est arrivé à la fin de la ligne */
/*
char	*ft_find_newline(int fd)
{
	int	i;
	char	*buffer;
	int	*reads;

	i = 0;
	buffer = malloc(sizeof(t_list) * BUFFER_SIZE + 1);
	buffer = (int)read(fd, buffer, BUFFER_SIZE);
	if (buffer == NULL || *reads < -1 || *reads < 0)

	{
		free(buffer);
		return (NULL);
	}
	while (reads)
	{
		buffer[i] = reads[i];
		i++;
	}
	return (buffer);
}
*/
/* Une fonction qui récupére le dernier élément de la liste avec lst_getback_last */

//t_list	*ft_getback_last(t_list *stack);

int	main(int argc, char **argv)
{
	int	fd;
	int	line;
	char	*buffer;
	int	i;

	i = 0;
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

	line = read(fd, buffer, BUFFER_SIZE);

	/* On finis par le caractere 0 pour avoir une chaine finis */
	/* Line correspond au dernier caractere de buffer + 1 */

	buffer[line] = '\0';

	write(1, buffer, line);
	
	free(buffer);	
	return (0);
}
