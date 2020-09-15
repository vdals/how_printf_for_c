/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 15:33:05 by ggeri             #+#    #+#             */
/*   Updated: 2020/09/05 19:33:50 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int 		ft_len(long i)
{
	int		count;
	count = (i == 0) ? 1 : 0;
	while (i != 0)
	{
		count++;
		i /= 10;
	}
	return count;
}

int			ft_pow(int x, unsigned int y)
{
	int		i;

	if (y == 0)
		return (1);
	i = ft_pow(x, y / 2);
	if (y % 2 == 0)
		return (i * i);
	else
		return (x * i * i);
}

int			length_of_num(unsigned long long int i, int base)
{
	int		length;

	length = 0;
	if (i == 0)
		return (1);
	if (i < 0)
	{
		i *= -1;
		length++;
	}
	while (i > 0)
	{
		i /= base;
		length++;
	}
	return (length);
}

int			length_of_num_i(long long int i, int base)
{
	int		length;

	length = 0;
	if (i == 0)
		return (1);
	if (i < 0)
	{
		i *= -1;
		length++;
	}
	while (i > 0)
	{
		i /= base;
		length++;
	}
	return (length);
}

void		print_base_i(long long num, long long base)
{
	long long	num1;


	if (num < 0)
		num *= -1;
	num1 = (long long)num;
	if (num1 >= base)
	{
		print_base(num1 / base, base);
		print_base(num1 % base, base);
	}
	else if (num1 < base && num1 < 10)
		ft_putchar(num + 48);
	else if (base >= 11 && num1 < base)
		ft_putchar('a' + num1 - 10);
}

void		print_base_high(unsigned long long num,\
										 unsigned long long base)
{
	unsigned long long	num1;


	if (num < 0)
		num *= -1;
	num1 = (unsigned long long)num;
	if (num1 >= base)
	{
		print_base_high(num1 / base, base);
		print_base_high(num1 % base, base);
	}
	else if (num1 < base && num1 < 10)
		ft_putchar(num + 48);
	else if (base >= 11 && num1 < base)
		ft_putchar('A' + num1 - 10);
}

void		print_base(unsigned long long num,\
										 unsigned long long base)
{
	unsigned long long	num1;


	if (num < 0)
		num *= -1;
	num1 = (unsigned long long)num;
	if (num1 >= base)
	{
		print_base(num1 / base, base);
		print_base(num1 % base, base);
	}
	else if (num1 < base && num1 < 10)
		ft_putchar(num + 48);
	else if (base >= 11 && num1 < base)
		ft_putchar('a' + num1 - 10);
}
