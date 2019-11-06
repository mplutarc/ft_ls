/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:11:20 by emaveric          #+#    #+#             */
/*   Updated: 2019/11/06 18:06:11 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

// заходим и записываем все элементы с ошибкой
// сортируем все элементы
// выводим все элементы в отсортированном порядке

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

void			e_print(struct s_node *tree)
{
	if (tree != NULL)
	{      //Пока не встретится пустой узел
		e_print(tree->left);  //Рекурсивная функция вывода левого поддерева
		if (!opendir(tree->field) && !fopen(tree->field, "rt"))
			directory(tree->field);
		e_print(tree->right); //Рекурсивная функция вывода правого поддерева
	}
}

void			print(struct s_node *tree)
{
	if (tree != NULL)
	{      //Пока не встретится пустой узел
		print(tree->left);  //Рекурсивная функция вывода левого поддерева
		if (opendir(tree->field) || fopen(tree->field, "rt"))
		{
			ft_putstr(tree->field);
			ft_putchar('\n');
			//directory(tree->field);
		}
		print(tree->right); //Рекурсивная функция вывода правого поддерева
	}
}

int				sorting(int	ac, char **av)
{
	struct s_node	*tree;
	int				i;

	i = 1;
	tree = NULL;
	while (i < ac)
	{
		if (!(tree = addnode(av[i], tree)))
			return (ERROR);
		i++;
	}
	e_print(tree);
	print(tree);
	return (0);
}

/*
int 	sorting(int ac, char **av, t_ls *ls)
{
	int 	i;
	int 	j;
	int 	k;
	int 	n;
	char 	*new;

	i = 1;
	j = 1;
	k = 1;
	n = 1;
	if (!(ls->e_sort = (char **)malloc(sizeof(char *) * ls->e_sum)))
		return (ERROR);
	while (i < ac)
	{
		if (i == ls->e_index[j])
		{
			ls->e_sort[i] = av[i];
			j++;
		}
		i++;
	}
	i = 1;
	j = 1;
	while (i < ac)
	{
		if (i == ls->e_index[k])
		{
			while (j < ac)
			{
				if (j == ls->e_index[n + 1])
				{
					if (ft_strcmp(ls->e_sort[ls->e_index[n]], ls->e_sort[j]) > 0)
					{
						new = ls->e_sort[j];
						ls->e_sort[j] = ls->e_sort[ls->e_index[n]];
						ls->e_sort[ls->e_index[n]] = new;
					}
					n++;
				}
				j++;
			}
			n = 1;
			k++;
		}
		j = 1;
		i++;
	}
	i = 1;
	while (i < ac)
	{
		if (i == ls->e_index[j])
		{
			directory(ls->e_sort[i]);
			j++;
		}
		i++;
	}
	return (0);
}*/
