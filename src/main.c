/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:23:06 by mplutarc          #+#    #+#             */
/*   Updated: 2019/10/22 16:30:44 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_ls	*init(void)
{
	t_ls	*new;

	new = (t_ls *)malloc(sizeof(t_ls));
	new->l = 0;
	new->i = 0;
	new->a = 0;
	new->t = 0;
	new->r = 0;
	new->big_r = 0;
	// new->index = 0;
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
		printf("theDir is %s\n", theDir);
       	error(theDir);
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
	
	if (!(ls = (t_ls *)malloc(sizeof(t_ls))))
	    return (-1);
	i = 1;
	if (ac == 1)
	{
		directory(".");
		return (0);
	}
	while (i < ac)
    {
        if (av[i][0] != '-')
            ls->index = 1;
        else if (av[i][0] == '-' && ls->index == 1)
		{
			printf("i = %d, ls index = %d\n", i, ls->index);
            //error(av[i]);
			directory(av[i]);
			av[i][1] = '\0';
		}
        i++;
    }
	i = 1;
	ls = init();
	while (i < ac)
	{
		//(av[i]);
		if (!opendir(av[i]) && fopen(av[i], "rt"))
		{
			files(av[i], ".");
		}
		else if (av)
		{
			directory(av[i]);
		}
		i++;
	}
	return (0);
}
