/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaria-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:28:00 by mfaria-p          #+#    #+#             */
/*   Updated: 2023/11/19 19:51:37 by mfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	int		index;

	index = 0;
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
		temp[index++] = nest[++i];
	temp[index] = '\0';
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
	static char		*nest[1024];

	read_count = BUFFER_SIZE;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (!(ft_findnl(buffer)) && read_count)
	{
		read_count = read(fd, buffer, BUFFER_SIZE);
		if (read_count == -1)
			return (free_all(&nest[fd], &buffer));
		buffer[read_count] = '\0';
		nest[fd] = ft_strappend(nest[fd], buffer);
	}
	line = get_newline(nest[fd]);
	nest[fd] = get_rest(nest[fd]);
	free(buffer);
	return (line);
}

/*int main(void)
{
	char	*line;

	int fd1 = open("file1.txt", O_RDONLY);
	int fd2 = open("file2.txt", O_RDONLY);
	line = get_next_line(fd1);
	printf("%s", line);
	free(line);
	line = get_next_line(fd2);
	printf("%s", line);
	free(line);
	line = get_next_line(fd1);
	printf("%s", line);
	free(line);
	line = get_next_line(fd2);
	printf("%s", line);
	free(line);
	close(fd1);
	close(fd2);
}*/
