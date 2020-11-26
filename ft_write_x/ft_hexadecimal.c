/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ke <abdel-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 16:36:38 by abdel-ke          #+#    #+#             */
/*   Updated: 2020/01/13 22:20:48 by abdel-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_reverse(t_flags *t)
{
	int		i;
	int		j;
	char	temp;

	i = ft_strlen(t->s) - 1;
	j = 0;
	while (j < i)
	{
		temp = t->s[j];
		t->s[j++] = t->s[i];
		t->s[i--] = temp;
	}
}

int		count_number_hex_unsa(unsigned long d)
{
	unsigned long count;

	count = 0;
	while (d != 0)
	{
		d /= 16;
		count++;
	}
	return (count);
}

void	ft_hexa(unsigned long d, char c, t_flags *t)
{
	int	ss;
	int i;

	i = 0;
	t->s = (char *)malloc(count_number_hex_unsa(d) * sizeof(char) + 1);
	while (d != 0)
	{
		ss = d % 16;
		d /= 16;
		if (c == 'x')
			if (ss >= 10)
				t->s[i] = ss + 'W';
			else
				t->s[i] = ss + '0';
		else if (ss >= 10)
			t->s[i] = ss + '7';
		else
			t->s[i] = ss + '0';
		i++;
	}
	t->s[i] = '\0';
	ft_reverse(t);
}
