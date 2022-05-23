#include "get_next_line.h"

// Dans notre fonction get_next_line, on aura besoin d'un pointeur qui stockera la ligne qu'on aura lu
// D'un autre pointeur qui stockera les lignes dans un buffer
// Et d'un int qui stockera la fonction read() en memoire

char	*get_next_line(int fd)
{
	static	t_list	*stack;
	char		*line;
	int		reads;

	if (BUFFER_SIZE < 0 || fd < 0 || read(fd, &line, 0) < 0)
		return (NULL);
	reads = 1;
	line = NULL;

	/* Faire une fonction qui permet de lire et de stocker en mémoire les lignes dans stack */
	ft_read_files(fd, stack, &reads);
	return (line);
} 


int	main(void)
{
	int	fd;
	char *buffer;

	buffer = (char *)malloc(sizeof(BUFFER_SIZE));
	fd = open("test.txt", O_RDONLY);
	if (!buffer)
		return (NULL);
	buffer = get_next_line(fd);
	printf("%s", buffer);
	free(buffer);

	return (0);
}

