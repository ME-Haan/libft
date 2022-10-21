/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 18:00:10 by mhaan         #+#    #+#                 */
/*   Updated: 2022/10/21 10:21:08 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int	fill_str(char *str, size_t numlen, int n, int sign);

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	tmp;
	int				sign;
	size_t			numlen;

	sign = 1;
	numlen = 0;
	if (n < 0)
	{
		sign = -1;
		numlen++;
	}
	tmp = n * sign;
	while (tmp / 10)
	{
		numlen++;
		tmp /= 10;
	}
	if (tmp >= 0)
		numlen++;
	str = (char *)malloc((numlen + 1) * sizeof(char));
	if (!str)
		return (0);
	fill_str(str, numlen, n, sign);
	return (str);
}

static int	fill_str(char *str, size_t numlen, int n, int sign)
{
	unsigned int	tmp;

	str[numlen] = '\0';
	tmp = n * sign;
	while (numlen-- > 1)
	{
		str[numlen] = (tmp % 10) + 48;
		tmp = tmp / 10;
	}
	if (sign == -1)
		str[numlen] = 45;
	else
		str[numlen] = tmp + 48;
	return (0);
}

// #include <stdio.h>
// int	main (void)
// {
// 	int	x = 0;
// 	printf("%s\n", ft_itoa(x));
// }
