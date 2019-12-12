/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   columns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:42:27 by mplutarc          #+#    #+#             */
/*   Updated: 2019/12/12 20:54:28 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char		*itostr(struct s_node *tree, t_ls *ls)
{
	char	*str_link;
	char	*str_size;
	int		sizeofstr;
	int		i;

	sizeofstr = 0;
	while ((ls->col->link / 10) > 0)
	{
		ls->col->link /= 10;
		sizeofstr++;
	}
	printf("size of str |%d|\n", sizeofstr);
	if (!(str_link = (char *)malloc(sizeof(char *) * (sizeofstr + 3))))
		return (NULL);
	i = 0;
	while (i < sizeofstr + 3)
	{
		str_link[i] = '.';
		printf("|%s|\n", str_link);
		i++;
	}
	return (str_link);
}

t_column	*init_col(void)
{
	t_column	*new;

	if (!(new = (t_column *)malloc(sizeof(t_column))))
		    return (NULL);
	new->link = 0;
	new->size = 0;
	return(new);
}

t_ls		*max_str(struct s_node *tree, t_ls *ls)
{
	if (tree != NULL)
	{
		max_str(tree->left, ls);
		if (ls->col->link < tree->links)
			ls->col->link = tree->links;
		if (ls->col->size < tree->size)
			ls->col->size = tree->size;
		max_str(tree->right, ls);
	}
	return (ls);
}

char		*into_string(struct s_node *tree, t_ls *ls)
{
	char	*res;

	ls = max_str(tree, ls);
	printf("max link = %d, max size = %d\n",ls->col->link, ls->col->size);
	res = ft_strcat(tree->mode, itostr(tree, ls));
	printf("res: |%s|\n", res);
	return(res);
}