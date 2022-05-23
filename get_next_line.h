# ifndef GET_NEXT_LINE
#define GET_NEXT_LINE

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

typedef struct	s_list
{
	char		*content;
	struct s_list	*next;
}		t_list;

char	*get_next_line(int fd);
void	ft_read_and_stash(int fd, t_list *stash, int *readed);
#endif
