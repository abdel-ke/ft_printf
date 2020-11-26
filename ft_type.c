/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ke <abdel-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:01:56 by abdel-ke          #+#    #+#             */
/*   Updated: 2020/01/13 22:34:28 by abdel-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type(char str)
{
	if (str == 'c' || str == 's' || str == 'u' || str == 'd' ||
	str == 'i' || str == 'p' || str == 'X' || str == 'x' || str == '%')
		return (1);
	return (0);
}
