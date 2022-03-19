/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.42.fr> >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:35:38 by jlamonic          #+#    #+#             */
/*   Updated: 2022/03/19 19:53:29 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Функция strncmp() сравнивает не более n символов.
** Поскольку функция strncmp() предназначена для
** сравнения строк, а не двоичных данных, символы,
** появляющиеся после символа `\0', не сравниваются.
**
** RETURN
**
** Функции strncmp() возвращают целое число, большее,
**  равное или меньшее 0, в зависимости от того, является ли строка s1
** больше, равна или меньше
** чем строка s2. Сравнение выполняется с использованием символов
** без знака, так что "\200 "больше, чем "\0".
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		if (i < (n - 1))
			i++;
		else
			return (0);
	}
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}