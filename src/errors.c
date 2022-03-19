/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 20:44:56 by jlamonic          #+#    #+#             */
/*   Updated: 2022/03/19 20:44:56 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd_error(int err, char *arg)
{
	char	*errmsg;

	errmsg = strerror(err);
	write(2, "bash: cd: ", 10);
	write(2, arg, ft_strlen(arg));
	write(2, ": ", 2);
	write(2, errmsg, ft_strlen(errmsg));
	write(2, "\n", 1);
}
