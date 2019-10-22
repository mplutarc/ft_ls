/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:23:06 by mplutarc          #+#    #+#             */
/*   Updated: 2019/10/22 14:25:37 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_ls	*init(void)
{
	t_ls	*new;

	new = (t_ls *)malloc(sizeof(t_ls));
	new->flags->l = 0;
	new->flags->i = 0;
	new->flags->a = 0;
	new->flags->t = 0;
	new->flags->r = 0;
	new->flags->big_r = 0;
	// new->index = 0;
	return (new);
}

int		files(char *av, char *theDir)
{
	DIR				*dir;
	struct dirent	*entry;

	dir = opendir(theDir); //открытие директории
	while((entry = readdir(dir)))  //пока директория читаема
	{
		if (entry->d_type == 8 && ft_strcmp(av, entry->d_name) == 0)
		{
			ft_putstr(entry->d_name);
			ft_putchar('\t');
		}
		// printf("Inode number: %llu\n filename: %s\n Type of file: [%d]\n Size: %d\n\n",
		// 			entry->d_ino, entry->d_name, entry->d_type, entry->d_reclen);
    }
	closedir(dir);
	return (0);
}

int		directory(char *theDir)
{
    DIR				*dir;
    struct	dirent	*entry;

	dir = opendir(theDir); //открытие директории
	if (!dir)
	{
       	printf( "Error opening %s: %s", theDir, strerror(errno));
       	return (0);
   	}
	while((entry = readdir(dir)))  //пока директория читаема
	{
		ft_putstr(entry->d_name);
		ft_putchar('\n');
		// printf("Inode number: %llu\n filename: %s\n Type of file: [%d]\n Size: %d\n\n",
		// 			entry->d_ino, entry->d_name, entry->d_type, entry->d_reclen);
    }
	closedir(dir);
    return (0);
}

int		main(int ac, char **av)
{
	int		i;
	t_ls	*ls;
	
	i = 1;
	if (ac == 1)
	{
		directory(".");
		return (0);
	}
	// ls = init();
	while (i < ac)
	{
		// if (av[i][0] == '-')
		// 	flags(av[i]);
		if (!opendir(av[i]))
		{
			files(av[i], ".");
			// ls->index = 1;
		}
		else
		{
			directory(av[i]);
			// ls->index = 1;
		}
		i++;
	}
	return (0);
}
