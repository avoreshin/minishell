/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:57:45 by jlamonic          #+#    #+#             */
/*   Updated: 2022/03/19 13:57:48 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expand_env_var(t_proc *proc, char *data, int start, char **new_data)
{
	char	*get_env;
	char	*temp;

	*new_data = parse_pre_env_var(data, start, *new_data);
	if (!(*new_data))
		return (NULL);
	data = &data[start + 1];
	get_env = ft_strndup(data, find_valid_env_var_point(data));
	data = &data[find_valid_env_var_point(data)];
	if (!get_env)
		return (ft_free(*new_data));
	temp = get_env;
	if (get_env[0] == '?')
		get_env = ft_itoa(g_stat);
	else
		get_env = read_value_of_key(proc->env_lst, get_env);
	ft_free(temp);
	temp = *new_data;
	*new_data = ft_strjoin(*new_data, get_env);
	ft_free(temp);
	ft_free(get_env);
	if (!(*new_data))
		return (NULL);
	return (data);
}

char	*expand_in_quot_env_var(t_proc *proc, char *data, int start, int end)
{
	char	*new_data;
	char	*temp;
	char	*temp2;

	new_data = ft_strndup(data, start);
	if (!new_data)
		return (NULL);
	data = &data[start + 1];
	data = ft_strndup(data, end - start - 1);
	if (!data)
		return (ft_free(new_data));
	temp2 = data;
	data = expand_in_quot_utils(proc, data, &new_data);
	if (!data)
		return (ft_free(temp2));
	temp = new_data;
	new_data = ft_strjoin(new_data, data);
	ft_free(temp2);
	ft_free(temp);
	return (new_data);
}

char	*expand_data(t_proc *proc, char *data)
{
	char	*new_data;
	char	*temp;
	int		i;

	new_data = NULL;
	i = -1;
	while (data[++i])
	{
		if (data[i] == '\'' && i != find_valid_quot_point(data, i))
			data = del_small_quot_token(data, i, &new_data);
		else if (data[i] == '\"' && i != find_valid_quot_point(data, i))
			data = del_big_quot(proc, data, i, &new_data);
		else if (data[i] == '$')
			data = expand_env_var(proc, data, i, &new_data);
		else
			continue ;
		if (!data)
			return (ft_free(new_data));
		i = -1;
	}
	temp = new_data;
	new_data = ft_strjoin(new_data, data);
	ft_free(temp);
	return (new_data);
}

char	*del_big_quot(t_proc *proc, char *data, int start, char **new_data)
{
	char	*org_data;
	char	*temp;
	int		end;

	org_data = *new_data;
	temp = NULL;
	end = find_valid_quot_point(data, start);
	if (find_env_var_token(data, start, end) == TRUE)
		temp = expand_in_quot_env_var(proc, data, start, end);
	else
		temp = my_strtrim(data, start, end);
	if (!temp)
		return (ft_free(org_data));
	*new_data = ft_strjoin(*new_data, temp);
	ft_free(org_data);
	ft_free(temp);
	if (!(*new_data))
		return (NULL);
	data = &data[end + 1];
	return (data);
}

char	*del_small_quot_token(char *data, int start, char **new_data)
{
	char	*org_data;
	char	*temp;
	int		end;

	org_data = *new_data;
	temp = NULL;
	end = find_valid_quot_point(data, start);
	temp = my_strtrim(data, start, end);
	if (!temp)
		return (NULL);
	*new_data = ft_strjoin(*new_data, temp);
	ft_free(org_data);
	ft_free(temp);
	if (!(*new_data))
		return (NULL);
	data = &data[end + 1];
	return (data);
}
