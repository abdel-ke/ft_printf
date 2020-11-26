/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ke <abdel-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:47:55 by abdel-ke          #+#    #+#             */
/*   Updated: 2020/01/14 14:13:12 by abdel-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			ft_return_type(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'c' || str[i] == 's' || str[i] == 'u'
		|| str[i] == 'd' || str[i] == 'i' || str[i] == 'p' || str[i] == 'X'
		|| str[i] == 'x' || str[i] == '%')
			return (str[i]);
		i++;
	}
	return (0);
}

const char		*ft_condition(const char *str, va_list ap,
t_returns *rtn, t_flags *t)
{
	if (*str == '%' && rtn->i == 0)
	{
		str++;
		if (ft_return_type((char*)str) == 'd' ||
		ft_return_type((char*)str) == 'i')
			ft_print_d((char *)str, t, ap, rtn);
		else if (ft_return_type((char*)str) == 's')
			ft_print_s((char*)str, ap, t, rtn);
		else if (ft_return_type((char*)str) == 'c')
			ft_print_c((char*)str, ap, t, rtn);
		else if (ft_return_type((char*)str) == 'x' ||
		ft_return_type((char*)str) == 'X')
			ft_print_x((char*)str, ap, t, rtn);
		else if (ft_return_type((char*)str) == 'u')
			ft_print_u((char *)str, t, ap, rtn);
		else if (ft_return_type((char*)str) == 'p')
			ft_print_p((char *)str, t, ap, rtn);
		else if (ft_return_type((char*)str) == '%')
			ft_print_pcentage((char*)str, ap, t, rtn);
		rtn->i = 1;
	}
	return (str);
}
