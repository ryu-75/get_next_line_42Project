/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:16:48 by nlorion           #+#    #+#             */
/*   Updated: 2022/05/27 16:52:19 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

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

int	ft_strlen(char *str);

#endif
