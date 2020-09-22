/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 12:43:41 by ggeri             #+#    #+#             */
/*   Updated: 2020/09/20 21:02:43 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

# define RED			"\x1b[31m"
# define GREEN			"\x1b[32m"
# define YELLOW			"\x1b[33m"
# define BLUE			"\x1b[34m"
# define MAGENTA		"\x1b[35m"
# define CYAN			"\x1b[36m"
# define RESET			"\x1b[0m"
# define ABS(i) (((i) < 0) ? -(i) : (i))
# define F_HH			1
# define F_H			2
# define F_L			3
# define F_LL			4
# define F_LD			5

typedef	struct			s_arg
{
	char				*fmt;
	char				*s;
	char				c;
	long int			p;
	unsigned int		u_i;
	unsigned char		hha;
	unsigned short		ha;
	unsigned long long	lla;
	unsigned long long	ull;
	unsigned long		la;
	int					i;
	char				hhi;
	short				hi;
	long long			lli;
	long long			lls;
	long				li;
	int					lnint;
	int					flg;
	int					hsh;
	int					num;
	int					zero;
	int					space;
	int					space2;
	int					move;
	int					plus;
	int					minus;
	int					minus2;
	int					wiedth;
	int					point;
	int					star;
	int					und_beh;
	double				f;
	double				lf;
	long double			ld;
	long double			ldd;
	int					precision;
	char				*fstr;
	long double			head;
	long double			tail;
	int					l1;
	int					l2;
	long				i_h;
	int					counter;
}						t_arg;

int						ft_printf(const char *format, ...);
char					*ft_strdup(const char *src);
int						ft_pow(int x, unsigned int y);
int						ft_atoi(const char *str);
size_t					ft_strlen(const char *s);
int						get_flag(t_arg *r, va_list ap, int ret);
int						ft_shorter_i(t_arg *r, va_list ap, int ret);
int						ft_print_base(t_arg *r, int sum);
int						pars(t_arg *r, va_list ap);
int						ft_putchar(char c);
int						ft_print_symb(t_arg *r, va_list ap);
int						ft_print_symb2(t_arg *r, va_list ap);
int						ft_putstr(const char *ptr);
void					print_base(unsigned long long num, unsigned \
						long long base);
void					print_base_i(long long num, long long base);
void					print_base_high(unsigned long long num, unsigned \
						long long base);
int						length_of_num(unsigned long long int i, int base);
int						length_of_num_i(long long int i, int base);
int						ft_print_hash(t_arg *r);
int						shorter_u_i(t_arg *r, int base, int sum);
int						shorter_u_i_high(t_arg *r, int base, int sum);
int						shorter_i(t_arg *r, int base, int sum);
int						ft_check_hash(t_arg *r);
int						ft_check_zero(t_arg *r);
int						ft_check_num(t_arg *r);
int						ft_check_space(t_arg *r);
int						ft_check_plus(t_arg *r);
int						ft_check_minus(t_arg *r);
int						ft_check_star(va_list ap, t_arg *r);
int						ft_check_undefined_behavior(t_arg *r);
int						ft_size_print(t_arg *r, int length);
int						ft_size_print2(t_arg *r, int length);
int						ft_size_print_minus(t_arg *r, int length);
void					ft_check_wiedth(t_arg *r);
int						ft_putstr2(const char *str, int size);
int						ft_putstr3(const char *str, int size);
int						ft_shorter_f(t_arg *r, va_list ap, int ret);
int						shorter_f(t_arg *r, int sum);
char					*ft_ltoa(int length, t_arg *r);
int						check_hash_help(t_arg *r);
int						m_s_u_i_high2(t_arg *r, int base, int sum);
int						h1_u_i_high2(t_arg *r, int base, int sum);
int						h1_u_i_high3(t_arg *r, int sum);
int						wiedth_help_i2(t_arg *r, int sum);
int						helper_i2(t_arg *r, int sum);
int						ft_print_symb22(t_arg *r, int sum);
int						ft_print_ptr2(t_arg *r, int sum);
int						ft_print_ptr3(t_arg *r, int sum);
int						ft_print_ptr4(t_arg *r, int sum);
int						ft_print_str2(t_arg *r, int sum);
int						ft_print_str3(t_arg *r, int sum);
int						ft_print_str4(t_arg *r);
int						m_s_u_i2(t_arg *r, int sum);
int						h1_u_i2(t_arg *r, int base, int sum);
int						h1_u_i3(t_arg *r, int sum);
int						h1_u_i4(t_arg *r, int sum);
int						h1_u_i5(t_arg *r, int base, int sum);
int						h1_u_i6(t_arg *r, int base, int sum);

#endif
