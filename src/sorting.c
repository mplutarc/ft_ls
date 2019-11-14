/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:11:20 by emaveric          #+#    #+#             */
/*   Updated: 2019/11/14 20:19:13 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

struct s_node	*addnode(char *str, struct s_node *tree)
{
	if (tree == NULL)     // Если дерева нет, то формируем корень
	{
		if (!(tree = (struct s_node *)malloc(sizeof(struct s_node))))
			return (NULL);

		tree->field = str;   //поле данных
		tree->left = NULL;
		tree->right = NULL; //ветви инициализируем пустотой
	}
	else     // иначе
	{
		if (ft_strcmp(str, tree->field) < 0)   //Если элемент str меньше корневого, уходим влево
			tree->left = addnode(str, tree->left); //Рекурсивно добавляем элемент
		else  //иначе уходим вправо
			tree->right = addnode(str, tree->right); //Рекурсивно добавляем элемент
	}
	return (tree);
}

struct s_node	*addnode_flag_r(char *str, struct s_node *tree)
{
	if (tree == NULL)     // Если дерева нет, то формируем корень
	{
		if (!(tree = (struct s_node *)malloc(sizeof(struct s_node))))
			return (NULL);

		tree->field = str;   //поле данных
		tree->left = NULL;
		tree->right = NULL; //ветви инициализируем пустотой
	}
	else     // иначе
	{
		if (ft_strcmp(str, tree->field) > 0)   //Если элемент str меньше корневого, уходим влево
			tree->left = addnode_flag_r(str, tree->left); //Рекурсивно добавляем элемент
		else  //иначе уходим вправо
			tree->right = addnode_flag_r(str, tree->right); //Рекурсивно добавляем элемент
	}
	return (tree);
}

int				sorting(int	ac, char **av, t_ls *ls)
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
				if (!(tree = addnode_flag_r(av[i], tree)))
					return (ERROR);
			}
			else if (!(tree = addnode(av[i], tree)))
				return (ERROR);
		}
		i++;
	}
	output(ls, tree);
	return (0);
}
