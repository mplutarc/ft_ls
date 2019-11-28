/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 17:41:40 by emaveric          #+#    #+#             */
/*   Updated: 2019/11/28 18:07:26 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	free_tree(struct s_node *tree, t_ls *ls)
{
	if (tree != NULL)
	{      //Пока не встретится пустой узел
		free_tree(tree->left, ls);  //Рекурсивная функция вывода левого поддерева
		free(tree->field);
		free(tree->time);
		free(tree->mode);
		free(tree->gid);
		free(tree->uid);
		free(tree);
		free_tree(tree->right, ls); //Рекурсивная функция вывода правого поддерева
	}
}