/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaria-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:28:50 by mfaria-p          #+#    #+#             */
/*   Updated: 2023/11/19 19:28:54 by mfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	int		i;
	int		n;

	i = 0;
	n = nmemb * size;
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	while (n--)
		ptr[i++] = '\0';
	return (ptr);
}

int	ft_findnl(char *ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return (0);
	while (ptr[i])
	{
		if (ptr[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strappend(char *nest, char *buffer)
{
	char	*temp;
	int		i;
	int		j;
	int		size;

	if (!nest)
		nest = ft_calloc(1, sizeof(char));
	if (!buffer)
		return (NULL);
	i = 0;
	j = 0;
	size = ft_strlen(nest) + ft_strlen(buffer);
	temp = ft_calloc((size + 1), sizeof(char));
	while (nest[i])
	{
		temp[i] = nest[i];
		i++;
	}
	while (buffer[j])
		temp[i++] = buffer[j++];
	free(nest);
	return (temp);
}
