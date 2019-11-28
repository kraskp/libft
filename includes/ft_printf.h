/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:58:25 by kkraszew          #+#    #+#             */
/*   Updated: 2019/11/28 19:39:25 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "color.h"
# include <stdarg.h>
# include <errno.h>
# include <string.h>
# define BUFF_PRINTF 128

typedef struct				s_pf
{
	va_list					va_lst;
	va_list					va_copy;
	int						buff_count;
	unsigned char			buff[BUFF_PRINTF];
	int						count;
	unsigned char			*str;
	unsigned long			ul_nb;
	unsigned long			ful_nb;
	long double				fl_nb;
	int						expo;
	char					hash;
	char					space;
	char					zero;
	char					sign;
	char					apost;
	int						field;
	char					dot;
	int						preci;
	char					uppercase;
	char					*psign;
	unsigned char			base;
	size_t					length;
	char					conv;
}							t_pf;

int							ft_printf(const char *str, ...);
int							ft_dprintf(int fd, const char *str, ...);
int							ft_sprintf(unsigned char **dest,
										const char *format, ...);
void						conv_char(t_pf *lst);
void						conv_int(t_pf *lst);
void						conv_string(t_pf *lst);
void						conv_double(t_pf *lst, unsigned long *nb, int i);
void						conv_other(t_pf *lst);
int							conv_color(t_pf *lst, char *str);
t_pf						*lst_init(void);
int							lst_putoption(t_pf *lst, char *str, int index);
void						lst_zero(t_pf *lst);
void						lst_putint(t_pf *lst);
void						lst_putdouble(t_pf *lst);
void						printf_error(t_pf *lst, char *str);
int							ulen_base(unsigned long nb, size_t base);
void						convert_buff(t_pf *lst, void *tmp, size_t len);
void						put_buff(t_pf *lst, void *tmp, size_t len,
										size_t index);
void						put_itoa(t_pf *lst, unsigned long n);
void						put_prefix(t_pf *lst, int len, int nb, int point);

#endif
