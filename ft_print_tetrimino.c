/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tetrimino.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:52:14 by wrhett            #+#    #+#             */
/*   Updated: 2019/11/25 11:23:27 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_print(char *str, int side)
{
	int	n;

	n = 0;
	while (n < side * side)
	{
		if (ft_isalpha(str[n]))
			write(1, &str[n], 1);
		else
			write(1, ".", 1);
		n += 1;
		if (n % side == 0)
			write(1, "\n", 1);
	}
}

void		ft_print_tetrimino(t_fillit **head, size_t len, size_t side)
{
	char	*str;
	int		n;
	size_t	m;

	str = ft_strnew(side * side);
	m = 0;
	while (m < len)
	{
		n = 0;
		while (n < 13)
		{
			if (head[m]->tetrimino & (1 << (15 - n)))
				str[n / 4 * side + n % 4 + head[m]->shift] = head[m]->id;
			n += 1;
		}
		m += 1;
	}
	ft_print(str, side);
	free(str);
}
