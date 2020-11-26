/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ke <abdel-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 21:54:32 by abdel-ke          #+#    #+#             */
/*   Updated: 2020/01/14 12:06:51 by abdel-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_c(char *str, va_list ap, t_flags *t, t_returns *rtn)
{
	ft_stock(str, t, ap);
	t->args_d = va_arg(ap, int);
	if (!t->minus)
	{
		while (t->width-- > 1)
			ft_putchar(' ', rtn);
		ft_putchar(t->args_d, rtn);
	}
	else
	{
		ft_putchar(t->args_d, rtn);
		while (t->width-- > 1)
			ft_putchar(' ', rtn);
	}
}
