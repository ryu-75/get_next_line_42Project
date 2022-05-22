# ifndef GET_NEXT_LINE
#define GET_NEXT_LINE

# include "stdio.h"
# include "stdlib.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

typedef struct	s_list
{
	char		*content;
	struct s_list	*next;
}		t_list;

#endif
