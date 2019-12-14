/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:23:13 by mplutarc          #+#    #+#             */
/*   Updated: 2019/12/14 15:25:58 by emaveric         ###   ########.fr       */
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
# include <time.h>
# include <grp.h>
# include <dirent.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct		s_column
{
	int				link;
	int				size;
	char			*str_link;
	char			*str_size;
}					t_column;

struct				s_node
{
	int				ino;
	int				size;
	int				links;
	char			*uid;
	char			*gid;
	char			*mode;
	int				flag;
	char			*time;
	long int		sec;
	char			*field; // поле данных
	struct s_node	*left;  // левый потомок
	struct s_node	*right; // правый потомок
};

typedef struct		s_ls
{
	int				l;
	int				i;
	int				a;
	int				t;
	int				r;
	int				big_r;
    int				flag;
    int 			ind;
    long int		sec;
	int 			blocks;
    int 			f_sum;
    int 			dh_index; //индекс для --
    int 			*f_index; // индекс для флагов
	char 			**c_dir; // for "."
	t_column		*col;
}					t_ls;

int					files(struct s_node *tree, char *theDir);
int					directory(char *theDir, t_ls *ls);
int					main(int ac, char **av);
int					validation(int ac, char **av, t_ls *ls);
int 				flags(int ac, char **av, t_ls *ls);
int 				sorting(int ac, char **av, t_ls *ls, struct stat buf);
int					dhyp_check(int ac, char **av, t_ls *ls);
int					cur_dir(char *theDir, t_ls *ls);
void				print(struct s_node *tree, t_ls *ls);
void				e_print(struct s_node *tree, t_ls *ls);
int					output(t_ls *ls, struct s_node *tree);
void				find_flag(t_ls *ls, char **av, int i);
struct s_node		*addnode(char *str, struct s_node *tree, struct stat buf,
							t_ls *ls);
void				big_r_flag_print(struct s_node *tree, t_ls *ls);
struct s_node		*addnode_flag_r(char *str, struct s_node *tree,
									struct stat buf, t_ls *ls);
void				l_flag_print(struct s_node *tree, t_ls *ls);
void    			i_flag_print(struct s_node *tree, t_ls *ls);
void				a_flag_print(struct s_node *tree, t_ls *ls);
int					mode_to_rwx(struct s_node *tree, struct stat buf);
struct s_node		*tree_create(char *str, struct stat buf, t_ls *ls);
struct s_node		*addnode_flag_t(char *str, struct s_node *tree,
									struct stat buf, t_ls *ls);
void				last_dir_check(struct s_node *tree, t_ls *ls);
void				free_tree(struct s_node *tree);
void				free_ls(t_ls *ls);
void				free_first_tree(struct s_node *tree);
void				into_string(struct s_node *tree, t_ls *ls);
t_column			*init_col(void);
t_ls				*max_str(struct s_node *tree, t_ls *ls);
t_ls				*itostr(struct s_node *tree, t_ls *ls);

#endif
