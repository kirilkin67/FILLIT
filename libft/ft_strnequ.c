/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:52:31 by wrhett            #+#    #+#             */
/*   Updated: 2019/09/14 19:04:31 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 != NULL && s2 != NULL)
	{
		while (n > 0 && (*s1 || *s2))
		{
			if (*s1 != *s2)
				return (0);
			s1 += 1;
			s2 += 1;
			n -= 1;
		}
		return (1);
	}
	return (0);
}
