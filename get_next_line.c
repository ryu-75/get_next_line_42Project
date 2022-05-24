/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
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
	static t_list	*line;
	char		*stash;
	int		readed;

	stash = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	read_and_stash(fd, &stash);
	if (!stash)
		return (NULL);
	// 2. On extrait la ligne 
	return (line->content);
}

void	read_and_stash(int fd, t_list **stash)
{
	char	*buf;
	int	readed;

	readed = 1;
	new_line = malloc(sizeof(t_list));
	if (!new_line)
		return ;
	while (!check_newline(*stash) && readed != 0)
	{
		buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (buf == NULL)
			return ;
		readed = (int)read(fd, buf, BUFFER_SIZE);
		if ((*stash == NULL && readed == 0) || readed == -1)
		{
			free(buf);
			return ;
		}
		buf[readed] = '\0';
		add_to_stash(stash, buf, readed);
		free(buf);
	}
}

void	add_to_stash(t_list **stash, char *buf, int readed)
{
	t_list	*new_line;
	t_list	*last;
	int		i;

	i = 0;
	new_line->next = NULL;
	new_line->content = malloc(sizeof(char) * readed + 1);
	if (new_line == NULL)
		return ;
	while (buf[i] && i < readed)
	{
		new_line->content[i] = buf[i];
		i++;
	}
	new_line->content[i] = '\0';
	if (*stash == NULL)
	{
		*stash = new_line;
		return ;
	}
	ft_getback_last(*stash);
	last->next = new_line;
}

t_list	*ft_getback_last(t_list *stash)
{
	t_list	*last;
	
	last = stash;
	while (last && last->next)
		last = stash->next;
	return (last);
}

/* Je check les lignes de fichier, si le curseur rencontre un '\n', la fonction retourne 1 sinon 0 */

int	check_newline(t_list **stash)
{
	int	i;
	t_list	*current;

	if (!stash)
		return (0);
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	add_line_to_stash()

int	main()
{
	char	**tab = 
}
