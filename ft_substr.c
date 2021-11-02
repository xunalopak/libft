/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:09:08 by rchampli          #+#    #+#             */
/*   Updated: 2021/11/01 17:09:08 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	size_t			j;
	unsigned char	*str;

	i = 0;
	str = (char *)malloc(sizeof(*s) * len + 1);
	if (!str)
		return (0);
	while (s[i])
	{
		while (i >= start && j < len)
		{
			str[i] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}
