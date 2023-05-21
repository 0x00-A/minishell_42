/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:17:19 by hsaktiwy          #+#    #+#             */
/*   Updated: 2023/05/21 10:18:31 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	g_heredoc_executing(int i)
{
	static int	j;
	if (i == -1)
		return (j);
	j = i;
	return (j);
}

int	find_delimeter(char *line, char *needle)
{
	int	i;

	i = 0;
	while (line[i] && needle[i] && needle[i] == line[i])
		i++;
	if (line[i] == '\0' && !needle[i])
		return (1);
	return (0);
}

int	in_redirection(t_file *tmp)
{
	int fd;

	fd = -1;
	if (tmp->a_file)
	{
		// fd = open(tmp->a_file, O_WRONLY, 0777);
		fd = open(tmp->a_file, O_RDONLY, 0777);
		if (fd == -1)
			print_error(NULL, tmp->a_file, 1);
	}
	return (fd);
}

int	heredoc(t_env *env, char *delimiter, int h_fd)
{
	char	*line;
	char	*tmp;

	while (1)
	{
		g_heredoc_executing(1);
		line = readline("> ");
		if (g_heredoc_executing(-1) && line)
		{
			tmp = expand(env, line);
			if (!find_delimeter(tmp, delimiter) && g_heredoc_executing(-1))
			{
				if (write(h_fd, tmp, ft_strlen(tmp)) == -1)
					return (g_heredoc_executing(0), free(tmp), free(line), 0);
			}
			else
			{
				return (g_heredoc_executing(0), free(tmp), free(line), close(h_fd), 1);
			}
			free(line);
			free(tmp);
			line = NULL;
		}
		else
			return (g_heredoc_executing(0), free(line), 1);
	}
}

int	here_doc_red(t_env *env, t_file *tmp)
{
	int	fd;

	fd = -1;
	if(tmp->a_file)
	{
		// printf(">>>> ? : %s\n",tmp->a_file);
		fd = open(".here_doc", O_RDWR | O_CREAT | O_TRUNC, 0666);
		if (fd == -1)
			print_error(NULL, ".here_doc", 1);
		else if (!heredoc(env, tmp->a_file, fd))
		{
			fd = -1;
			write(2, "Error : here_doc fail\n", 22);
		}
	}
	return (fd);		
}

int out_append_red(t_file *tmp, int out_app)
{
	int fd;

	fd = -1;
	if (tmp->a_file)
	{
		if (out_app == OUT_REDIRECT)
		{
			if (ft_strlen(tmp->a_file) != 0)
				fd = open(tmp->a_file, O_RDWR | O_CREAT | O_TRUNC, 0644);
		}
		else if (out_app == APPEND_REDIRECT)
		{
			if (ft_strlen(tmp->a_file) != 0)
				fd = open(tmp->a_file, O_RDWR | O_CREAT | O_APPEND, 0644);
		}
		if (fd == -1)
			print_error(NULL, tmp->a_file, 1);
	}
	return (fd);
}
