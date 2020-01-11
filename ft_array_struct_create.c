/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_struct_create.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 12:55:51 by wrhett            #+#    #+#             */
/*   Updated: 2019/11/25 11:12:10 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_free_array(t_fillit **tab, size_t index)
{
	while (index > 0)
	{
		free(tab[index - 1]);
		index -= 1;
	}
	free(tab);
}

t_fillit	**ft_array_struct_create(char *str)
{
	static t_fillit	**node;
	char			*tmp;
	size_t			len_node;
	size_t			n;

	tmp = str;
	len_node = (ft_strlen(tmp) + 1) / 21;
	node = (t_fillit **)malloc(sizeof(t_fillit *) * len_node);
	if (node == NULL)
		return (NULL);
	n = 0;
	while (*tmp)
	{
		node[n] = (t_fillit *)malloc(sizeof(t_fillit));
		if (node[n] == NULL)
			ft_free_array(node, n);
		node[n]->id = 'A' + n;
		node[n]->tetrimino = ft_tetrimino_validation(tmp);
		node[n]->shift = 0;
		tmp = (ft_strlen(tmp) > 20) ? tmp + 21 : tmp + 20;
		n += 1;
	}
	return (node);
}
