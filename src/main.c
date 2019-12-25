/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mplutarc <mplutarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:23:06 by mplutarc          #+#    #+#             */
/*   Updated: 2019/12/25 15:55:53 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_ls	*init(void)
{
	t_ls	*new;

	if (!(new = (t_ls *)malloc(sizeof(t_ls))))
		return (NULL);
	new->flag = 0;
	new->dh_index = 0;
	new->ac = 0;
	new->l = 0;
	new->i = 0;
	new->a = 0;
	new->t = 0;
	new->r = 0;
	new->big_r = 0;
	new->f_sum = 0;
	new->sec = 0;
	new->point = 0;
	new->col = init_col();
	new->f_index = NULL;
	return (new);
}

void	ft_error(char *the_dir)
{
	ft_putstr("Error opening ");
	ft_putstr(the_dir);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
}

int		main_p2(int ac, char **av, t_ls *ls)
{
	struct stat	buf;
	int			i;

	i = 0;
	while (i < ac)
	{
		stat(av[i], &buf);
		i++;
	}
	if (sorting(ac, av, ls, buf) == ERROR)
	{
		free_ls(ls);
		return (ERROR);
	}
	if ((ls->l != 1 || ls->f_sum == 0) && ls->ac > -1)
		ft_putchar('\n');
	return (0);
}

int		main(int ac, char **av)
{
	t_ls		*ls;

	if (!(ls = init()))
		return (ERROR);
	if (validation(ac, av, ls) == ERROR)
	{
		free_ls(ls);
		return (ERROR);
	}
	if (ac - ls->f_sum > 2)
		ls->ac = ac - ls->f_sum - 1;
	if (ac == 1 || (ft_strcmp(av[1], "--") == 0 && ac == 2)
		|| ls->f_sum == ac - 1
		|| (ft_strcmp(av[ls->f_sum + 1], "--") == 0 && ac == ls->f_sum + 2))
	{
		directory(".", ls);
		if (ls->l != 1 || ls->f_sum == 0)
			ft_putchar('\n');
		free_ls(ls);
		return (0);
	}
	if (main_p2(ac, av, ls) == ERROR)
		return (ERROR);
	free_ls(ls);
	return (0);
}
