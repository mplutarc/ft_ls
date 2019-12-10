/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   columns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:42:27 by mplutarc          #+#    #+#             */
/*   Updated: 2019/12/10 19:23:44 by mplutarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_column	*init_col(void)
{
	t_column	*new;

	if (!(new = (t_column *)malloc(sizeof(t_column))))
		    return (NULL);
	new->link = 0;
	new->size = 0;
	return(new);
}

char		*into_string(struct s_node *tree, t_ls *ls)
{
	char	*res;

	res = ft_strcat(tree->mode, "  ");
	printf("res = |%s|\n", res);
	return(res);
}