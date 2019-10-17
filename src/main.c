/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:23:06 by mplutarc          #+#    #+#             */
/*   Updated: 2019/10/17 17:55:18 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		flags(t_ls *ls, char *av, struct dirent *entry)
{
	if((ls->flag = ft_strchr(av, 'i')))
		printf("Inode number: %llu\n\n ", entry->d_ino);
}

unsigned	directory(char *av, char *theDir)
{
    DIR		*dir;
    struct	dirent *entry;
	int		i;
	t_ls	*ls;

	dir = opendir(theDir); //открытие директории
	i = 0;
	while((entry = readdir(dir)))  //пока директория читаема, но почему-то оно прочитывает его по второму кругу, разберёшься, почему?
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
		// printf("im alive\n");
		if(av)
			flags(ls, av, entry);
    }
	// inode number == ls -i
	closedir(dir);
		printf("sega isn't here\n");
    return (0);
}

int			main(int ac, char **av)
{
	if(ac > 3)
		return (0);
	directory(av[1], ".");
	return (0);
}
