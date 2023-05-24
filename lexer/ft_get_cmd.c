/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaktiwy <hsaktiwy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:07:28 by hsaktiwy          #+#    #+#             */
/*   Updated: 2023/05/24 14:12:46 by hsaktiwy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_cmd	*ini_cmd(t_env *env)
{
	t_cmd	*cmd;
	
	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->cmd = NULL;
	cmd->arg = NULL;
	cmd->cmd_type = -1;
	cmd->cmd_in = STDIN_FILENO;
	cmd->cmd_out = STDOUT_FILENO;\
	cmd->file_in = NULL;
	cmd->file_out = NULL;
	cmd->env = env;
	return (cmd);
}

int	is_splitable_env(char *str)
{
	int	i;

	i = 0;
	if(str[i] == '$')
		i++;
	else
		return (0);
	while (str[i] && (ft_isalnum(str[i])
		|| str[i] == '?' || str[i] == '_'))
		i++;
	if (str[i] == '\"' || str[i] == '\''
		|| str[i] == '$')
		return (0);
	else
		return (1);
}

t_cmd	*get_cmd(t_env *env, char *input, int *index)
{
	//int		i;
	t_cmd	*cmd;
	//int		stack;

	//i = 0;
	if (!input)
		return (NULL);
	cmd = ini_cmd(env);
	if(check_quotes_validity(input))
	{
		//stack = *index;
		if (input[0] && input[0] != '|')
		{
			cmd->cmd = get_simple_arg(env, input, index);
			if (input[0] == '$')
				cmd->cmd_type = VARIABLE;
			else
				cmd->cmd_type = WORD;
		}
		//i = (*index) - stack;
	}
	if (cmd->cmd == NULL)
		return (free(cmd), NULL);
	return (cmd);	
}