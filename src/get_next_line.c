/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 22:19:52 by jlamonic          #+#    #+#             */
/*   Updated: 2022/03/17 22:20:05 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_next_line(char **line)
{
	char	buffer;
	int		re;

	*line = (char *)malloc(1);
	if (*line == NULL)
		return (-1);
	(*line)[0] = 0;
	re = read(0, &buffer, 1);
	while (buffer != '\n' && buffer != '\0')
	{
		*line = sum(*line, buffer);
		if (*line == 0)
			return (-1);
		re = read(0, &buffer, 1);
	}
	if (buffer == '\n')
		return (1);
	return (0);
}
