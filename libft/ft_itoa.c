/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 13:42:44 by wrhett            #+#    #+#             */
/*   Updated: 2019/09/19 11:30:58 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_itoa(int n)
{
	char			*str;
	size_t			index;
	unsigned int	num;

	index = ft_lennumber(n);
	if (!(str = ft_strnew(index)))
		return (NULL);
	num = (n < 0) ? (unsigned int)-n : n;
	if (n < 0)
		str[0] = '-';
	while (num >= 10)
	{
		str[index - 1] = num % 10 + '0';
		num = num / 10;
		index -= 1;
	}
	str[index - 1] = num + '0';
	return (str);
}
