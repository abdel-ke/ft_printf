/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ke <abdel-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 12:17:21 by abdel-ke          #+#    #+#             */
/*   Updated: 2020/01/14 12:09:13 by abdel-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_write_u_n_minus(t_flags *t, t_returns *rtn)
{
	if (t->minus == 1)
	{
		ft_putnbr_u(t->hex_uns, rtn);
		while (t->width > t->count++)
			ft_putchar(' ', rtn);
	}
}

void	ft_write_u_n(t_flags *t, t_returns *rtn)
{
	if (!t->minus && !t->zero)
	{
		while (t->width > t->count++)
			ft_putchar(' ', rtn);
		ft_putnbr_u(t->hex_uns, rtn);
	}
	else if (!t->minus)
	{
		while (t->width > t->count++)
			ft_putchar('0', rtn);
		ft_putnbr_u(t->hex_uns, rtn);
	}
	else if (t->minus)
		ft_write_u_n_minus(t, rtn);
}

void	ft_write_u_if_minus(t_flags *t, t_returns *rtn)
{
	while (t->width > t->precesion && t->width > t->count)
	{
		ft_putchar(' ', rtn);
		t->width--;
	}
	while (t->precesion-- > t->count)
		ft_putchar('0', rtn);
	ft_putnbr_u(t->hex_uns, rtn);
}

void	ft_write_u_if_not_minus(t_flags *t, t_returns *rtn)
{
	while (t->precesion > t->count)
	{
		ft_putchar('0', rtn);
		t->count++;
	}
	ft_putnbr_u(t->hex_uns, rtn);
	while (t->width > t->precesion && t->width > t->count && t->precesion)
	{
		ft_putchar(' ', rtn);
		t->width--;
	}
	while (t->width > t->count && !t->precesion)
	{
		ft_putchar(' ', rtn);
		t->width--;
	}
}

void	ft_write_u_if_zero(t_flags *t, t_returns *rtn, int width, int precesion)
{
	if (!t->minus)
	{
		while (width-- > precesion)
			ft_putchar(' ', rtn);
		while ((unsigned int)precesion > t->hex_uns++)
			ft_putchar('0', rtn);
	}
	else
	{
		while ((unsigned int)precesion > t->hex_uns++)
			ft_putchar('0', rtn);
		while (width-- > precesion)
			ft_putchar(' ', rtn);
	}
}
