/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:23:13 by mplutarc          #+#    #+#             */
/*   Updated: 2019/10/21 20:29:07 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
# define FT_LS

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

typedef struct	s_flags
{
	int			l;
	int			i;
	int			a;
	int			t;
	int			r;
	int			big_r;
}				t_flags;

typedef struct s_ls
{
    t_flags     *flags;
    int         index;
}               t_ls;


#endif