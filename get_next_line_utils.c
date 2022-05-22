#include "get_next_line.h"

/* On écrit une fonction qui va pour permettre de lire les lignes de notre fichier et de les stocker dans stack*/

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

/* Une fonction qui va vérifier si on est arrivé à la fin de la ligne */

int	ft_find_newline(char *stack);

/* Une fonction qui récupére le dernier élément de la liste avec lst_getback_last */

t_list	*ft_getback_last(t_list *stack);
