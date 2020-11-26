/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ke <abdel-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 18:15:32 by abdel-ke          #+#    #+#             */
/*   Updated: 2020/01/14 14:05:27 by abdel-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	t_flags		tt;
	t_flags		*t;
	t_returns	in;
	t_returns	*rtn;

	va_start(ap, str);
	t = &tt;
	rtn = &in;
	struct_returns(rtn);
	while (*str)
	{
		str = ft_condition(str, ap, rtn, t);
		if (rtn->i == 0)
			ft_putchar(*str, rtn);
		if (ft_type(*str))
			rtn->i = 0;
		str++;
	}
	va_end(ap);
	return (rtn->print_rtn);
}
