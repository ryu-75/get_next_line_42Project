/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:06:18 by nlorion           #+#    #+#             */
/*   Updated: 2022/05/30 15:08:37 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# define BUFFER_SIZE

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

char	*ft_check_line(char *line);

char	*ft_check_last_line(char *line, char *buf);

char	*get_next_line(int fd);

char	*ft_read_line(int fd, char *line, char *buf);

char	*ft_strjoin(char *s1, char *s2);

char	*ft_strchr(char *str, int c);

int		ft_strlen(char *str);

#endif
