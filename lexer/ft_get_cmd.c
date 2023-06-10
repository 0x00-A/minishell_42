/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaktiwy <hsaktiwy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:07:28 by hsaktiwy          #+#    #+#             */
/*   Updated: 2023/06/10 19:00:22 by hsaktiwy         ###   ########.fr       */
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
	cmd->cmd_in = STDIN_FILENO;
	cmd->cmd_out = STDOUT_FILENO;
	cmd->file_in = NULL;
	cmd->file_out = NULL;
	cmd->env = env;
	cmd->error = 0;
	return (cmd);
}

// int	is_splitable_env(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] && !iswhitespace(str[i]))
// 	{
// 		if (str[i] == '$')
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }
