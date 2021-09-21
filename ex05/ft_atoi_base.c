/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 22:09:40 by chpark            #+#    #+#             */
/*   Updated: 2021/09/21 22:41:26 by chpark           ###   ########.fr       */
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

void	ft_trance_nbr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = str[i] + 48;
		i++;
	}
	return (str);
}

void	ft_atoi_base(char *str, char *base)
{
	long	*n;
	int		bl;

	bl = 0;
	ft_trance_nbr(str);
	*n = *str;
	if (ft_check_error(base))
	{
		while (base[bl])
			bl++;
		if (n < bl)
			ft_putchar(base[nb]);
		if (n >= bl)
		{
			ft_atoi_base(n / bl, base);
			ft_atoi_base(n % bl, base);
		}
	}
}
