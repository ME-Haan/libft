/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 15:09:30 by mhaan         #+#    #+#                 */
/*   Updated: 2022/10/10 15:53:31 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/* # include	<stdio.h>
# include	<ctype.h>
int	main(void)
{
	char c = '!';

	printf("ft: %i\n", ft_isprint(c));
	printf("test: %i", isprint(c));
} */
