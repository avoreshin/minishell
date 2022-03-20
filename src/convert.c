/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:56:52 by jlamonic          #+#    #+#             */
/*   Updated: 2022/03/17 21:57:55 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env_lstsize(t_env *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

char	**convert_env_lst_to_dp(t_env *env)
{
	int		len;
	char	**envp;
	char	*join_env;
	char	*tmp;
	int		i;

	len = ft_env_lstsize(env);
	envp = (char **)malloc(sizeof(char *) * len + 1);
	envp[len] = NULL;
	i = 0;
	while (len--)
	{
		tmp = ft_strjoin(env->key, "=");
		join_env = ft_strjoin(tmp, env->value);
		free(tmp);
		envp[i++] = join_env;
		env = env->next;
	}
	return (envp);
}
