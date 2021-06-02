/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelamran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 16:23:31 by aelamran          #+#    #+#             */
/*   Updated: 2019/01/18 20:20:59 by aelamran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <locale.h>
# include "libft.h"

# define RED "\e[31m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define BLUE "\e[34m"
# define CYAN "\e[36m"
# define EOC "\e[0m"

typedef struct		s_format
{
	char			*flag;
	int				field_width;
	int				precision;
	char			*length;
	char			conversion;
}					t_format;

typedef struct		s_print
{
	char			sign;
	char			space;
	char			*prefix;
	int				spaces;
	int				zeros;
}					t_print;

typedef	struct		s_number
{
	intmax_t		nbr;
	int				len;
	int				negative;
}					t_number;

typedef struct		s_float
{
	int				sign;
	int				exponent;
	char			*mantissa;
	int				length;
}					t_float;

typedef	struct		s_fltnbr
{
	char			sign;
	char			*decimal;
	int				lengthd;
	char			*fraction;
}					t_fltnbr;

typedef	struct		s_read
{
	unsigned long	mantissa:63;
	int				integer:1;
	unsigned int	exp:15;
	int				sign:1;
}					t_read;

union				u_type
{
	long	double	nbr;
	t_read			rd;
}					u_type;

typedef	struct		s_read_double
{
	long			mantissa:52;
	unsigned int	exp:11;
	int				sign:1;
}					t_read_double;

union				u_typed
{
	double			nbr;
	t_read_double	rd_double;
}					u_typed;

typedef	struct		s_read_float
{
	long			mantissa:23;
	unsigned int	exp:8;
	int				sign:1;
}					t_read_float;

union				u_typef
{
	float			nb;
	t_read_float	rd_float;
}					u_typef;

typedef	struct		s_multi
{
	char			nbr;
	int				anas;
}					t_multi;

typedef	struct		s_addition
{
	char			nbr;
	int				anas;
}					t_addition;

int					ft_printf(const char *format, ...);
void				ft_printcolor(const char **format);
int					ft_readarg(va_list ap, t_format *fmt);

char				*ft_getflags(const char **format);
int					ft_isprecision(const char *format);
char				*ft_getlength(const char **format);
t_format			*ft_setformat(const char **format, va_list ap);

int					ft_write_formatint(t_format *fmt, intmax_t nbr);
int					ft_write_formatbin(t_format *fmt, int c);
int					ft_write_formatchar(t_format *fmt, char *str);
int					ft_write_formatwstr(t_format *fmt, wchar_t *str);
int					ft_write_formatchr(t_format *fmt, int c);
int					ft_write_formatwchr(t_format *fmt, wchar_t c);
int					ft_write_formatdouble(t_format *fmt, double nbr);
int					ft_write_formatldouble(t_format *fmt, long double nbr);
int					ft_write_formatinf(t_format *fmt, char *str, int sign);

void				ft_write_spaces(int size);
void				ft_write_zeros(int size);
int					ft_write_float(t_fltnbr *fltn, t_format *fmt);

t_number			*ft_newls(intmax_t nbr, t_format *fmt);
t_print				*ft_newlist(void);

void				ft_printnumber(t_number *nbr, t_format *fmt);
void				ft_printbin(int nbr, int count);
void				ft_putnbr_int(intmax_t nbr, t_format *fmt);
void				ft_putnbr_uint(uintmax_t nbr, t_format *fmt);
void				ft_putnbr_octal(uintmax_t nbr, t_format *fmt);
void				ft_putnbr_hex(uintmax_t nbr, t_format *fmt);
void				ft_putwchar(wchar_t c);

void				ft_toctal(uintmax_t n);
void				ft_tohex(uintmax_t nbr, char conversion);

int					ft_count(intmax_t nbr, int base);
int					ft_ucount(uintmax_t nbr, int base);
int					ft_countnbr(intmax_t nbr, t_format *fmt);
int					ft_chrlen(wchar_t c);
int					ft_wstrlen(wchar_t *str);

char				*ft_setprefix(t_format *fmt, t_number *nbr);

int					ft_retvalue(t_number *nbr, t_print *pnt, t_format *fmt);

t_float				*ft_setdouble(double nbr);
t_float				*ft_setldouble(long double nbr);
char				*ft_calcfloat(t_float *flt);

t_fltnbr			*ft_getdouble(t_float *flt);

t_float				*ft_inifloat(void);

char				*ft_getmantissad(long mantissa, int exp);
char				*ft_getmantissald(unsigned long mantissa, int integer);

char				**ft_getitall(char *man);

t_multi				*ft_multiplication(int anas, int s, int c);
char				*ft_join(char *str, char c);
char				*ft_multi(char *s1, char *s2);
char				*ft_addition(char *s1, char *s2);
void				ft_eliminate_zeros(char **str);
char				*ft_makefirst(char **str, int exp);
t_print				*ft_printit(t_format *fmt, t_fltnbr *flt);

int					ft_getlast(char *str);
char				*ft_getline(char *s1, char c);
int					ft_isgreater(char *fraction);
char				*ft_add_toit(char *s);

void				ft_dorounding(t_fltnbr *nb, t_format *fmt);
int					ft_roundit(char **str, int i);

#endif
