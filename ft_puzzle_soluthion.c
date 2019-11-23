/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puzzle_soluthion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:16:46 by wrhett            #+#    #+#             */
/*   Updated: 2019/11/19 17:43:03 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_clear_map(char *map)
{
	int	n;

	n = 0;
	while (n < 160)
	{
		map[n] = '\0';
		n += 1;
	}
}

void		ft_puzzle_soluthion(t_fillit **head, size_t len, size_t side)
{
	static char		map[160];
	int				n;
	size_t			m;

	n = 0;
	while (n != 1 && side != 15)
	{
		n = ft_puzzle(map, head, len, side);
		if (n == -1)
		{
			m = 0;
			while (m < len)
			{
				head[m]->shift = 0;
				m += 1;
			}
			side += 1;
			ft_clear_map(map);
		}
	}
	ft_print_tetrimino(head, len, side);
}
