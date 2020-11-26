/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ke <abdel-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 16:09:53 by abdel-ke          #+#    #+#             */
/*   Updated: 2020/01/14 12:08:43 by abdel-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_s(char *str, va_list ap, t_flags *t, t_returns *rtn)
{
	ft_stock(str, t, ap);
	t->s = va_arg(ap, char*);
	if (t->s == NULL)
		t->s = "(null)";
	t->count = ft_strlen(t->s);
	ft_finish(t, rtn, 0);
}
