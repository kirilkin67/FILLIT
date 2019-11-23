/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 12:49:36 by wrhett            #+#    #+#             */
/*   Updated: 2019/11/18 19:55:18 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		valid_character(char *str)
{
	while (*str != '\0')
	{
		if (*str != '.' && *str != '#' && *str != '\n')
			return (0);
		if (*str == '.')
			*str = '0';
		if (*str == '#')
			*str = '1';
		str += 1;
	}
	return (1);
}

static int		valid_block(char *str)
{
	int	line;

	while (*str)
	{
		line = 0;
		while (line != 4)
		{
			if ((ft_strchr(str, '\n') - str) == 4)
			{
				line += 1;
				str = ft_strchr(str, '\n') + 1;
			}
			else
				return (0);
		}
		if (*str != '\n' && *str != '\0')
			return (0);
		else if (*str == '\n')
			str += 1;
	}
	return (1);
}

static int		valid_tetrimino(char *str)
{
	while (*str)
	{
		if (ft_tetrimino_validation(str) == 0)
			return (0);
		else if (ft_strlen(str) > 20)
			str += 21;
		else
			str += 20;
	}
	return (1);
}

t_fillit		**ft_fillit_validation(char *str)
{
	char		*tmp;
	t_fillit	**tetrimino;

	if (str == NULL)
		return (NULL);
	tmp = str;
	if (valid_character(tmp) && valid_block(tmp) && valid_tetrimino(tmp))
	{
		tetrimino = ft_array_struct_create(tmp);
		return (tetrimino);
	}
	else
		ft_putendl("error");
	return (NULL);
}
