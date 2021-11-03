/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:16:51 by rchampli          #+#    #+#             */
/*   Updated: 2021/11/03 17:24:27 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
		dest[i++] = '\0';
	dest[i] = '\0';
	return (dest);
}

int	ft_is_charset(char c, const char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
		if (c == charset[i++])
			return (1);
	return (0);
}

char	*ft_next_word(char *str, char *charset)
{
	if (!str[0])
		return (0);
	while (!ft_is_charset(*str, charset))
	{
		if (*str)
			str++;
		else
			return (0);
	}
	while (ft_is_charset(*str, charset))
	{
		if (*str)
			str++;
		else
			return (0);
	}
	return (str);
}

int	ft_word_count(char *str, char *charset)
{
	char	*tmp;
	int		wc;

	tmp = str;
	wc = 0;
	while (tmp && *tmp)
	{
		tmp = ft_next_word(tmp, charset);
		wc++;
	}
	return (wc);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		it;
	int		wc;
	int		ln;

	if (ft_is_charset(*s, &c))
		s = ft_next_word((char *)s, &c);
	wc = ft_word_count((char *)s, &c);
	strs = calloc((wc + 1), sizeof(char *));
	if (!strs)
		return (0);
	it = 0;
	while (s && it < wc)
	{
		ln = 0;
		while (s[ln] && !ft_is_charset(s[ln], &c))
			ln++;
		strs[it] = calloc((ln + 1), sizeof(char));
		if (!strs[it])
			return (0);
		ft_strncpy(strs[it++], s, ln);
		s = ft_next_word((char *)s, &c);
	}
	strs[wc] = 0;
	return (strs);
}
