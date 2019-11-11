/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:23:13 by mplutarc          #+#    #+#             */
/*   Updated: 2019/11/09 18:49:19 by emaveric         ###   ########.fr       */
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

struct				s_node
{
	int 			type;
	char			*field; // поле данных
	struct s_node	*left;  // левый потомок
	struct s_node	*right; // правый потомок
};

typedef struct		s_ls
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
	char 		**c_dir; // for "."
}               t_ls;

int 			directory(char *theDir, t_ls *ls);
int				main(int ac, char **av);
int				validation(int ac, char **av, t_ls *ls);
int 			dhyp_check(int ac, char **av, t_ls *ls);
int 			flags(int ac, char **av, t_ls *ls);
int 			sorting(int ac, char **av, t_ls *ls);
int 			cur_dir(char *theDir, t_ls *ls);
void			print(struct s_node *tree, t_ls *ls);
void			e_print(struct s_node *tree, t_ls *ls);
int 			output(t_ls *ls, struct s_node *tree);
void			find_flag(t_ls *ls, char **av, int i);
void			find_flag2(t_ls *ls, char **av, int i);
struct s_node	*addnode(char *str, struct s_node *tree);
void 			print_without_err(struct s_node *tree, t_ls *ls);

#endif
