/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ke <abdel-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 21:15:27 by abdel-ke          #+#    #+#             */
/*   Updated: 2020/01/14 12:39:22 by abdel-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_stock(char *str, t_flags *t, va_list ap)
{
	int point;
	int i;

	initialise_struct(t);
	point = ft_point(str, t);
	i = 0;
	while (str[i] && !ft_type(str[i]))
	{
		if (i < point)
			ft_stock_width(str, str[i], ap, t);
		else
			ft_stock_prec(str[i], ap, t);
		i++;
	}
}
