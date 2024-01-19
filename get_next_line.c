/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaria-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:28:17 by mfaria-p          #+#    #+#             */
/*   Updated: 2023/11/19 19:46:24 by mfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_newline(char *nest)
{
	char	*temp;
	int		i;

	if (!*nest)
		return (NULL);
	i = 0;
	while (nest[i] && nest[i] != '\n')
		i++;
	temp = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (nest[i] && nest[i] != '\n')
	{
		temp[i] = nest[i];
		i++;
	}
	temp[i] = nest[i];
	return (temp);
}

char	*get_rest(char *nest)
{
	char	*temp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (nest[i] && nest[i] != '\n')
		i++;
	if (!*nest)
	{
		free(nest);
		return (NULL);
	}
	temp = ft_calloc(ft_strlen(nest) - i + 1, sizeof(char));
	while (nest[i])
		temp[j++] = nest[++i];
	temp[j] = '\0';
	free(nest);
	return (temp);
}

void	*free_all(char **nest, char **buffer)
{
	if (nest != NULL)
	{
		free(*nest);
		*nest = NULL;
	}
	if (buffer != NULL)
	{
		free(*buffer);
		*buffer = NULL;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	int				read_count;
	char			*buffer;
	char			*line;
	static char		*nest;

	read_count = BUFFER_SIZE;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (!(ft_findnl(buffer)) && read_count)
	{
		read_count = read(fd, buffer, BUFFER_SIZE);
		if (read_count == -1)
			return (free_all(&nest, &buffer));
		buffer[read_count] = '\0';
		nest = ft_strappend(nest, buffer);
	}
	line = get_newline(nest);
	nest = get_rest(nest);
	free(buffer);
	return (line);
}

/*#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	char	*line;

	int fd = open("1char.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);

	free(line);
	close(fd);
}*/
