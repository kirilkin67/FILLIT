/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:57:46 by wrhett            #+#    #+#             */
/*   Updated: 2019/11/25 12:33:35 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*ft_fillit_read(char *dest)
{
	char		bufer[BUFF_SIZE + 1];
	char		*str;
	ssize_t		ret;
	int			fd;

	fd = open(dest, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("error");
		exit(1);
	}
	ret = read(fd, bufer, BUFF_SIZE);
	if (ret == -1 || ret < 20 || ((ret + 1) % 21) != 0 || ret > 545)
	{
		ft_putendl("error");
		exit(1);
	}
	bufer[ret] = '\0';
	str = ft_strdup(bufer);
	close(fd);
	return (str);
}

size_t		ft_min_map(t_fillit **head, size_t len_tab)
{
	size_t	nb;
	size_t	sqrt;

	nb = 4 * len_tab;
	sqrt = 1;
	while ((sqrt * sqrt) < nb)
		sqrt += 1;
	if (head[0]->tetrimino == 52224 && len_tab == 1)
		sqrt = 2;
	else if (len_tab == 1)
		sqrt = 3;
	return (sqrt);
}

int			main(int argc, char **argv)
{
	static char	*str;
	size_t		len_tab;
	size_t		side;
	t_fillit	**head;

	if (argc != 2)
	{
		ft_putstr(MESSAGE1);
		return (0);
	}
	head = NULL;
	if ((str = ft_fillit_read(argv[1])) != NULL)
		head = ft_fillit_validation(str);
	if (head != NULL)
	{
		len_tab = (ft_strlen(str) + 1) / 21;
		free(str);
		side = ft_min_map(head, len_tab);
		ft_puzzle_soluthion(head, len_tab, side);
		ft_free_array(head, len_tab);
	}
	return (0);
}
