/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 16:05:16 by emaveric          #+#    #+#             */
/*   Updated: 2019/12/24 16:18:04 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

struct s_node	*tree_create_p3(char *str, struct stat buf, t_ls *ls, struct s_node	*tree)
{
	tree->ino = buf.st_ino;
	tree->size = buf.st_size;
	tree->links = buf.st_nlink;
	if (ls->a == 1)
		ls->blocks += buf.st_blocks;
	else if (ft_strname(str, '/')[0] != '.')
		ls->blocks += buf.st_blocks;
	tree->sec = buf.st_mtimespec.tv_sec;
	return (tree);
}

struct s_node	*tree_create_p2(char *str, struct stat buf, t_ls *ls, struct s_node	*tree)
{
	char 			*tmp;

	tmp = NULL;
	if (tree->ind != 1 &&
	ft_strcmp(str, tmp = ft_strjoin("/Users/", ft_strname(str, '/'))) == 0)
		tree->ind = 2;
	if (tmp)
		free(tmp);
	tree->str_link = NULL;
	if (tree->mode[0] == 'l' && ls->l == 1)
	{
		if (!(tree->str_link = (char *)ft_memalloc(sizeof(char) *
				(buf.st_size + 1))))
			return (NULL);
		readlink(tree->field, tree->str_link, buf.st_size);
	}
	tree = tree_create_p3(str, buf, ls, tree);
	if (!(tree->time = ft_strdup(ctime((long int *)&buf.st_ctimespec))))
		return (NULL);
	tree->left = NULL;
	tree->right = NULL;
	return (tree);
}

struct s_node	*tree_create(char *str, struct stat buf, t_ls *ls)
{
	struct passwd	*pws;
	struct group	*grp;
	struct s_node	*tree;

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
	if (str[0] == '~' && str[1] == '\0')
	{
		tree->ind = 1;
		if (!(tree->field = ft_strjoin("/Users/", pws->pw_name)))
			return (NULL);
	}
	else
		tree->field = str;
	if (!(tree = tree_create_p2(str, buf, ls, tree)))
		return (NULL);
	return (tree);
}