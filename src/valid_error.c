/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 15:58:39 by emaveric          #+#    #+#             */
/*   Updated: 2019/12/24 15:58:39 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int 	valid_error_p2(int ac, char **av, int i, int j)
{
	if (av[i][j] >= 121 || av[i][j] < 65 || av[i][j] == 'E' ||
		av[i][j] == 'D' || (av[i][j] <= 75 && av[i][j] >= 73)
		|| av[i][j] == 'M' || av[i][j] == 'N' || av[i][j] == 'Q'
		|| av[i][j] == 'V' || (av[i][j] >= 88 && av[i][j] <= 96)
		|| av[i][j] == '!' || (av[i][j] >= 35 && av[i][j] <= 37)
		|| (av[i][j] >= 40 && av[i][j] <= 44) || (av[i][j] >= 46
		&& av[i][j] <= 62) || av[i][j] == '@' || (av[i][j] == '-'
		&& j >= 2))
	{
		ft_putstr("ls: illegal option -- ");
		ft_putchar(av[i][j]);
		ft_putchar('\n');
		ft_putendl("usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]");
		return (ERROR);
	}
	return (0);
}

int		valid_error(int ac, char **av)
{
	int		i;
	int		j;

	i = 1;
	j = 1;
	while (ac > 1 && i < ac && av[i][0] == '-')
	{
		while (av[i][j] != '\0')
		{
			if (valid_error_p2(ac, av, i ,j) == ERROR)
				return (ERROR);
			j++;
		}
		j = 1;
		i++;
	}
	return (0);
}