/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ke <abdel-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 12:12:59 by abdel-ke          #+#    #+#             */
/*   Updated: 2020/01/13 22:23:01 by abdel-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_minus(char *str, t_flags *t)
{
	int i;
	int j;

	i = 0;
	j = ft_point(str, t);
	while (str[i] && !ft_type(str[i]))
	{
		if (str[i] == '-' && i < j)
			t->minus = 1;
		i++;
	}
}
