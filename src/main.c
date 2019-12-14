/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:23:06 by mplutarc          #+#    #+#             */
/*   Updated: 2019/12/14 12:29:18 by mplutarc         ###   ########.fr       */
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
	new->ind = 0;
	new->sec = 0;
	new->col = init_col();
	return (new);
}

void    error(char *theDir)
{
	char	*myerror;

	/*myerror = ft_strjoin("Error opening ", ft_strjoin(theDir,
				ft_strjoin(": ", strerror(errno))));
	// myerror = ft_strcat(myerror, ": ");
	// myerror = ft_strcat(myerror, strerror(errno));
	ft_putendl(myerror);
	free(myerror);*/
     ft_putstr("Error opening ");
     ft_putstr(theDir);
     ft_putstr(": ");
     ft_putstr(strerror(errno));
     ft_putstr("\n");
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
    char 			*tmp;

	ls->blocks = 0;
    dir = opendir(theDir); //открытие директории
	if (!dir)
	{
       	error(theDir);
       	return (0);
   	}
	sub_tree = NULL;
	str = (char *)ft_memalloc(sizeof(char) * (ft_strlen(theDir) + 2));
	str = ft_strcpy(str, theDir);
	ft_strcat(str, "/");
	while ((entry = readdir(dir)))  //пока директория читаема
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
				return(ERROR);
			}
		}
		else if (ls->r == 1)
		{
			if (!(sub_tree = addnode_flag_r(ft_strjoin(str, entry->d_name), sub_tree, buf, ls)))
			{
				closedir(dir);
				free(str);
				free_tree(sub_tree);
				return(ERROR);
			}
		}
		else if (!(sub_tree = addnode(ft_strjoin(str, entry->d_name), sub_tree, buf, ls)))
		{
			free_tree(sub_tree);
			free(str);
			closedir(dir);
			return(ERROR);
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
	int 		i;

	if (!(ls = init()))
		return (ERROR);
	if (validation(ac, av, ls) == ERROR)
	{
		free_ls(ls);
		return (ERROR);
	}
	if (ac == 1 || (ft_strcmp(av[1], "--") == 0 && ac == 2) || ls->f_sum == ac - 1
		|| (ft_strcmp(av[ls->f_sum + 1], "--") == 0 && ac == ls->f_sum + 2))
	{
		directory(".", ls);
		free_ls(ls);
		return (0);
	}
	i = 1;
	while (i < ac)
	{
		stat(av[i], &buf);
		i++;
	}
	if (flags(ac, av, ls) == ERROR)
	{
		free_ls(ls);
		return (ERROR);
	}
	if (sorting(ac, av, ls, buf) == ERROR)
	{
		free_ls(ls);
		return (ERROR);
	}
	free_ls(ls);
	return (0);
}
