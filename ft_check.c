/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ke <abdel-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 16:34:46 by abdel-ke          #+#    #+#             */
/*   Updated: 2020/01/14 12:39:22 by abdel-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_stock_width(char *str, char c, va_list ap, t_flags *t)
{
	if (c == '0' && t->width == 0)
		t->zero = 1;
	else if (c >= '0' && c <= '9')
		t->width = t->width * 10 + (c - '0');
	if (c == '*')
	{
		t->width = va_arg(ap, int);
		if (t->width < 0)
		{
			t->width = t->width * -1;
			t->minus = 1;
		}
	}
	if (c == '-')
		ft_minus(str, t);
}

void	ft_stock_prec(char c, va_list ap, t_flags *t)
{
	if (c == '0' && t->precesion == 0)
		t->zero = 2;
	if (c == '*')
	{
		t->precesion = va_arg(ap, int);
		if (t->precesion < 0)
			t->check_prec = 1;
	}
	if (c >= '0' && c <= '9')
		t->precesion = t->precesion * 10 + (c - '0');
	if (c == '-')
		t->minus = 2;
}
