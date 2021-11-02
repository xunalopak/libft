/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:00:45 by rchampli          #+#    #+#             */
/*   Updated: 2021/10/20 15:00:45 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	unsigned char	*rpt;

	i = 0;
	rpt = 0;
	while (s[i])
	{
		if (s[i] == c)
			rpt = (char *)s + i;
		i++;
	}
	return (rpt);
}
