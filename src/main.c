/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:23:06 by mplutarc          #+#    #+#             */
/*   Updated: 2019/10/14 17:17:18 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

unsigned directory(char *theDir)
{
    DIR		*dir;
    struct	dirent *entry;
	int		i = 0;

	dir = opendir(theDir); //открытие директории
	while((entry = readdir(dir)))  //пока директория читаема, но почему-то оно прочитывает его по второму кругу, разберёшься, почему?
	{
		i++;
		if (!dir)
		{
        	printf( "Error opening %s: %s", theDir, strerror(errno));
        	return 0;
    	}
		printf("i = %d\t %s\n", i, entry->d_name);
		// printf("d_ino: %llu\t name: %s\t type: [%d]\t reclen: %d\n", entry->d_ino, entry->d_name, entry->d_type, entry->d_reclen);
    }
	closedir(dir);
    return (0);
}

int		main()
{
	directory(".");
	return (0);
}
