/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:23:06 by mplutarc          #+#    #+#             */
/*   Updated: 2019/11/29 16:14:07 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_ls	*init(void)
{
	t_ls	*new;

	if (!(new = (t_ls *)malloc(sizeof(t_ls))))
	    return (NULL);
	new->flag = 0;
	new->e_sum = 0;
	new->dh_index = 0;
	new->l = 0;
	new->i = 0;
	new->a = 0;
	new->t = 0;
	new->r = 0;
	new->big_r = 0;
	new->f_sum = 0;
	new->blocks = 0;
	new->ind = 0;
	return (new);
}

void    error(char *theDir)
{
	char	*myerror;

	myerror = ft_strjoin("Error opening ", ft_strjoin(theDir,
				ft_strjoin(": ", strerror(errno))));
	// myerror = ft_strcat(myerror, ": ");
	// myerror = ft_strcat(myerror, strerror(errno));
	ft_putendl(myerror);
    // ft_putstr("Error opening ");
    // ft_putstr(theDir);
    // ft_putstr(": ");
    // ft_putstr(strerror(errno));
    // ft_putstr("\n");
    //printf( "Error opening %s: %s", theDir, strerror(errno));
}

int		files(struct s_node *tree, char *theDir)
{
	DIR				*dir;
	struct dirent	*entry;

	dir = opendir(theDir); //открытие директории
	while((entry = readdir(dir)))  //пока директория читаема
	{
		if (entry->d_type == 8 && ft_strcmp(tree->field, entry->d_name) == 0)
		{
			closedir(dir);
			return (0);
		}
		// printf("Inode number: %llu\n filename: %s\n Type of file: [%d]\n Size: %d\n\n",
		// 			entry->d_ino, entry->d_name, entry->d_type, entry->d_reclen);
    }
	closedir(dir);
	return (ERROR);
}

int		directory(char *theDir, t_ls *ls)
{
    DIR				*dir;
    struct	dirent	*entry;
    struct	s_node	*sub_tree;
    char			*str;
    struct	stat	buf;

	dir = opendir(theDir); //открытие директории
	if (!dir)
	{
       	error(theDir);
       	return (0);
   	}
	sub_tree = NULL;
	str = (char *)malloc(sizeof(char) * (ft_strlen(theDir) + 2));
	str = ft_strcpy(str, theDir);
	ft_strcat(str, "/");
	while ((entry = readdir(dir)))  //пока директория читаема
	{
		lstat(ft_strjoin(str, entry->d_name), &buf);
		ls->sec = buf.st_mtimespec.tv_sec;
		if (ls->r == 1)
		{
			if (!(sub_tree = addnode_flag_r(ft_strjoin(str, entry->d_name), sub_tree, buf, ls)))
				return (ERROR);
		}
		else if (ls->t == 1)
		{
			if (!(sub_tree = addnode_flag_t(ft_strjoin(str, entry->d_name), sub_tree, buf, ls)))
				return (ERROR);
		}
		else if (!(sub_tree = addnode(ft_strjoin(str, entry->d_name), sub_tree, buf, ls)))
			return (ERROR);
	}
	ls->flag = 2;
	output(ls, sub_tree);
	closedir(dir);
	//free(entry);
	//ft_strclr(str);
//	free_tree(sub_tree, ls);
    return (0);
}

int		main(int ac, char **av)
{
	struct	stat	buf;
	int		i;
	int 	j;
	t_ls	*ls;

	i = 2;
	j = 1;
	if (!(ls = init()))
		return (ERROR);
	if (validation(ac, av, ls) == ERROR)
		return (ERROR);
	if (ac == 1 || (ft_strcmp(av[1], "--") == 0 && ac == 2) || ls->f_sum == ac - 1
		|| (ft_strcmp(av[ls->f_sum + 1], "--") == 0 && ac == ls->f_sum + 2))
	{
		directory(".", ls);
		return (0);
	}
	if (flags(ac, av, ls) == ERROR)
		return (ERROR);
	if (sorting(ac, av, ls, buf) == ERROR)
   		return (ERROR);
/*	while (i < ac)
	{
		if (i != ls->dh_index && i != ls->f_index[i])
		{
			if (!opendir(av[i]) && fopen(av[i], "rt"))
				files(av[i], ".");
			else if (i == ls->e_index[j])
				j++;
			else if (i != ls->e_index[j])
				directory(av[i]);
		}
	*//*	else if (ls->dh_index && i == ls->dh_index)
		{
			directory(av[i]);
		}*//*
		else if (i == ls->dh_index)
			j++;
		i++;
	}*/
	return (0);
}
