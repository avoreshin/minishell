/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:39:33 by jlamonic          #+#    #+#             */
/*   Updated: 2022/03/17 21:41:10 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	if (s2[i] == s1[i])
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_free_split(char **draw)
{
	int	i;

	i = 0;
	while (draw[i])
		free(draw[i++]);
	free(draw);
}

t_env	*env_dup_check(t_env *env_list, char *new_key)
{
	t_env	*temp;

	temp = env_list;
	while (temp)
	{
		if (!ft_strcmp(temp->key, new_key))
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

t_env	*env_set(char	**envp)
{
	char	**splits;
	t_env	*temp;
	t_env	*env_list;

	temp = NULL;
	env_list = 0;
	while (*envp)
	{
		splits = ft_split(*(envp++), '=');
		env_lstadd_back(&env_list, temp, splits[0], splits[1]);
		free(splits);
	}
	return (env_list);
}

void	env_lstadd_back(t_env **lst, t_env *new, char *key, char *value)
{
	t_env	**phead;

	new = (t_env *)malloc(sizeof(t_env));
	new->key = key;
	new->value = value;
	new->print_check = 0;
	phead = lst;
	while (*phead)
		phead = &(*phead)->next;
	new->next = *phead;
	*phead = new;
}
