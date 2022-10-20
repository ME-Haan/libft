/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 16:24:46 by mhaan         #+#    #+#                 */
/*   Updated: 2022/10/20 14:12:29 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static size_t	count_splits(char const *s, char c);
static void		fill_array(char const *s, char c, const size_t cnt, char **arr);

static size_t	count_splits(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static void	fill_array(char const *s, char c, const size_t cnt, char **arr)
{
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	start = 0;
	end = 0;
	while (i < cnt)
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		arr[i] = ft_substr(s, start, end - start);
		i++;
		start = end;
	}
	arr[i] = 0;
}

char	**ft_split(char const *s, char c)
{
	char			**arr;
	const size_t	count = count_splits(s, c);

	if (!s)
		return (0);
	arr = (char **)malloc((count + 1) * sizeof(char *));
	if (!arr)
		return (0);
	fill_array(s, c, count, arr);
	return (arr);
}

// #include	"stdio.h"
// int	main(void)
// {
// 	char str[] = "abc---efg--erga-adsgdgs----dsgas-da";
// 	char delim = '-';

// 	printf("%lu", count_splits(str, delim));	
// }