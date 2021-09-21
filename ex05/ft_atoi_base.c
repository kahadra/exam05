/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 22:09:40 by chpark            #+#    #+#             */
/*   Updated: 2021/09/21 22:19:30 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] < '0' || '9' < str[i])
	{
		if (str[i] == '-')
			count++;
		i++;
	}
	if ((count % 2) != 0)
		ft_putchar('-');
	while (str[i] != '\0')
	{
		if ('0' <= str[i] && str[i] <= '9')
			ft_putchar(str[i]);
		if ('0' > str[i] || str[i] > '9')
			return (0);
		i++;
	}
	return (0);
}

int	ft_check_error(char *base)
{
	int	i;
	int	j;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	j = i;
	while (base[j] != '\0')
	{
		j++;
		if (base[i] == base[j])
			return (0);
	}
	while (base[i] != '\0')
	{
		if (base[i] < 48 || base[i] >= 123 || (base[i] >= 91 && base[i] <= 96))
			return (0);
		else
			i++;
	}
	return (1);
}

void	ft_atoi_base(char *str, char *base)
{
	int	bl;
	int	error;

	bl = 0;
	error = 0;
	nb = nbr;
	if (ft_check_error(base))
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb *= -1;
		}
		while (base[bl])
			bl++;
		if (nb < bl)
			ft_putchar(base[nb]);
		if (nb >= bl)
		{
			ft_putnbr_base(nb / bl, base);
			ft_putnbr_base(nb % bl, base);
		}
	}
}
