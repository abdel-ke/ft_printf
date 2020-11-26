/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ke <abdel-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 18:19:11 by abdel-ke          #+#    #+#             */
/*   Updated: 2020/01/14 12:08:00 by abdel-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_p_if_minus(t_flags *t, t_returns *rtn)
{
	while (t->width-- > t->count)
		ft_putchar(' ', rtn);
	ft_putstr("0x", rtn);
	if (!t->p)
		ft_putchar('0', rtn);
	else
		ft_putstr(t->s, rtn);
}

void	ft_print_p(char *str, t_flags *t, va_list ap, t_returns *rtn)
{
	ft_stock(str, t, ap);
	t->p = va_arg(ap, unsigned long);
	ft_hexa(t->p, 'x', t);
	t->count = ft_strlen(t->s) + 2;
	t->count = t->p == 0 ? ++t->count : t->count;
	if (!t->minus)
		ft_print_p_if_minus(t, rtn);
	else
	{
		ft_putstr("0x", rtn);
		if (!t->p)
			ft_putchar('0', rtn);
		else
			ft_putstr(t->s, rtn);
		while (t->width-- > t->count)
			ft_putchar(' ', rtn);
	}
	free(t->s);
}
