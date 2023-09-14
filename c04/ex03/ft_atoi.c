/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekmekci <sekmekci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:48:33 by sekmekci          #+#    #+#             */
/*   Updated: 2023/09/14 01:37:05 by sekmekci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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

int	main(void)
{
	char	str[] = "        +----+++--+1234---++ab567";

	printf ("%d", ft_atoi(str));
}
