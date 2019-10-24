/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:23:13 by mplutarc          #+#    #+#             */
/*   Updated: 2019/10/24 20:17:16 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
# define FT_LS
# define ERROR -1

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <dirent.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <limits.h>
# include "../libft/libft.h"


typedef struct s_ls
{
	int			l;
	int			i;
	int			a;
	int			t;
	int			r;
	int			big_r;
    int         flag;
    int 		e_sum;
    int 		*e_index; // индекс для ошибок
    int 		dh_index; //индекс для --
    int 		*f_index; // индекс для флагов
}               t_ls;

int 	directory(char *theDir);
int		main(int ac, char **av);
int     validation(int ac, char **av, t_ls *ls);
int 	dhyp_check(int ac, char **av, t_ls *ls);
int 	flags(int ac, char **av, t_ls *ls);

#endif