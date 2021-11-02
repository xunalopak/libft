/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 19:10:10 by rchampli          #+#    #+#             */
/*   Updated: 2021/10/27 19:10:10 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (size <= 0)
		return (ft_strlen(src));
	while (dest[i] && i < size)
		i++;
	j = i;
	while (src[i - j] != '\0' && i < size - 1)
	{
		dest[j] = src[i - j];
		i++;
	}
	dest[i + j] = '\0';
	if (j < size)
		return (j + ft_strlen(src));
	return (size + ft_strlen(src));
}
