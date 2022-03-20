/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:26:39 by jlamonic          #+#    #+#             */
/*   Updated: 2022/03/19 20:33:35 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(char **dbuf, t_env **env_list)
{
	int		i;
	t_env	**pp;
	t_env	*del;

	i = -1;
	while (dbuf[++i])
	{
		if (!unset_key_syntax_check(dbuf[i]))
			continue ;
		pp = env_list;
		while (*pp)
		{
			if (!ft_strcmp(dbuf[i], (*pp)->key))
			{
				del = *pp;
				*pp = ((*pp)->next);
				free(del->key);
				free(del->value);
				free(del);
			}
			if (*pp)
				pp = &(*pp)->next;
		}
	}
	g_stat = 0;
}

void	ft_cd(char **buf, t_env *env_list)
{
	int	error;
	int	temp;

	if (!buf[0])
	{
		chdir(read_value_of_key(env_list, "HOME"));
		g_stat = 0;
		return ;
	}
	temp = chdir(buf[0]);
	if (temp < 0)
	{
		error = errno;
		cd_error(error, buf[0]);
		g_stat = error;
		return ;
	}
	g_stat = 0;
}

void	ft_env(t_env *env_list)
{
	t_env	*one;

	one = env_list;
	while (one)
	{
		printf("%s=%s\n", one->key, one->value);
		one = one->next;
	}
	g_stat = 0;
}

int	unset_key_syntax_check(char *s)
{
	int	i;

	i = -1;
	if (s[0] > 47 && s[0] < 58)
	{
		write(2, "bash: unset: `", 14);
		write(2, s, ft_strlen(s));
		write(2, "': not a valid identifier\n", 27);
		g_stat = 1;
		return (0);
	}
	while (s[++i])
	{
		if (s[i] == '_')
			continue ;
		if (!ft_isalnum(s[i]))
		{
			write(2, "bash: unset: `", 14);
			write(2, s, ft_strlen(s));
			write(2, "': not a valid identifier\n", 27);
			g_stat = 1;
			return (0);
		}
	}
	return (1);
}

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
