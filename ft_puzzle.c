/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puzzle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:01:22 by wrhett            #+#    #+#             */
/*   Updated: 2019/11/23 18:20:34 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_clear_str(char *map, t_fillit **head, size_t m, int side)
{
	int	n;

	n = 0;
	while (n < 13)
	{
		if (head[m]->tetrimino & (1 << (15 - n)))
			map[n / 4 * side + n % 4 + head[m]->shift] = '\0';
		n += 1;
	}
	head[m]->shift += 1;
	head[m + 1]->shift = 0;
}

static void	ft_set_str(char *map, t_fillit **head, size_t m, int side)
{
	int	n;

	n = 0;
	while (n < 13)
	{
		if (head[m]->tetrimino & (1 << (15 - n)))
			map[n / 4 * side + n % 4 + head[m]->shift] = '1';
		n += 1;
	}
}

static int	ft_test_str(char *map, t_fillit **head, size_t m, size_t side)
{
	size_t	offset;
	int		bit;
	int		n;

	while ((size_t)head[m]->shift < side * side)
	{
		n = 0;
		bit = 0;
		while (n < 13 && bit != 4)
		{
			offset = n / 4 * side + n % 4 + head[m]->shift;
			if ((head[m]->tetrimino & (1 << (15 - n))) && (map[offset] != '1')
			&& ((n % 4 + head[m]->shift % side) < side) && offset < side * side)
				bit += 1;
			if ((head[m]->tetrimino & (1 << (15 - n))) && (map[offset] == '1'))
				break ;
			n += 1;
		}
		if (bit == 4)
			return (head[m]->shift);
		else
			head[m]->shift += 1;
	}
	return (-1);
}

int			ft_puzzle(char *map, t_fillit **head, size_t len, size_t side)
{
	size_t	n;

	n = 0;
	while (n < len && (head[0]->shift != -1))
	{
		if ((head[n]->shift = ft_test_str(map, head, n, side)) != -1)
		{
			ft_set_str(map, head, n, side);
			if ((n + 1) < len)
			{
				if (ft_test_str(map, head, n + 1, side) != -1)
					n += 1;
				else
					ft_clear_str(map, head, n, side);
			}
			else
				return (1);
		}
		else if (head[n]->shift == -1 && n != 0)
		{
			ft_clear_str(map, head, (n - 1), side);
			n -= 1;
		}
	}
	return (-1);
}
