/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.42.fr> >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:42:27 by jlamonic          #+#    #+#             */
/*   Updated: 2022/03/19 19:53:29 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** выделяет (с помощью malloc(3)) и возвращает новую
** строку, которая является результатом конкатенации
** ’s1’ и ’s2’
**
** RETURN
** Новая строка. NULL, если выделение не удается
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		l1;
	int		l2;

	if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	l1 = 0;
	while (s1[l1])
	{
		s3[l1] = s1[l1];
		l1++;
	}
	l2 = 0;
	while (s2[l2])
	{
		s3[l1 + l2] = s2[l2];
		l2++;
	}
	s3[l1 + l2] = 0;
	return (s3);
}
