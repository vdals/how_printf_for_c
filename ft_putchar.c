/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 15:46:29 by ggeri             #+#    #+#             */
/*   Updated: 2020/09/12 15:50:47 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int				ft_putstr(const char *str)
{
	int			sum;
	const char	*ptr;

	ptr = str;
	sum = 0;
	while (*ptr)
	{
		write(1, ptr++, 1);
		sum++;
	}
	return (sum);
}

int				ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int				ft_putstr2(const char *str, int size)
{
	const char	*ptr;
	int			sum;

	sum = 0;
	ptr = str;
	while (size > 0)
	{
		write(1, ptr++, 1);
		sum++;
		size--;
	}
	return (sum);
}
