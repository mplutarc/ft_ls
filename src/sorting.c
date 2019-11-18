/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:11:20 by emaveric          #+#    #+#             */
/*   Updated: 2019/11/18 20:58:00 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			mode_to_rwx(struct s_node *tree, struct stat buf)
{
	int		i;

	i = 0;
	tree->mode = (char *)malloc(sizeof(char) * 11);
	tree->mode[i++] = (S_ISDIR((unsigned short int)buf.st_mode) ? 'd' : '-');
	tree->mode[i++] = ((buf.st_mode & S_IRUSR) ? 'r' : '-');
	tree->mode[i++] = ((buf.st_mode & S_IWUSR) ? 'w' : '-');
	tree->mode[i++] = ((buf.st_mode & S_IXUSR) ? 'x' : '-');
	tree->mode[i++] = ((buf.st_mode & S_IRGRP) ? 'r' : '-');
	tree->mode[i++] = ((buf.st_mode & S_IWGRP) ? 'w' : '-');
	tree->mode[i++] = ((buf.st_mode & S_IXGRP) ? 'x' : '-');
	tree->mode[i++] = ((buf.st_mode & S_IROTH) ? 'r' : '-');
	tree->mode[i++] = ((buf.st_mode & S_IWOTH) ? 'w' : '-');
	tree->mode[i++] = ((buf.st_mode & S_IXOTH) ? 'x' : '-');
}

struct s_node	*addnode(char *str, struct s_node *tree, struct stat buf)
{
	struct passwd	*pws;
	struct group	*grp;

	if (tree == NULL)     // Если дерева нет, то формируем корень
	{
		if (!(tree = (struct s_node *)malloc(sizeof(struct s_node))))
			return (NULL);
		mode_to_rwx(tree, buf);
		pws = getpwuid(buf.st_uid);
		grp = getgrgid(buf.st_gid);
		if (pws != NULL)
			tree->uid = ft_strdup(pws->pw_name);
		if (grp != NULL)
			tree->gid = ft_strdup(grp->gr_name);
		tree->ino = buf.st_ino;
		tree->size = buf.st_size;
		tree->links = buf.st_nlink;
		tree->field = str;   //поле данных
		tree->left = NULL;
		tree->right = NULL; //ветви инициализируем пустотой
	}
	else     // иначе
	{
		if (ft_strcmp(str, tree->field) < 0)   //Если элемент str меньше корневого, уходим влево
			tree->left = addnode(str, tree->left, buf); //Рекурсивно добавляем элемент
		else  //иначе уходим вправо
			tree->right = addnode(str, tree->right, buf); //Рекурсивно добавляем элемент
	}
	return (tree);
}

struct s_node	*addnode_flag_r(char *str, struct s_node *tree, struct stat buf)
{
	if (tree == NULL)     // Если дерева нет, то формируем корень
	{
		if (!(tree = (struct s_node *)malloc(sizeof(struct s_node))))
			return (NULL);
		tree->field = str;   //поле данных
		tree->ino = buf.st_ino;
		tree->left = NULL;
		tree->right = NULL; //ветви инициализируем пустотой
	}
	else     // иначе
	{
		if (ft_strcmp(str, tree->field) > 0)   //Если элемент str меньше корневого, уходим влево
			tree->left = addnode_flag_r(str, tree->left, buf); //Рекурсивно добавляем элемент
		else  //иначе уходим вправо
			tree->right = addnode_flag_r(str, tree->right, buf); //Рекурсивно добавляем элемент
	}
	return (tree);
}

int				sorting(int	ac, char **av, t_ls *ls, struct stat buf)
{
	struct s_node	*tree;
	int				i;

	i = 1;
	tree = NULL;
	while (i < ac)
	{
		if (i != ls->f_index[i] && i != ls->dh_index)
		{
			if (ls->r == 1)
			{
				if (!(tree = addnode_flag_r(av[i], tree, buf)))
					return (ERROR);
			}
			else if (!(tree = addnode(av[i], tree, buf)))
				return (ERROR);
		}
		i++;
	}
	output(ls, tree);
	return (0);
}
