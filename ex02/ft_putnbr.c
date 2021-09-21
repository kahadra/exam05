/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:13:57 by chpark            #+#    #+#             */
/*   Updated: 2021/09/21 18:21:12 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int	n;

	n = 1;
	if (nb < 0 && (nb / 10) == 0)
		ft_putchar('-');
	if (nb < 0)
		n = -1;
	if ((nb / 10) != 0)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) * n) + '0');
}
