/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:40:18 by emarion           #+#    #+#             */
/*   Updated: 2021/10/20 10:24:55 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(char const *s, char c)
{
	size_t	counter;
	size_t	in_word;

	counter = 0;
	in_word = 0;
	while (*s)
	{
		if (in_word == 0 && *s != c)
		{
			in_word = 1;
			counter ++;
		}
		if (in_word == 1 && *s == c)
		{
			in_word = 0;
		}
		s ++;
	}
	return (counter);
}

static size_t	ft_word_length(char const *s, char c)
{
	size_t		length;

	length = 0;
	while (*s != c && *s != '\0')
	{
		s ++;
		length ++;
	}
	return (length);
}

static char	**make_array(char *s, char c, char **res)
{
	size_t	words_count;
	size_t	i;

	i = 0;
	words_count = ft_word_count(s, c);
	while (words_count > 0)
	{
		while (*s == c && *s != '\0')
			s++;
		res[i] = ft_substr(s, 0, ft_word_length(s, c));
		if (res[i] == NULL)
			return (NULL);
		s = s + ft_word_length(s, c);
		i ++;
		words_count --;
	}
	res[i] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	res = (char **)malloc(sizeof(*res) * (ft_word_count((char *)s, c) + 1));
	if (!res)
		return (NULL);
	return (make_array((char *)s, c, res));
}
