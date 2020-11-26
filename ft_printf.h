/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ke <abdel-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 13:00:32 by abdel-ke          #+#    #+#             */
/*   Updated: 2020/01/14 14:05:03 by abdel-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef	struct		s_flags
{
	unsigned int	hex_uns;
	unsigned long	p;
	int				width;
	int				precesion;
	int				point;
	int				minus;
	int				check_prec;
	int				args_d;
	int				args_minus;
	int				count;
	int				zero;
	char			*s;
}					t_flags;

typedef	struct		s_returns
{
	int	print_rtn;
	int i;
}					t_returns;

int					ft_printf(const char *str, ...);
void				ft_stock(char *str, t_flags *t, va_list ap);
void				initialise_struct(t_flags *t);
void				struct_returns(t_returns *rtn);
int					ft_count(long long nbr);
int					ft_point(char *str, t_flags *t);
void				ft_print_d(char *str, t_flags *t, va_list ap,
t_returns *rtn);
void				ft_stock_number(char c, t_flags *t);
void				ft_stock_width(char *str, char c, va_list ap, t_flags *t);
void				ft_stock_prec(char c, va_list ap, t_flags *t);
void				ft_minus(char *str, t_flags *t);
void				ft_putnbr(long long nbr, t_returns *rtn);
void				ft_putchar(char c, t_returns *rtn);
int					ft_type(char str);
char				ft_return_type(char *str);
void				ft_write_d_n(t_flags *t, t_returns *rtn);
void				ft_write_d_n_minus(t_flags *t, t_returns *rtn);
void				ft_finish_d(t_flags *t, t_returns *rtn);
void				ft_write_d_if_minus(t_flags *t, t_returns *rtn);
void				ft_write_d_if_zero(t_flags *t, t_returns *rtn, int width,
int precesion);
void				ft_write_d_if_not_minus(t_flags *t, t_returns *rtn);
void				ft_print_s(char *str, va_list ap, t_flags *t,
t_returns *rtn);
void				ft_args_s(va_list ap, t_flags *t, t_returns *rtn);
int					ft_strlen(char *str);
void				ft_write_s_n(t_flags *t, t_returns *rtn);
void				ft_putstr(char *str, t_returns *rtn);
void				ft_finish(t_flags *t, t_returns *rtn, int i);
void				ft_print_if_zero(char c, t_flags *t, t_returns *rtn, int i);
void				ft_print_c(char *str, va_list ap, t_flags *t,
t_returns *rtn);
void				ft_print_x(char *str, va_list ap, t_flags *t,
t_returns *rtn);
void				ft_write_x_if_not_minus(t_flags *t, t_returns *rtn);
void				ft_hexa(unsigned long d, char c, t_flags *t);
void				ft_reverse(t_flags *t);
void				ft_finish_x(t_flags *t, t_returns *rtn);
void				ft_write_x_n(t_flags *t, t_returns *rtn);
void				ft_print_u(char *str, t_flags *t, va_list ap,
t_returns *rtn);
void				ft_args_u(va_list ap, t_flags *t, t_returns *rtn);
void				ft_finish_u(t_flags *t, t_returns *rtn);
void				ft_write_u_n_minus(t_flags *t, t_returns *rtn);
void				ft_write_u_n(t_flags *t, t_returns *rtn);
void				ft_write_u_if_minus(t_flags *t, t_returns *rtn);
void				ft_write_u_if_not_minus(t_flags *t, t_returns *rtn);
void				ft_write_u_if_zero(t_flags *t, t_returns *rtn, int width,
int precesion);
void				ft_putnbr_u(unsigned int n, t_returns *rtn);
void				ft_print_p(char *str, t_flags *t, va_list ap,
t_returns *rtn);
void				ft_print_p_if_minus(t_flags *t, t_returns *rtn);
void				ft_print_pcentage(char *str, va_list ap,
t_flags *t, t_returns *rtn);
const char			*ft_condition(const char *str, va_list ap,
t_returns *rtn, t_flags *t);
#endif
