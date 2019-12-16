/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   columns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:42:27 by mplutarc          #+#    #+#             */
/*   Updated: 2019/12/16 21:30:21 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		max_len(struct s_node *tree, t_ls *ls)
{
	if (tree != NULL)
	{
		max_len(tree->left, ls);
		if (ls->col->max_ino < ft_numlen(tree->ino))
			ls->col->max_ino = ft_numlen(tree->ino);
		if (ls->col->max_link < ft_numlen(tree->links))
			ls->col->max_link = ft_numlen(tree->links);
		if (ls->col->max_size < ft_numlen(tree->size))
			ls->col->max_size = ft_numlen(tree->size);
		max_len(tree->right, ls);
	}
}

/*int			ft_strlen_ino(char *str)
{
	int		i;
	int 	sum;

	i = 0;
	sum = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] != ' ' && str[i] != '\0')
	{
		sum++;
		i++;
	}
	return (sum);
}*/

int 		ft_str_space_len(char *str)
{
	int 	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	return (i);
}

t_ls		*itostr(struct s_node *tree, t_ls *ls)
{
	int		sizeofstr;
	int		i;

	sizeofstr = ls->col->max_link + 2;
	ls->col->str_link = ft_itoa_rev(tree->links, sizeofstr);
	sizeofstr = ls->col->max_size + 2;
	ls->col->str_size = ft_itoa_rev(tree->size, sizeofstr);
	if (ls->i == 1)
	{
		//sizeofstr = ft_numlen(ls->col->ino);
		sizeofstr = ls->col->max_ino + 2;
		ls->col->str_ino = ft_itoa_rev(tree->ino, sizeofstr);
		ft_strncut(ls->col->str_ino, 2, ft_strlen(ls->col->str_ino));
		/*ft_strncut(ls->col->str_ino, ft_str_space_len(ls->col->str_ino) - (ls->col->max_ino -
			(ft_strlen(ls->col->str_ino) - ft_str_space_len(ls->col->str_ino) - 1)),
				ft_strlen(ls->col->str_ino));*/
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
	new->max_ino = 0;
	new->max_link = 0;
	new->max_size = 0;
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