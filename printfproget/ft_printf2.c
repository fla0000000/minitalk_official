/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:16:10 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/04/13 18:58:53 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_puutchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_puutstr(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

void	ft_puutnbr(int n, int *written)
{
	int	a;

	if (n == -2147483648)
		*written += write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n = n * (-1);
			*written += write(1, "-", 1);
		}
		a = n % 10;
		n = n / 10;
		if (n > 0)
			ft_puutnbr(n, written);
		a += 48;
		*written += write(1, &a, 1);
	}
}
