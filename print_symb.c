/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_symb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 14:20:08 by ggeri             #+#    #+#             */
/*   Updated: 2020/09/15 19:24:39 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static int		ft_prints_symb_help(t_arg *r, va_list ap, int sum)
{
	r->c = va_arg(ap, int);
	if (r->c == 0 && r->num == 0)
		return (ft_putchar(0));
	// if (r->num == 0 && r->point == 1)
	// 	return (ft_putchar(r->c));
	if (r->wiedth > 0)
		r->num = r->wiedth;
	if (r->num != 0 && r->minus == 0)
		sum += ft_size_print(r, 1);
	sum += ft_putchar(r->c);
	if (r->num != 0 && r->minus == 1)
		sum += ft_size_print_minus(r, 1);
	return(sum);
}

static int		ft_print_str(t_arg *r)
{
	int			sum;

	sum = 0;
	if (r->minus2 == 1)
	{
		r->fmt++;
		return (ft_putchar(' '));
	}
	if (r->num != 0 && ft_strlen(r->s) == 0 && r->minus == 0)
	{
		r->fmt++;
		return (ft_size_print(r, 0));
	}
	else if ((r->num != 0) && (r->s != NULL) && r->minus == 0)
		sum += ft_size_print(r, r->wiedth);
	else if (r->num != 0 && r->s == NULL && r->minus == 0)
		sum += ft_size_print(r, r->wiedth);
	if (ft_strlen(r->s) == 0 && r->num != 0)
		sum += 0;
	else if (r->s == NULL)
		sum += ft_putstr3("(null)", r->wiedth);
	else if (ft_strlen(r->s) == 0 && r->num == 0)
	{
		r->fmt++;
		return (sum);
	}
	else
		sum += ft_putstr3(r->s, r->wiedth);
	if (r->num != 0 && ft_strlen(r->s) == 0 && r->minus == 1)
	{
		r->fmt++;
		return (ft_size_print(r, 0));
	}
	else if ((r->num != 0) && (r->s != NULL) && r->minus == 1)
		sum += ft_size_print_minus(r, r->wiedth);
	else if (r->num != 0 && r->s == NULL && r->minus == 1)
		sum += ft_size_print_minus(r, r->wiedth);
	r->fmt++;
	return (sum);
}

int				ft_print_symb(t_arg *r, va_list ap)
{
	int			sum;

	sum = 0;
	if (*(r->fmt + 1) == 'c')
		sum += ft_prints_symb_help(r, ap, sum);
	else if (*(r->fmt + 1) == 's')
	{
		r->s = va_arg(ap, char*);
		if (r->wiedth != -1)
			return (ft_print_str(r));
		if ((r->num != 0) && (r->s != NULL) && r->minus == 0)
			sum += ft_size_print(r, ft_strlen(r->s));
		else if (r->num != 0 && r->s == NULL && r->minus == 0)
			sum += ft_size_print(r, 6);
		if (r->s == NULL)
			sum += ft_putstr("(null)");
		else
			sum += ft_putstr(r->s);
		if ((r->num != 0) && (r->s != NULL) && r->minus == 1)
			sum += ft_size_print_minus(r, ft_strlen(r->s));
		else if (r->num != 0 && r->s == NULL && r->minus == 1)
			sum += ft_size_print_minus(r, 6);
	}
	r->fmt++;
	return (sum);
}

static int		ft_print_ptr(t_arg *r, int sum)
{
	int			i;

	i = 0;
	if ((r->num > r->wiedth) && r->minus2 == 1)
		r->num = r->wiedth;
	if (r->num != 0 && r->minus2 == 1)
	{
		ft_putstr("0x");
		print_base(r->p, 16);
		sum += ft_size_print_minus(r, sum);
	}
	if (r->num != 0 && r->minus == 1 && r->minus2 == 0)
	{
		ft_putstr("0x");
		while (r->wiedth + 2 - sum > 0)
			sum += ft_putchar('0');
		print_base(r->p, 16);
		while (r->num - sum > 0)
			sum += ft_putchar(' ');
	}
	if (r->num !=0 && r->minus == 0 && r->minus2 == 0)
	{
		while (r->num - r->wiedth - 2 - i > 0)
			i += ft_putchar(' ');
		ft_putstr("0x");
		while (r->wiedth - sum + 2 > 0)
			sum += ft_putchar('0');
		print_base(r->p, 16);
	}
	r->fmt++;
	return (sum + i);
}

int				ft_print_symb2(t_arg *r, va_list ap)
{
	int			sum;

	sum = 0;
	if (*(r->fmt + 1) == '%')
	{
		if (r->num != 0 && r->minus == 0)
			sum += ft_size_print(r, 1);
		sum += ft_putchar('%');
		if (r->num != 0 && r->minus == 1)
			sum += ft_size_print_minus(r, 1);
	}
	if (*(r->fmt + 1) == 'p')
	{
		r->p = va_arg(ap, long int);
		sum += 2 + length_of_num(r->p, 16);
		if (r->wiedth != -1)
			return (ft_print_ptr(r ,sum));
		if (r->num != 0 && r->minus == 0)
			sum += ft_size_print2(r, sum);
		else
			ft_putstr("0x");
		print_base(r->p, 16);
		if (r->num != 0 && r->minus == 1)
			sum += ft_size_print_minus(r, sum);
	}
	r->fmt++;
	return (sum);
}
