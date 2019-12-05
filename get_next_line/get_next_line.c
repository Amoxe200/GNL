/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 20:18:57 by aaqari            #+#    #+#             */
/*   Updated: 2019/12/05 14:30:20 by aaqari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	freeptr(char **ptr, int r)
{
	free(*ptr);
	*ptr = NULL;
 	return (r);
}

int	checksave(char **line , char **save)
{
	char *ptr;
	char *temp;
	
	if (*save)
	{
		temp = *line;
		if ((ptr = ft_strchr(*save,'\n')))
		{
			*ptr = '\0';
			*line = ft_strjoin(*line,*save);
			free(temp);
			temp = *save;
			*save = ft_strdup(ptr + 1);
			free(temp);
			return(1);
		}
		*line = ft_strjoin(*line,*save);
		free(temp);
		free(*save);
		*save = NULL;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char		*save;
    char			*buff;
    char			*ptr;
    int				rt;
	char			*temp;
	if (fd < 0 || !(line) || !(buff = malloc(BUFFER_SIZE +1)) || read(fd,buff,0))
		return (-1);
	*line = ft_strdup("");
	if (checksave(line,&save))
		return(freeptr(&buff,1));
	while ((rt = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[rt] = '\0';
		if ((ptr = ft_strchr(buff, '\n')))
		{
			*ptr    = '\0';
			temp = *line;
			*line   = ft_strjoin(*line, buff);
			free(temp);
			save    = ft_strdup(ptr + 1);
			return (freeptr(&buff,1));
		}
		ptr = *line;
		*line   = ft_strjoin(*line, buff);
		free(ptr);
	}
	return (freeptr(&buff,0));
}
