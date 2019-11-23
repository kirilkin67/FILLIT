/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetrimino_validation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:27:13 by wrhett            #+#    #+#             */
/*   Updated: 2019/11/14 16:20:17 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int	ft_is_tetrimino(int tetr)
{
	static int	tab[19] = {52224, 61440, 34952, 58368, 19968, 35968, 19520,
	59392, 35008, 50240, 51328, 17600, 36352, 57856, 11776, 50688, 27648,
	35904, 19584};
	int			n;

	n = 0;
	while (n <= 19)
	{
		if (tetr != tab[n])
			n += 1;
		else
			return (1);
	}
	return (0);
}

static int	ft_atoi_binary(char *str)
{
	int	num;
	int	n;

	num = 0;
	n = 0;
	while (str[n] && n < 19)
	{
		if (str[n] == '\n')
			n += 1;
		num = num * 2 + (str[n] - '0');
		n += 1;
	}
	return (num);
}

int			ft_tetrimino_validation(char *str)
{
	int	tetrimino;

	tetrimino = ft_atoi_binary(str);
	while (tetrimino <= 61440)
	{
		if (ft_is_tetrimino(tetrimino) == 1)
			return (tetrimino);
		else
		{
			if ((tetrimino & (1 << 3)) || (tetrimino & (1 << 7)) ||
			(tetrimino & (1 << 11)))
				tetrimino = tetrimino << 4;
			else
				tetrimino = tetrimino << 1;
		}
	}
	return (0);
}
