/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ke <abdel-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 20:57:32 by abdel-ke          #+#    #+#             */
/*   Updated: 2020/01/14 12:10:15 by abdel-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_x(char *str, va_list ap, t_flags *t, t_returns *rtn)
{
	char c;

	c = ft_return_type(str);
	ft_stock(str, t, ap);
	t->hex_uns = va_arg(ap, unsigned int);
	ft_hexa(t->hex_uns, c, t);
	t->count = ft_strlen(t->s);
	ft_finish_x(t, rtn);
	free(t->s);
}
