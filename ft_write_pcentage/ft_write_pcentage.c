/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_pcentage.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ke <abdel-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 17:37:20 by abdel-ke          #+#    #+#             */
/*   Updated: 2020/01/14 12:08:10 by abdel-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_pcentage(char *str, va_list ap, t_flags *t, t_returns *rtn)
{
	ft_stock(str, t, ap);
	if (!t->minus)
	{
		if (!t->zero)
		{
			while (t->width-- > 1)
				ft_putchar(' ', rtn);
			ft_putchar('%', rtn);
		}
		else
		{
			while (t->width-- > 1)
				ft_putchar('0', rtn);
			ft_putchar('%', rtn);
		}
	}
	else
	{
		ft_putchar('%', rtn);
		while (t->width-- > 1)
			ft_putchar(' ', rtn);
	}
}
