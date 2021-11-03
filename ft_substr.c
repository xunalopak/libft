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
	char			*str;

	i = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) < start)
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (0);
		str[0] = '\0';
		return (str);
	}
	str = (char *)malloc((sizeof(*s) * (len + 1)));
	if (!str)
		return (0);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
