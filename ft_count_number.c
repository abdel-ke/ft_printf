/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ke <abdel-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 12:55:25 by abdel-ke          #+#    #+#             */
/*   Updated: 2020/01/13 22:22:29 by abdel-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_count(long long nbr)
{
	int rslt;

	rslt = 0;
	while (nbr)
	{
		nbr /= 10;
		rslt++;
	}
	if (rslt == 0)
		return (rslt = 1);
	return (rslt);
}
