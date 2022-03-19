/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 22:38:44 by jlamonic          #+#    #+#             */
/*   Updated: 2022/03/19 20:35:49 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_input(char *input, t_env *env, char **envp)
{
	t_list	*token;

	token = 0;
	add_history(input);
	if (split_token(input, &token) == TRUE && check_token(token) == TRUE)
	{
		handle_heredoc(token);
		parse_pipe_token(token, env, envp);
		while (waitpid(-1, &g_stat, 0) > 0)
			continue ;
	}
	if (WIFEXITED(g_stat))
		g_stat = WEXITSTATUS(g_stat);
	ft_lstclear(&token, free);
}

int	main(int argc, char **argv, char **envp)
{
	t_set	set;
	t_env	*env;
	char	*input;

	argc = 0;
	argv = 0;
	init_set(&set, &env, envp);
	signal(SIGINT, ft_handler);
	while (1)
	{
		init_set2(&set, &envp, env);
		input = readline("$ ");
		signal(SIGQUIT, ft_handler);
		if (!input)
		{
			reset_set(&set);
			exit(0);
		}
		tcsetattr(STDIN_FILENO, TCSANOW, &set.org_term);
		parse_input(input, env, envp);
		input = ft_free(input);
		reset_stdio(&set);
		ft_free_split(envp);
	}
	return (0);
}
