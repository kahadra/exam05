/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:22:17 by chpark            #+#    #+#             */
/*   Updated: 2021/09/21 20:33:25 by chpark           ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	if (argc == 2)
		ft_atoi(argv[1]);
	else
		return (0);
}
