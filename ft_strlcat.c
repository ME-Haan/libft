/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 10:26:48 by mhaan         #+#    #+#                 */
/*   Updated: 2022/10/20 14:10:31 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	const size_t	srclen = ft_strlen(src);
	const size_t	dstlen = ft_strlen(dst);
	size_t			i;

	if (dstlen >= dstsize)
		return (dstsize + srclen);
	i = 0;
	while (i < srclen && i < (dstsize - dstlen - 1))
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char src[8] = "D";
// 	char dst[8] = "H";

// 	printf("Length: %lu, strlcat: %s\n", strlcat(dst, src, 3), dst);
// 	char dst2[8] = "H";
// 	printf("Length: %lu, ft_strlcat: %s\n", ft_strlcat(dst2, src, 3), dst2);
// }