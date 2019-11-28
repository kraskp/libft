/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:32:42 by kkraszew          #+#    #+#             */
/*   Updated: 2019/11/24 19:08:38 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	3.5.1	find_conv(lst, (str + i + j), 0)
** 			str = (char *)format + i + j
**			ret = 0
**			lst = lst
**	1	set ret to lst_putoption(lst, str, 1), i.e., the position on str
**	2	check for 'f' or 'F' conversions, if there goto lst_putdouble();
**	3	check for 's' conversion, if there goto conv_string();
**	4	check for int conversions, if so goto conv_int();
**	5	check for @, if so goto conv_other();
**	6	check for '{', if so conv_color, move position on str
**	7	otherwise if conversion isn't 0, conv_char
*/

static	int	find_conv(t_pf *lst, char *str, int ret)
{
	ret = lst_putoption(lst, str, 1);
	if (lst->conv == 'f' || lst->conv == 'F')
		lst_putdouble(lst);
	else if (lst->conv == 's')
		conv_string(lst);
	else if (lst->conv == 'd' || lst->conv == 'i' || lst->conv == 'x' ||
			lst->conv == 'X' || lst->conv == 'o' || lst->conv == 'u' ||
			lst->conv == 'p' || lst->conv == 'b' || lst->conv == 'B')
		conv_int(lst);
	else if (lst->conv == '@')
		conv_other(lst);
	else if (lst->conv == '{')
		ret += conv_color(lst, str + ret);
	else if (lst->conv != 0)
		conv_char(lst);
	return (ret);
}

/*
**	3	ftprintf_base is where things get going
** 		(char *)format = str
**	3.1	copy lst->va_lst to lst->va_copy
**	3.2	traverse str until reaching '\0'
**	3.3 increment j when str[i + j] isn't '\0' or %
**	3.4	pass lst, str + i, j, 0 to put_buff();
**	3.5 if str[i+j] is %, increase i by result of find_conv();
**		pass lst, (str + i + j), 0 to find_conv();
**	3.6	increase i by j;
**	3.7	end lst->va_lst;
**	3.8	end lst->va_copy;
*/

static void	ftprintf_base(char *str, t_pf *lst, size_t i, size_t j)
{
	va_copy(lst->va_copy, lst->va_lst);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && str[i + j] != '%')
			j++;
		put_buff(lst, str + i, j, 0);
		if (str[i + j] == '%')
			i += find_conv(lst, (str + i + j), 0);
		i += j;
	}
	va_end(lst->va_lst);
	va_end(lst->va_copy);
}

/*
**	ft_sprintf operates akin to ft_printf, but composes a string with
**	the same text that would be printed if format was used on printf,
**	but instead of being printed, the content is stored as a C string
**	in the buffer pointed by str
*/

int			ft_sprintf(unsigned char **dest, const char *format, ...)
{
	t_pf	*lst;

	lst = lst_init();
	va_start(lst->va_lst, format);
	ftprintf_base((char*)format, lst, 0, 0);
	convert_buff(lst, NULL, 0);
	*dest = lst->str;
	return (lst->count + lst->buff_count);
}

/*
**	ft_dprintf operates akin to ft_printf, except that it output to a
**	file descriptor fd instead of to a stdio stream
*/

int			ft_dprintf(int fd, const char *format, ...)
{
	t_pf	*lst;

	lst = lst_init();
	va_start(lst->va_lst, format);
	ftprintf_base((char*)format, lst, 0, 0);
	if (lst->count != 0)
		write(fd, lst->str, lst->count);
	if (lst->buff_count != 0)
		write(fd, lst->buff, lst->buff_count);
	if (lst->str != NULL)
		free(lst->str);
	free(lst);
	return (lst->count + lst->buff_count);
}

/*
** This is where it all begins.
** 1	Initialize the list with lst_int().
** 2	Initialize a variable argument list (lst->va_lst).
**		Initializes lst->va_lst to retrieve additional args after param format)
** 3	Cast format as char * and send format, lst, size_t 0, & size_0
** 		to ftprintf_base.
** 4	If lst->count isn't zero, write lst->count no. of characters of
**		lst->str to stdout.
** 5	If lst->buff isn't zero, write lst->buff_count no. of characters of
**		lst->buff to stdout.
** 6	Free lst->str.
** 7	Free lst
** 8	return lst->count + lst->buffcount, i.e., 0
*/

int			ft_printf(const char *format, ...)
{
	t_pf	*lst;

	lst = lst_init();
	va_start(lst->va_lst, format);
	ftprintf_base((char*)format, lst, 0, 0);
	if (lst->count != 0)
		write(1, lst->str, lst->count);
	if (lst->buff_count != 0)
		write(1, lst->buff, lst->buff_count);
	if (lst->str != NULL)
		free(lst->str);
	free(lst);
	return (lst->count + lst->buff_count);
}
