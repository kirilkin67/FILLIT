/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puzzle_soluthion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:01:22 by wrhett            #+#    #+#             */
/*   Updated: 2020/01/14 11:17:41 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_clear_str(char *map, t_fillit **head, size_t m, int side)
{
	int	n;
	int	b;

	b = (head[m]->tetrimino == 34952) ? 13 : 10;
	n = 0;
	while (n < b)
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
	int	b;

	b = (head[m]->tetrimino == 34952) ? 13 : 10;
	n = 0;
	while (n < b)
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
	int		b;

	b = (head[m]->tetrimino == 34952) ? 13 : 10;
	while ((size_t)head[m]->shift < side * side)
	{
		n = 0;
		bit = 0;
		while (n < b && bit != 4)
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

static int	ft_puzzle(char *map, t_fillit **head, size_t len, size_t side)
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
			ft_bzero(map, 160);
		}
	}
	ft_print_tetrimino(head, len, side);
}
