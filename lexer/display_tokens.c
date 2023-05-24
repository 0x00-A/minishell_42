/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaktiwy <hsaktiwy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:07:11 by hsaktiwy          #+#    #+#             */
/*   Updated: 2023/05/24 14:26:17 by hsaktiwy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_tokens(t_list	*tokens)
{
	t_list	*list;

	list = tokens;
	printf("Displaying a tokens (list) : \n");
	while (list)
	{
		t_token *token;

		token = list->content;
		if (token->type == IN_REDIRECT)
		{
			printf("	type : <\n");
			printf("		Data : %s\n", ((t_file *)token->value)->a_file);
			printf("		Old_data : %s\n", ((t_file *)token->value)->token_file);
		}
		if (token->type == OUT_REDIRECT)
		{
			printf("	type : >\n");
			printf("		Data : %s\n", ((t_file *)token->value)->a_file);
			printf("		Old_data : %s\n", ((t_file *)token->value)->token_file);
		}
		if (token->type == HERE_DOC)
		{
			printf("	type : <<\n");
			printf("		Data : %s\n", ((t_file *)token->value)->a_file);
			printf("		Old_data : %s\n", ((t_file *)token->value)->token_file);
		}
		if (token->type == APPEND_REDIRECT)
		{
			printf("	type : >>\n");
			printf("		Data : %s\n", ((t_file *)token->value)->a_file);
			printf("		Old_data : %s\n", ((t_file *)token->value)->token_file);
		}
		if (token->type == PIPE)
		{
			printf("	type : |\n");
			printf("		Data : %p\n", token->value);
		}
		if (token->type == COMMAND)
		{
			printf("	type : COMMOND\n");
			printf("		CMD : |%s|\n", ((t_cmd *)token->value)->cmd);
			t_list 	*arg = ((t_cmd *)token->value)->arg;
			printf("	CMD type cmd(token) = %d\n", ((t_cmd *)(token->value))->cmd_type);
			printf("	CMD count arg = %zu\n", ((t_cmd *)(token->value))->arg_count);
			printf("		Data :");
			while (arg)
			{
				printf("|%s|->[%d]",(char *)((t_file *)arg->content)->a_file,
					(int)((t_file *)arg->content)->arg_type);
				arg = arg->next;
			}
			printf("\n");
			printf("		cmd_in : %d\n", ((t_cmd *)token->value)->cmd_in);
			printf("		cmd_out : %d\n", ((t_cmd *)token->value)->cmd_out);
			printf("		file_in : %s\n", ((t_cmd *)token->value)->file_in);
			printf("		file_out : %s\n", ((t_cmd *)token->value)->file_out);
		}
		list = list->next;
	}
}