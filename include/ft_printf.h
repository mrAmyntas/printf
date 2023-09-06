/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: basz <basz@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/22 20:21:47 by basz          #+#    #+#                 */
/*   Updated: 2021/02/20 16:12:47 by basz          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"
# include <stdint.h>

typedef	struct	s_info
{
	int			ret;
	int			pos;
	va_list		list;
	char		*str;
	int			left_just;
	int			width;
	int			prec;
	int			pad_zero;
	int			index;
}				t_info;
enum			e_conversions
{
	character,
	string,
	address,
	decimal_int,
	unsign_decimal_int,
	unsign_hexa_int_lc,
	unsign_hexa_int_uc,
	percent_char,
	unknown
};
typedef t_info	(*t_convers_fts_array)(t_info info);
int				ft_printf(const char *str, ...);
int				ft_assign_c(char c);
t_info			ft_start_convers(t_info info);
t_info			converse_c(t_info info);
t_info			converse_d(t_info info);
t_info			converse_u(t_info info);
t_info			converse_x_upper(t_info info);
t_info			converse_x(t_info info);
t_info			converse_percent_sign(t_info info);
t_info			converse_s(t_info info);
t_info			converse_p(t_info info);
int				ft_itoa_hex_address(void *pointer, int index, int put_add);
int				ft_itoa_base(long int x, int index, int upper, int base);
int				ft_itoa_base_len(long int dec_value, int index, int upper,
				int base);
int				ft_putnbr_unsignedint(unsigned int n);
t_info			ft_flags(t_info info);
char			*ft_malloc_string(char const *s1);
t_info			ft_write_string(t_info info, int len, char *str);
t_info			ft_padding(t_info info, int len);
int				ft_nbr_len(int n);
int				ft_write_nbr(int n, t_info info);
t_info			ft_padzero(int x, int len, t_info info);
t_info			ft_width_for_d(t_info info, int x, int len);
t_info			ft_width_for_u(t_info info, int len);
t_info			ft_padzero_unsigned(int len, t_info info);
#endif
