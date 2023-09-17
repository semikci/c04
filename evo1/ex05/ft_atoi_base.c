/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekmekci <sekmekci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:03:08 by sekmekci          #+#    #+#             */
/*   Updated: 2023/09/17 19:33:38 by sekmekci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
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
		write(1, &base[nb], 1);
}

int	ft_atoi(char	*str)
{
	int	i;
	int	s;
	int	ress;
	int	k;

	i = 0;
	s = 1;
	k = 0;
	ress = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			k++;
		i++;
	}
	if ((k % 2) == 1)
		s *= -1;
	while (str[i] >= 48 && str[i] <= 57)
	{
		ress = (str[i] - 48) + (ress * 10);
		i++;
	}
	return (ress * s);
}

int	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	long n;
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (base[i] >= 9 && base[i] <= 13)
			|| ft_isbase(base[i], base + i + 1))
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	n = (long)nbr;
	if (nbr < 0)
	{
		write(1, "-", 1);
		ft_print(-n, base, i);
	}
	else
		ft_print(nbr, base, i);
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	k;
	int	a;

	k = ft_atoi(str);
	ft_putnbr_base(k, base);
	if (a == 0)
		return (a);
	return (0);
}

int main()
{
	char str[] = "-2147483648";
	char base[] = "0123456789";
	printf("%d", ft_atoi_base(str, base));
}