/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   columns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:42:27 by mplutarc          #+#    #+#             */
/*   Updated: 2019/12/16 16:35:39 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_ls		*itostr(struct s_node *tree, t_ls *ls)
{
	int		sizeofstr;
	int		i;
	int		tmp;

	sizeofstr = 0;
	tmp = ls->col->link;
	while ((tmp /= 10) > 0)
		sizeofstr++;
	sizeofstr += 3;
	ls->col->str_link = ft_itoa_rev(tree->links, sizeofstr);
	sizeofstr = 0;
	tmp = ls->col->size;
	while ((tmp /= 10) > 0)
		sizeofstr++;
	sizeofstr += 3;
	ls->col->str_size = ft_itoa_rev(tree->size, sizeofstr);
	if (ls->i == 1)
	{
		sizeofstr = 0;
		tmp = ls->col->ino;
		while ((tmp /= 10) > 0)
			sizeofstr++;
		sizeofstr += 3;
		ls->col->str_ino = ft_itoa_rev(tree->ino, sizeofstr);
		ft_strncut(ls->col->str_ino, 2, ft_strlen(ls->col->str_ino));
	}
	return (ls);
}

t_column	*init_col(void)
{
	t_column	*new;

	if (!(new = (t_column *)malloc(sizeof(t_column))))
		    return (NULL);
	new->link = 0;
	new->size = 0;
	new->ino = 0;
	new->str_link = NULL;
	new->str_ino = NULL;
	new->str_size =  NULL;
	return(new);
}

// t_ls		*max_str(struct s_node *tree, t_ls *ls)
// {
// 	if (tree != NULL)
// 	{
// 		ft_putstr(tree->field);
// 		ft_putchar('\n');
// 		max_str(tree->left, ls);
// 		printf("Check LINKS: %d < %d\n", ls->col->link, tree->links);
// 		printf("Check SIZE:  %d < %d\n\n", ls->col->size, tree->size);
// 		if (ls->col->link <= tree->links)
// 			ls->col->link = tree->links;
// 		if (ls->col->size <= tree->size)
// 			ls->col->size = tree->size;
// 		max_str(tree->right, ls);
// 	}
// 	return (ls);
// }

void		into_string(struct s_node *tree, t_ls *ls)
{
	ls = itostr(tree, ls);
	// printf("link = |%s| size = |%s|\n",ls->col->str_link, ls->col->str_size);
}