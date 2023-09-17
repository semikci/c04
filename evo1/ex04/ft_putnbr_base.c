/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekmekci <sekmekci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:35:17 by sekmekci          #+#    #+#             */
/*   Updated: 2023/09/17 12:55:07 by sekmekci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_isbase(char a, char *str)
{
	while (*str)
		if (a == *str++)
			return (1);
	return (0);
}

void	ft_print(long nb, char *base, int size)
{
	if (nb > size -1)
	{
		ft_print(nb / size, base, size);
		ft_print(nb % size, base, size);
	}
	else
		ft_putchar(base[nb]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	long	n;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (base[i] >= 9 && base[i] <= 13)
			|| ft_isbase(base[i], base + i + 1))
			return ;
		i++;
	}
	if (i < 2)
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		n = (long)nbr;
		ft_print(-n, base, i);
	}
	else
		ft_print(nbr, base, i);
}
