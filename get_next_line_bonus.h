/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaria-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:34:12 by mfaria-p          #+#    #+#             */
/*   Updated: 2023/11/19 20:00:52 by mfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

void	*ft_calloc(size_t nmemb, size_t size);
int		ft_findnl(char *ptr);
size_t	ft_strlen(const char *s);
char	*ft_strappend(char *nest, char *buffer);
char	*get_next_line(int fd);
char	*get_newline(char *nest);
char	*get_rest(char *nest);
void	*free_all(char **nest, char **buffer);

#endif
