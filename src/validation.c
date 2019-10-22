/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:54:51 by emaveric          #+#    #+#             */
/*   Updated: 2019/10/22 20:17:31 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"


// проверка на ''
// проверка на --
// проверка с флагами

int 	dhyp_check(int ac, char **av, t_ls *ls)
{
	int 	i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-' && av[i][1] == '-')
		{
			if (av[i][2] != '\0')
				return (ERROR);
			else
			{
				ls->dh_index = i; // запоминаем с какого индекса --
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int		validation(int ac, char **av, t_ls *ls)
{
    int     i;

    i = 1;
    if (dhyp_check(ac, av, ls) == ERROR)
    	return (ERROR); //посмотреть ошибку ориг лс если ввести 3 --- и тп
    else if (dhyp_check(ac, av, ls) == 1)
    {
		printf("\\\\\\\\ LS->INDEX = %d \n\n", ls->dh_index);
    	return (1); // игнорирование последующих флагов после --
    }
    else
    	while (i < ac)
    	{
    		if (av[i][0] != '-' || (av[i][0] == '-' && av[i][1] == '\0')) // папка может быть названа -
            	ls->flag = 1;
    		else if (av[i][0] == '-' && ls->flag == 1)
            	directory(av[i]);
    		i++;
    	}
    return (0);
}