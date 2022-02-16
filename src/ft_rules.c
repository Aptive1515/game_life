/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelauna <tdelauna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:53:31 by tdelauna          #+#    #+#             */
/*   Updated: 2022/02/16 18:53:50 by tdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_life.h"

int	ft_check_neighbor(t_coord *(*tab_coord), int nb)
{
	int i;

	i = 0;
	//printf("nb : %d\n", nb);
	if (tab_coord[nb - 1] && nb != 0)
		i += tab_coord[nb - 1]->full;

	if (tab_coord[nb + 1])
		i += tab_coord[nb + 1]->full;
	if (tab_coord[nb + LINE])
		i += tab_coord[nb + LINE]->full;
	if (tab_coord[nb - LINE] && nb >= LINE)
		i += tab_coord[nb - LINE]->full;
	if (tab_coord[nb + LINE + 1])
		i += tab_coord[nb + LINE + 1]->full;
	if (tab_coord[nb + LINE - 1])
		i += tab_coord[nb + LINE - 1]->full;
	if (tab_coord[nb - LINE + 1] && nb >= LINE - 1)
		i += tab_coord[nb - LINE + 1]->full;
	if (tab_coord[nb - LINE - 1] && nb >= LINE + 1)
		i += tab_coord[nb - LINE - 1]->full;
	/*if(i)
		printf("i : %d\n", i);*/
	return (i);
}

void ft_rules(t_coord *(*tab_coord))
{
	int i;
	int neighbor;

	i = 0;
	while (tab_coord[i])
	{
		neighbor = ft_check_neighbor(tab_coord, i);
		//if(neighbor)
		//	printf("neighbor %d\n",neighbor);
		if (tab_coord[i]->full == 0)
		{
			if (neighbor == 3)
				tab_coord[i]->full = 1;
		}
		else if (tab_coord[i]->full == 1)
		{
			if (neighbor > 3 || neighbor < 2)
				tab_coord[i]->full = 0;
		}
		i++;
	}
}
