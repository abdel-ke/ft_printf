/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ke <abdel-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:49:43 by abdel-ke          #+#    #+#             */
/*   Updated: 2020/01/14 12:07:37 by abdel-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_d(char *str, t_flags *t, va_list ap, t_returns *rtn)
{
	ft_stock(str, t, ap);
	t->args_d = va_arg(ap, int);
	t->count = ft_count(t->args_d);
	if (t->args_d < 0)
		t->args_minus = 1;
	ft_finish_d(t, rtn);
}
