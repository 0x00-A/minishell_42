/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaktiwy <hsaktiwy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:07:39 by hsaktiwy          #+#    #+#             */
/*   Updated: 2023/05/31 15:59:40 by hsaktiwy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_exp_edge(char	**points, char *string, char *exp, int i)
{
	int		corr;
	char	*tmp;

	corr = 1;
	if (!points[i] && exp[0] != '*')
	{
		tmp = strstr(string, points[0]);
		if (string < tmp)
			corr = 0;
	}
	if (!points[i] && !isendwith(exp) && corr)
	{
		tmp = string;
		while (strstr(&tmp[1], points[i - 1]))
			tmp = strstr(&tmp[1], points[i - 1]);
		tmp = &tmp[ft_strlen(points[i - 1])];
		if (*tmp)
			corr = 0;
	}
	return (corr);
}

int	ft_regx(char *string, char *exp)
{
	char	**points;
	char	*tmp;
	int		i;
	int		corr;

	corr = 1;
	tmp = string;
	points = ft_split(exp, '*');
	i = -1;
	while (tmp && *tmp && points[++i])
		tmp = strstr(tmp, points[i]);
	if (!tmp)
		return (0);
	corr = check_exp_edge(points, string, exp, i);
	return (fre_tab(points), corr);
}

char	*add_matchs(struct dirent *entry, char *arg, char	*tmp, int *i)
{
	char	*res;

	res = arg;
	if (entry && entry->d_name[0] != '.')
	{
		if (ft_regx(entry->d_name, tmp))
		{
			res = str_join(res, ft_strdup(" "));
			res = str_join(res, ft_strdup(entry->d_name));
			(*i)++;
		}
	}
	return (res);
}

char	*local_dir(char *arg, char *tmp)
{
	char			*res;
	DIR				*dir;
	struct dirent	*entry;
	int				i;

	i = 0;
	res = arg;
	dir = opendir(".");
	if (dir)
	{
		entry = readdir(dir);
		while (entry)
		{	
			res = add_matchs(entry, res, tmp, &i);
			entry = readdir(dir);
		}
		closedir(dir);
	}
	if (i == 0)
	{
		res = str_join(res, ft_strdup(" "));
		res = str_join(res, ft_strdup(tmp));
	}
	return (res);
}

char	*add_wildcards_to_input(char *input, char *tmp)
{
	char	*res;
	char	**tab;
	int		i;

	i = -1;
	res = input;
	if (str_iswhitespaced(tmp))
	{
		tab = ft_split(tmp, ' ');
		while (tab[++i])
		{
			if (ft_strchr(tab[i], '*'))
				res = local_dir(res, tab[i]);
			else
			{
				res = str_join(res, ft_strdup(" "));
				res = str_join(res, ft_strdup(tab[i]));
			}
		}
		fre_tab(tab);
	}
	else
		res = local_dir(res, tmp);
	return (res);
}