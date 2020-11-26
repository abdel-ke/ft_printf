/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ke <abdel-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:07:04 by abdel-ke          #+#    #+#             */
/*   Updated: 2020/01/14 12:37:40 by abdel-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_if_zero(char c, t_flags *t, t_returns *rtn, int i)
{
	if (t->width == t->precesion && t->count < t->width)
		ft_putchar(c, rtn);
	while (t->width-- > t->precesion)
		ft_putchar(c, rtn);
	while (t->precesion-- && t->count--)
		ft_putchar(t->s[i++], rtn);
}

void	ft_not_minus_s(t_flags *t, t_returns *rtn, int i)
{
	if (t->zero == 1)
		ft_print_if_zero('0', t, rtn, 0);
	else if (t->zero == 2)
		ft_print_if_zero(' ', t, rtn, 0);
	else if (t->count >= t->precesion)
	{
		while (t->width-- > t->precesion)
			ft_putchar(' ', rtn);
		while (t->precesion > i)
			ft_putchar(t->s[i++], rtn);
	}
	else
	{
		while (t->width-- > t->count)
			ft_putchar(' ', rtn);
		ft_putstr(t->s, rtn);
	}
}

void	ft_write_s_n(t_flags *t, t_returns *rtn)
{
	if (!t->zero && !t->minus)
		while (t->width > t->count)
		{
			ft_putchar(' ', rtn);
			t->count++;
		}
	else if (!t->minus)
		while (t->width > t->count)
		{
			ft_putchar('0', rtn);
			t->count++;
		}
	ft_putstr(t->s, rtn);
	if (t->minus)
		while (t->width > t->count)
		{
			ft_putchar(' ', rtn);
			t->count++;
		}
}

void	ft_finish(t_flags *t, t_returns *rtn, int i)
{
	if (!t->point)
		ft_write_s_n(t, rtn);
	else
	{
		if (t->check_prec)
			ft_write_s_n(t, rtn);
		else
		{
			if (t->minus == 0)
				ft_not_minus_s(t, rtn, 0);
			else if (t->minus == 1)
			{
				while (t->precesion-- && t->count--)
					ft_putchar(t->s[i++], rtn);
				while (t->width > i++)
					ft_putchar(' ', rtn);
			}
			else
				while (t->precesion--)
					ft_putchar(' ', rtn);
		}
	}
}
