/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:23:06 by mplutarc          #+#    #+#             */
/*   Updated: 2019/10/17 18:36:01 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			flags(t_ls *ls, char *av, struct dirent *entry)
{
	// inode number == ls -i
	if((ls->flag = ft_strchr(av, 'i')))
		printf("Inode number: %llu\n\n ", entry->d_ino);
	return(0);
}

unsigned	directory(char *av, char *theDir)
{
    DIR		*dir;
    struct	dirent *entry;
	int		i;
	t_ls	*ls;

	dir = opendir(theDir); //открытие директории
	i = 0;
	while((entry = readdir(dir)))  //пока директория читаема
	{
		i++;
		if (!dir)
		{
        	printf( "Error opening %s: %s", theDir, strerror(errno));
        	return 0;
    	}
		printf("%s\n", entry->d_name);
		// printf("Inode number: %llu\n filename: %s\n Type of file: [%d]\n Length of this record: %d\n\n",
					// entry->d_ino, entry->d_name, entry->d_type, entry->d_reclen);
		if(av)
			flags(ls, av, entry);
    }
	closedir(dir);
    return (0);
}

int			main(int ac, char **av)
{
	if(ac > 3 || ft_strlen(av[1]) == 1 || ft_strlen(av[1]) >= 10)
		return (0);
	directory(av[1], ".");
	return (0);
}
