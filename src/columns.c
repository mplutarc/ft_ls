/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   columns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:42:27 by mplutarc          #+#    #+#             */
/*   Updated: 2019/12/23 18:50:12 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		max_len(struct s_node *tree, t_ls *ls)
{
	if (tree != NULL)
	{
		max_len(tree->left, ls);
		if (ls->col->max_ino < ft_numlen(tree->ino) &&
			(ls->a == 1 || ft_strname(tree->field, '/')[0] != '.'))
			ls->col->max_ino = ft_numlen(tree->ino);
		if (ls->col->max_link < ft_numlen(tree->links) &&
				(ls->a == 1 || ft_strname(tree->field, '/')[0] != '.'))
			ls->col->max_link = ft_numlen(tree->links);
		if (ls->col->max_size < ft_numlen(tree->size) &&
				(ls->a == 1 || ft_strname(tree->field, '/')[0] != '.'))
			ls->col->max_size = ft_numlen(tree->size);
		if (ls->col->max_uid < ft_strlen(tree->uid) &&
				(ls->a == 1 || ft_strname(tree->field, '/')[0] != '.'))
			ls->col->max_uid = ft_strlen(tree->uid);
		if (ls->col->max_gid < ft_strlen(tree->gid) &&
				(ls->a == 1 || ft_strname(tree->field, '/')[0] != '.'))
			ls->col->max_gid = ft_strlen(tree->gid);
		max_len(tree->right, ls);
	}
}

char		*ft_str_space(int size)
{
	int		i;
	char 	*str;

	if (!(str = (char *)ft_memalloc(sizeof(char)*(size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i] = ' ';
		i++;
	}
	str[i] = '\0';
	return (str);
}

t_ls		*itostr(struct s_node *tree, t_ls *ls)
{
	int		sizeofstr;
	char 	*str;

	sizeofstr = ls->col->max_link + 2;
	ls->col->str_link = ft_itoa_rev(tree->links, sizeofstr);
	sizeofstr = ls->col->max_size + 2;
	ls->col->str_size = ft_itoa_rev(tree->size, sizeofstr);
	sizeofstr = ls->col->max_uid - ft_strlen(tree->uid) + 2;
	if (!(str = ft_str_space(sizeofstr)))
		return (NULL);
	ls->col->str_uid = ft_strjoin(tree->uid, str);
	free(str);
	sizeofstr = ls->col->max_gid - ft_strlen(tree->gid);
	if (!(str = ft_str_space(sizeofstr)))
		return (NULL);
	ls->col->str_gid = ft_strjoin(tree->gid, str);
	free(str);
	if (ls->i == 1)
	{
		sizeofstr = ls->col->max_ino + 2;
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
	new->max_ino = 0;
	new->max_link = 0;
	new->max_size = 0;
	new->max_uid = 0;
	new->max_gid = 0;
	new->str_link = NULL;
	new->str_ino = NULL;
	new->str_size = NULL;
	new->str_uid = NULL;
	new->str_gid = NULL;
	return (new);
}

void		into_string(struct s_node *tree, t_ls *ls)
{
	ls = itostr(tree, ls);
}
