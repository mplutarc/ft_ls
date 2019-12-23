/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:11:20 by emaveric          #+#    #+#             */
/*   Updated: 2019/12/23 21:43:15 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int				mode_to_rwx(struct s_node *tree, struct stat buf)
{
	int		i;

	i = 0;
	if (!(tree->mode = (char *)ft_memalloc(sizeof(char) * 11)))
		return (ERROR);
	if ((buf.st_mode & S_IFLNK) == 40960)
		tree->mode[i] = 'l';
	else
		tree->mode[i] = (S_ISDIR((unsigned short int)buf.st_mode) ? 'd' : '-');
	i++;
	tree->mode[i++] = ((buf.st_mode & S_IRUSR) ? 'r' : '-');
	tree->mode[i++] = ((buf.st_mode & S_IWUSR) ? 'w' : '-');
	tree->mode[i++] = ((buf.st_mode & S_IXUSR) ? 'x' : '-');
	tree->mode[i++] = ((buf.st_mode & S_IRGRP) ? 'r' : '-');
	tree->mode[i++] = ((buf.st_mode & S_IWGRP) ? 'w' : '-');
	tree->mode[i++] = ((buf.st_mode & S_IXGRP) ? 'x' : '-');
	tree->mode[i++] = ((buf.st_mode & S_IROTH) ? 'r' : '-');
	tree->mode[i++] = ((buf.st_mode & S_IWOTH) ? 'w' : '-');
	tree->mode[i++] = ((buf.st_mode & S_IXOTH) ? 'x' : '-');
	tree->mode[i] = '\0';
	return (0);
}

struct s_node	*tree_create(char *str, struct stat buf, t_ls *ls)
{
	struct passwd	*pws;
	struct group	*grp;
	struct s_node	*tree;
	char 			*tmp;

	if (!(tree = (struct s_node *) malloc(sizeof(struct s_node))))
		return (NULL);
	if (mode_to_rwx(tree, buf) == ERROR)
		return (NULL);
	pws = getpwuid(buf.st_uid);
	grp = getgrgid(buf.st_gid);
	if (pws != NULL)
		tree->uid = ft_strdup(pws->pw_name);
	if (grp != NULL)
		tree->gid = ft_strdup(grp->gr_name);
	tree->ind = 0;
	if (str[0] == '~')
	{
		tree->ind = 1;
		if (!(tree->field = ft_strjoin("/Users/", pws->pw_name)))
			return (NULL);
	}
	else
		tree->field = str;
	if (ft_strcmp(tree->field, tmp = ft_strjoin("/Users/", tree->uid)))
		tree->mode[0] = 'q';
	free(tmp);
	if (tree->mode[0] == 'l' && ls->l == 1)
	{
		if (!(tree->str_link = (char *)ft_memalloc(sizeof(char) * (buf.st_size + 1))))
			return (NULL);
		readlink(tree->field, tree->str_link, buf.st_size);
	}
	tree->ino = buf.st_ino;
	tree->size = buf.st_size;
	tree->links = buf.st_nlink;
	if (ls->a == 1)
		ls->blocks += buf.st_blocks;
	else if (ft_strname(str, '/')[0] != '.')
		ls->blocks += buf.st_blocks;
	tree->sec = buf.st_mtimespec.tv_sec;
	if (!(tree->time = ft_strdup(ctime((long int *)&buf.st_ctimespec))))
		return (NULL);
	tree->left = NULL;
	tree->right = NULL;
	return (tree);
}

struct s_node	*addnode(char *str, struct s_node *tree, struct stat buf, t_ls *ls)
{
	if (tree == NULL)
	{
		if (!(tree = tree_create(str, buf, ls)))
		{
			free_tree(tree);
			return (NULL);
		}
		tree->flag = 0;
		if (ft_strcmp(ft_strname(tree->field, '/'), ".") == 0 ||
			ft_strcmp(ft_strname(tree->field, '/'), "..") == 0)
			tree->flag = 1;
	}
	else
	{
		if (ft_strcmp(str, tree->field) < 0)
			tree->left = addnode(str, tree->left, buf, ls);
		else
			tree->right = addnode(str, tree->right, buf, ls);
	}
	return (tree);
}

int				sorting(int ac, char **av, t_ls *ls, struct stat buf)
{
	struct s_node	*tree;
	struct s_node	*sub_tree;
	int				i;

	i = 1;
	tree = NULL;
	sub_tree = NULL;
	while (i < ac)
	{
		if (sub_tree == NULL)
			sub_tree = tree;
		if ((ls->f_sum < i || i != ls->f_index[i]) && i != ls->dh_index)
		{
			if (ls->t == 1)
			{
				if (!(tree = addnode_flag_t(av[i], tree, buf, ls)))
				{
					free_tree(sub_tree);
					return (ERROR);
				}
			}
			else if (ls->r == 1)
			{
				if (!(tree = addnode_flag_r(av[i], tree, buf, ls)))
				{
					free_tree(sub_tree);
					return (ERROR);
				}
			}
			else if (!(tree = addnode(av[i], tree, buf, ls)))
			{
				free_tree(sub_tree);
				return (ERROR);
			}
		}
		i++;
	}
	output(ls, tree);
	free_first_tree(tree);
	free_tree(tree);
	return (0);
}
