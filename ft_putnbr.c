/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ke <abdel-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 15:37:05 by abdel-ke          #+#    #+#             */
/*   Updated: 2020/01/14 12:11:33 by abdel-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putnbr(long long nbr, t_returns *rtn)
{
	if (nbr < 0)
		nbr *= -1;
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10, rtn);
		ft_putchar(nbr % 10 + '0', rtn);
	}
	else
		ft_putchar(nbr % 10 + '0', rtn);
}
