/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:23:06 by mplutarc          #+#    #+#             */
/*   Updated: 2019/11/06 18:05:47 by emaveric         ###   ########.fr       */
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
			printf("\n");
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
		//printf("theDir is %s\n", theDir);
       	error(theDir);
       	return (0);
   	}
	while ((entry = readdir(dir)))  //пока директория читаема
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
	int 	j;
	t_ls	*ls;

	i = 1;
	j = 1;
	if (!(ls = init()))
		return (ERROR);
	if (ac == 1 || (ft_strcmp(av[1], "--") == 0 && ac == 2))
	{
	//	sorting(ac, av);
		//directory(".");
		cur_dir(".", ls);
		return (0);
	}
	if (dhyp_check(ac, av, ls) == ERROR)
		return (ERROR); //посмотреть ошибку ориг лс если ввести 3 --- и тп
	if (flags(ac, av, ls) == ERROR)
		return (ERROR);
	if (dhyp_check(ac, av, ls) == ERROR)
		return (ERROR); //посмотреть ошибку ориг лс если ввести 3 --- и тп
	if (validation(ac, av, ls) == ERROR)
		return (ERROR);
	printf("\n\n\n");
	if (sorting(ac, av) == ERROR)
   		return (ERROR);
	printf ("\n\n\n\n");
	while (i < ac)
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
	/*	else if (ls->dh_index && i == ls->dh_index)
		{
			directory(av[i]);
		}*/
		else if (i == ls->dh_index)
			j++;
		i++;
	}
	return (0);
}
