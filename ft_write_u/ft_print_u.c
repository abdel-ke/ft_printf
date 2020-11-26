/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ke <abdel-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:49:43 by abdel-ke          #+#    #+#             */
/*   Updated: 2020/01/14 12:32:31 by abdel-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr_u(unsigned int n, t_returns *rtn)
{
	if (n > 9)
	{
		ft_putnbr_u(n / 10, rtn);
		ft_putchar(n % 10 + '0', rtn);
	}
	else
		ft_putchar(n % 10 + '0', rtn);
}

void	ft_finish_u(t_flags *t, t_returns *rtn)
{
	if (!t->point)
		ft_write_u_n(t, rtn);
	else if (t->check_prec == 1)
		ft_write_u_n(t, rtn);
	else if (!t->hex_uns)
		if (t->precesion < 0)
			ft_write_u_if_zero(t, rtn, t->width, 1);
		else
			ft_write_u_if_zero(t, rtn, t->width, t->precesion);
	else if (!t->minus)
		ft_write_u_if_minus(t, rtn);
	else
		ft_write_u_if_not_minus(t, rtn);
}

void	ft_print_u(char *str, t_flags *t, va_list ap, t_returns *rtn)
{
	ft_stock(str, t, ap);
	t->hex_uns = va_arg(ap, unsigned int);
	t->count = ft_count(t->hex_uns);
	ft_finish_u(t, rtn);
}
