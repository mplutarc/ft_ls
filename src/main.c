/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:23:06 by mplutarc          #+#    #+#             */
/*   Updated: 2019/12/23 15:06:38 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_ls	*init(void)
{
	t_ls	*new;

	if (!(new = (t_ls *)malloc(sizeof(t_ls))))
		return (NULL);
	new->flag = 0;
	new->dh_index = 0;
	new->l = 0;
	new->i = 0;
	new->a = 0;
	new->t = 0;
	new->r = 0;
	new->big_r = 0;
	new->f_sum = 0;
	new->sec = 0;
	new->point = 0;
	new->col = init_col();
	new->f_index = NULL;
	return (new);
}

void	error(char *the_dir)
{
	ft_putstr("Error opening ");
	ft_putstr(the_dir);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
}

int		files(struct s_node *tree, char *the_dir)
{
	DIR				*dir;
	struct dirent	*entry;

	dir = opendir(the_dir);
	while ((entry = readdir(dir)))
	{
		if (ft_strcmp(tree->field, entry->d_name) == 0)
		{
			closedir(dir);
			return (0);
		}
	}
	closedir(dir);
	return (ERROR);
}

int		directory(char *the_dir, t_ls *ls)
{
	DIR				*dir;
	struct dirent	*entry;
	struct s_node	*sub_tree;
	char			*str;
	struct stat	buf;
	char			*tmp;

	ls->blocks = 0;
	dir = opendir(the_dir);
	if (!dir)
	{
		error(the_dir);
		return (0);
	}
	sub_tree = NULL;
	str = (char *)ft_memalloc(sizeof(char) * (ft_strlen(the_dir) + 2));
	str = ft_strcpy(str, the_dir);
	ft_strcat(str, "/");
	while ((entry = readdir(dir)))
	{
		lstat(tmp = ft_strjoin(str, entry->d_name), &buf);
		free(tmp);
		ls->sec = buf.st_mtimespec.tv_sec;
		if (ls->t == 1)
		{
			if (!(sub_tree = addnode_flag_t(ft_strjoin(str, entry->d_name), sub_tree, buf, ls)))
			{
				free_tree(sub_tree);
				closedir(dir);
				free(str);
				return (ERROR);
			}
		}
		else if (ls->r == 1)
		{
			if (!(sub_tree = addnode_flag_r(ft_strjoin(str, entry->d_name), sub_tree, buf, ls)))
			{
				closedir(dir);
				free(str);
				free_tree(sub_tree);
				return (ERROR);
			}
		}
		else if (!(sub_tree = addnode(ft_strjoin(str, entry->d_name), sub_tree, buf, ls)))
		{
			free_tree(sub_tree);
			free(str);
			closedir(dir);
			return (ERROR);
		}
	}
	ls->flag = 2;
	closedir(dir);
	output(ls, sub_tree);
	free(str);
	free_tree(sub_tree);
	return (0);
}

int		main(int ac, char **av)
{
	struct stat buf;
	t_ls		*ls;
	int			i;

	if (!(ls = init()))
		return (ERROR);
	if (validation(ac, av, ls) == ERROR)
	{
		free_ls(ls);
		return (ERROR);
	}
	ls->ac = ac - ls->f_sum - 1;
	if (ac == 1 || (ft_strcmp(av[1], "--") == 0 && ac == 2) || ls->f_sum == ac - 1
		|| (ft_strcmp(av[ls->f_sum + 1], "--") == 0 && ac == ls->f_sum + 2))
	{
		directory(".", ls);
		if (ls->l != 1 || ls->f_sum == 0)
			ft_putchar('\n');
		free_ls(ls);
		return (0);
	}
	i = 0;
	while (i < ac)
	{
		stat(av[i], &buf);
		i++;
	}
	if (sorting(ac, av, ls, buf) == ERROR)
	{
		free_ls(ls);
		return (ERROR);
	}
	if (ls->l != 1 || ls->f_sum == 0)
		ft_putchar('\n');
	free_ls(ls);
	return (0);
}
