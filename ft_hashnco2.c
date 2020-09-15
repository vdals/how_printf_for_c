/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashnco2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 15:53:19 by ggeri             #+#    #+#             */
/*   Updated: 2020/09/14 17:21:03 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int		ft_check_minus(t_arg *r)
{
	if (*(r->fmt + 1) == '-')
	{
		while (*(r->fmt + 1) == '-')
			r->fmt++;
		return (1);
	}
	else
		return (0);
}

int		ft_check_star(va_list ap, t_arg *r)
{
	if (*(r->fmt + 1) == '*')
	{
		r->fmt++;
		r->num = va_arg(ap, int);
	}
	return (r->num);
}

void	ft_check_wiedth(t_arg *r)
{
	if (*(r->fmt + 1) == '.')
	{
		r->point = 1;
		r->fmt++;
		r->space2 = ft_check_space(r);
		if (r->space2 == 1 && r->num == 0)
		{
			r->minus2 = ft_check_minus(r);
			r->zero = ft_check_zero(r);
			r->num = ft_check_num(r);
		}
		else if (r->space2 == 1 && r->num != 0)
		{
			r->minus2 = ft_check_minus(r);
			r->zero = ft_check_zero(r);
		}
		else
		{
			r->minus2 = ft_check_minus(r);
			r->zero = ft_check_zero(r) - 1;
			r->wiedth = ft_check_num(r);
		}
	}
}
