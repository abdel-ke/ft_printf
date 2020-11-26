/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ke <abdel-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 14:54:31 by abdel-ke          #+#    #+#             */
/*   Updated: 2020/01/14 13:44:22 by abdel-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialise_struct(t_flags *t)
{
	t->width = 0;
	t->point = 0;
	t->minus = 0;
	t->precesion = 0;
	t->args_d = 0;
	t->count = 0;
	t->args_minus = 0;
	t->zero = 0;
	t->check_prec = 0;
	t->hex_uns = 0;
}

void	struct_returns(t_returns *rtn)
{
	rtn->print_rtn = 0;
	rtn->i = 0;
}
