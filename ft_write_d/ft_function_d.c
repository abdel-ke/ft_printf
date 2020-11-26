/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ke <abdel-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 21:54:19 by abdel-ke          #+#    #+#             */
/*   Updated: 2020/01/14 12:07:31 by abdel-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_write_d_n_minus(t_flags *t, t_returns *rtn)
{
	if (t->minus == 1)
	{
		if (t->args_minus == 1)
		{
			ft_putchar('-', rtn);
			t->count++;
		}
		ft_putnbr((long)t->args_d, rtn);
		while (t->width > t->count++)
			ft_putchar(' ', rtn);
	}
}

void	ft_write_d_n(t_flags *t, t_returns *rtn)
{
	if (!t->minus && !t->zero)
	{
		t->count = t->args_minus == 1 ? ++t->count : t->count;
		while (t->width > t->count++)
			ft_putchar(' ', rtn);
		if (t->args_minus == 1)
			ft_putchar('-', rtn);
		ft_putnbr((long)t->args_d, rtn);
	}
	else if (!t->minus)
	{
		if (t->args_minus == 1)
		{
			ft_putchar('-', rtn);
			t->count++;
		}
		while (t->width > t->count++)
			ft_putchar('0', rtn);
		ft_putnbr((long)t->args_d, rtn);
	}
	else if (t->minus)
		ft_write_d_n_minus(t, rtn);
}

void	ft_write_d_if_minus(t_flags *t, t_returns *rtn)
{
	while (t->width > (t->precesion + t->args_minus)
	&& (t->width > (t->count + t->args_minus)))
	{
		ft_putchar(' ', rtn);
		t->width--;
	}
	if (t->args_minus)
		ft_putchar('-', rtn);
	while (t->precesion-- > t->count)
		ft_putchar('0', rtn);
	ft_putnbr((long)t->args_d, rtn);
}

void	ft_write_d_if_not_minus(t_flags *t, t_returns *rtn)
{
	if (t->args_minus)
		ft_putchar('-', rtn);
	while (t->precesion > t->count)
	{
		ft_putchar('0', rtn);
		t->count++;
	}
	ft_putnbr((long)t->args_d, rtn);
	while (t->width > (t->precesion + t->args_minus)
	&& (t->width > (t->count + t->args_minus)) && t->precesion)
	{
		ft_putchar(' ', rtn);
		t->width--;
	}
	while (t->width > (t->count + t->args_minus) && !t->precesion)
	{
		ft_putchar(' ', rtn);
		t->width--;
	}
}

void	ft_write_d_if_zero(t_flags *t, t_returns *rtn, int width, int precesion)
{
	if (!t->minus)
	{
		while (width-- > precesion)
			ft_putchar(' ', rtn);
		while (precesion > t->args_d++)
			ft_putchar('0', rtn);
	}
	else
	{
		while (precesion > t->args_d++)
			ft_putchar('0', rtn);
		while (width-- > precesion)
			ft_putchar(' ', rtn);
	}
}
