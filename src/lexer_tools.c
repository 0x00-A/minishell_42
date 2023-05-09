/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:46:31 by hsaktiwy          #+#    #+#             */
/*   Updated: 2023/05/09 15:17:19 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

void	handleCommand(t_list **tokens, t_env *env,char *input, int *index)
{
	t_token *token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		return;
	token->type = COMMAND;
	token->value = get_cmd(env, &input[*index], index);
	ft_lstadd_back(tokens, ft_lstnew(token));
}

void	handleArg(t_list **tokens, t_env *env, char *input, int *index)
{
	t_token	*cmd;
	t_token	*tmp;
	t_list	*list;
	t_list	*node;

	cmd = NULL;
	list = *tokens;
	while (list)
	{
		tmp = list->content;
		if( tmp->type == COMMAND)
			cmd = tmp;
		list = list->next;
	}
	if (input[*index] == '$')
	{
		node = ft_lstnew(creat_arg(get_simple_arg(env, &input[*index], index), VARIABLE));
	}
	else
	{
		node = ft_lstnew(creat_arg(get_simple_arg(env, &input[*index], index), WORD));
	}
	ft_lstadd_back(&(((t_cmd *)cmd->value)->arg), node);
}

void	ini_count(t_token **token)
{
	t_cmd	*cmd;
	t_list	*current;
	t_file	*arg;

	cmd = (*token)->value;
	cmd->arg_count = 0;
	current = cmd->arg;

	while (current)
	{
		arg = current->content;
		if (ft_strlen(arg->a_file))
			cmd->arg_count++;
		current = current->next;
	}
}

void	ini_arg_count(t_list **tokens)
{
	t_list	*current;
	t_token	*token;

	current = *tokens;
	while (current)
	{
		token = current->content;
		if (token->type == COMMAND)
			ini_count(&token);
		current = current->next;
	}
}