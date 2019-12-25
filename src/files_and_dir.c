/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_and_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 13:23:56 by emaveric          #+#    #+#             */
/*   Updated: 2019/12/25 15:55:35 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int				files(char *str, char *the_dir)
{
	DIR				*dir;
	struct dirent	*entry;

	dir = opendir(the_dir);
	while ((entry = readdir(dir)))
	{
		if (ft_strcmp(str, entry->d_name) == 0)
		{
			closedir(dir);
			return (0);
		}
	}
	closedir(dir);
	return (ERROR);
}

struct s_node	*directory_p3(t_ls *ls, char *str,
		struct stat buf, struct s_node *sub_tree)
{
	if (ls->t == 1)
	{
		if (!(sub_tree = addnode_flag_t(str, sub_tree, buf, ls)))
		{
			free_tree(sub_tree);
			return (NULL);
		}
	}
	else if (ls->r == 1)
	{
		if (!(sub_tree = addnode_flag_r(str, sub_tree, buf, ls)))
		{
			free_tree(sub_tree);
			return (NULL);
		}
	}
	else if (!(sub_tree = addnode(str, sub_tree, buf, ls)))
	{
		free_tree(sub_tree);
		return (NULL);
	}
	return (sub_tree);
}

struct s_node	*directory_p2(DIR *dir, t_ls *ls,
		struct s_node *sub_tree, char *the_dir)
{
	char			*tmp;
	char			*str;
	struct dirent	*entry;
	struct stat		buf;

	tmp = NULL;
	str = (char *)ft_memalloc(sizeof(char) * (ft_strlen(the_dir) + 2));
	str = ft_strcpy(str, the_dir);
	ft_strcat(str, "/");
	while ((entry = readdir(dir)))
	{
		lstat(tmp = ft_strjoin(str, entry->d_name), &buf);
		free(tmp);
		tmp = ft_strjoin(str, entry->d_name);
		ls->sec = buf.st_mtimespec.tv_sec;
		if (!(sub_tree = directory_p3(ls, tmp, buf, sub_tree)))
		{
			free(tmp);
			free(str);
			closedir(dir);
			return (NULL);
		}
	}
	free(str);
	return (sub_tree);
}

int				directory(char *the_dir, t_ls *ls)
{
	DIR				*dir;
	struct s_node	*sub_tree;

	ls->blocks = 0;
	dir = opendir(the_dir);
	if (!dir)
	{
		ft_error(the_dir);
		return (0);
	}
	sub_tree = NULL;
	if (!(sub_tree = directory_p2(dir, ls, sub_tree, the_dir)))
	{
		closedir(dir);
		return (ERROR);
	}
	ls->flag = 2;
	closedir(dir);
	output(ls, sub_tree);
	free_tree(sub_tree);
	return (0);
}
