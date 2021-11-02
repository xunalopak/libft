/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchampli <rchampli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:16:51 by rchampli          #+#    #+#             */
/*   Updated: 2021/11/02 12:34:14 by rchampli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int		i;

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
	int		i;

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

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		it;
	int		wc;
	int		ln;

	if (ft_is_charset(*str, charset))
		str = ft_next_word(str, charset);
	wc = ft_word_count(str, charset);
	strs = (char **) malloc(sizeof(char *) * (wc + 1));
	if (!strs)
		return (0);
	it = 0;
	while (str && it < wc)
	{
		ln = 0;
		while (str[ln] && !ft_is_charset(str[ln], charset))
			ln++;
		strs[it] = (char *) malloc(sizeof(char) * (ln + 1));
		if (!strs[it])
			return (0);
		ft_strncpy(strs[it++], str, ln);
		str = ft_next_word(str, charset);
	}
	strs[wc] = 0;
	return (strs);
}
