/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ke <abdel-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 21:53:18 by abdel-ke          #+#    #+#             */
/*   Updated: 2020/01/14 12:32:31 by abdel-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_finish_d(t_flags *t, t_returns *rtn)
{
	if (!t->point)
		ft_write_d_n(t, rtn);
	else if (t->check_prec == 1)
		ft_write_d_n(t, rtn);
	else if (!t->args_d)
		if (t->precesion < 0)
			ft_write_d_if_zero(t, rtn, t->width, 1);
		else
			ft_write_d_if_zero(t, rtn, t->width, t->precesion);
	else if (!t->minus)
		ft_write_d_if_minus(t, rtn);
	else
		ft_write_d_if_not_minus(t, rtn);
}
