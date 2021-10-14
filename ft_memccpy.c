/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:42:30 by rchampli          #+#    #+#             */
/*   Updated: 2021/10/11 15:42:30 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	tmp1;
	unsigned char	tmp2;
	unsigned int	i;

	i = 0;
	tmp1 = (unsigned char *)src;
	tmp2 = (unsigned char *)dest;
	while (i < n)
	{
		tmp2[i] = tmp1[i];
		if (tmp1[i] == (unsigned char)c)
			return ((void *)(tmp2 + 1));
		i++;
	}
	return (0);
}
