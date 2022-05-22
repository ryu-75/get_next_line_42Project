#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#if BUFFER_SIZE && BUFFER_SIZE > 0

// Dans notre fonction get_next_line, on aura besoin d'un pointeur qui stockera la ligne qu'on aura lu
// D'un autre pointeur qui stockera les lignes dans un buffer
// Et d'un int qui stockera la fonction read() en memoire

char	*get_next_line(int fd)
{
	static	t_list	*stack;
	char		*line;
	int		reads;

	if (BUFFER_SIZE < 0 || fd < 0 || read(fd, &line, 0) < 0)
		return (-1);
	reads = 1;
	line = NULL;

	/* Faire une fonction qui permet de lire et de stocker en mémoire les lignes dans stack */

	return (line);
} 

/*
int	main(int argc, char **argv)
{
	FILE * test;
	char *buffer;

	if (argc == 0)
		return (0);
	buffer = (char *)malloc(sizeof(BUFFER_SIZE));
	test = fopen(argv[1], "r");
	if (test == NULL)
		return (-1);
	while (!feof(test))
	{
		fgets(buffer, BUFFER_SIZE, test);
		if (ferror(test))
		{
			printf("Reading error with code %d", errno);
			break ;
		}
		puts(buffer);
	}
	free(buffer);
	fclose(test);

	return (0);
}
*/
