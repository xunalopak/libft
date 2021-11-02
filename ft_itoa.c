/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:35:02 by rchampli          #+#    #+#             */
/*   Updated: 2021/11/02 14:09:27 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_numlen(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*dest;
	size_t	i ;

	i = ft_numlen(n);
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (0);
	dest[i--] = '\0';
	if (n == 0)
	{
		dest[0] = 48;
		return (dest);
	}
	if (n < 0)
	{
		dest[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		dest[i] = 48 + (n % 10);
		n = n / 10;
		i--;
	}
	return (dest);
}
