/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ke <abdel-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 21:02:07 by abdel-ke          #+#    #+#             */
/*   Updated: 2020/01/14 12:09:52 by abdel-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_zero(t_flags *t, t_returns *rtn)
{
	if (t->minus)
	{
		ft_putstr(t->s, rtn);
		while (t->width-- > t->count)
			ft_putchar(' ', rtn);
	}
	else
	{
		while (t->width-- > t->count)
			ft_putchar('0', rtn);
		ft_putstr(t->s, rtn);
	}
}

void	ft_not_zero(t_flags *t, t_returns *rtn)
{
	if (!t->minus)
	{
		t->count = t->count != 0 ? t->count : 1;
		while (t->width-- > t->count)
			ft_putchar(' ', rtn);
		if (!t->hex_uns)
			ft_putchar('0', rtn);
		ft_putstr(t->s, rtn);
	}
	else
	{
		ft_putstr(t->s, rtn);
		while (t->width-- > t->count)
			ft_putchar(' ', rtn);
	}
}

void	ft_write_x_n(t_flags *t, t_returns *rtn)
{
	if (!t->zero)
		ft_not_zero(t, rtn);
	else
		ft_zero(t, rtn);
}

void	ft_write_x_if_not_minus(t_flags *t, t_returns *rtn)
{
	while (t->width-- > t->precesion && t->width > t->count)
		ft_putchar(' ', rtn);
	while (t->precesion > t->count++)
		ft_putchar('0', rtn);
	ft_putstr(t->s, rtn);
}

void	ft_finish_x(t_flags *t, t_returns *rtn)
{
	if (!t->point)
		ft_write_x_n(t, rtn);
	else
	{
		if (!t->minus)
			ft_write_x_if_not_minus(t, rtn);
		else if (t->minus == 1)
		{
			while (t->precesion > t->count++)
				ft_putchar('0', rtn);
			ft_putstr(t->s, rtn);
			while (t->width > t->precesion && t->width > t->count - 1)
			{
				ft_putchar(' ', rtn);
				t->width--;
			}
		}
		else
		{
			ft_putstr(t->s, rtn);
			while (t->precesion-- > t->count)
				ft_putchar(' ', rtn);
		}
	}
}
