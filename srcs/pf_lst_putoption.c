/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_lst_putoption.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:32:13 by kkraszew          #+#    #+#             */
/*   Updated: 2019/11/28 19:40:06 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	3.5.1.1.6.6	lst_undefined(lst)
**	undefined cases
*/

static void	lst_undefined(t_pf *lst)
{
	if (lst->zero > 1 && lst->dot > 1)
		lst->zero = 0;
	else if (lst->zero > 1)
		lst->zero = 1;
	if (lst->dot > 1)
	{
		lst->dot = 0;
		lst->preci = 0;
	}
	if (lst->conv != 'i' && lst->conv != 'd' && lst->conv != 'u' &&
		lst->conv != 'f' && lst->conv != 'F')
		lst->apost = 0;
	if (lst->conv == 's')
		lst->preci = ft_abs(lst->preci);
	if (lst->hash == 1 && lst->conv == 'u')
		lst->hash = 0;
	if (lst->space == 1 && (lst->conv == 'o' ||
				lst->conv == 'x' || lst->conv == 'X'))
		lst->space = 0;
}

/*
**	3.5.1.1.6	lst_base(lst)
**	1	check whether conversion is hex or pointer, set base 16
**	2	check whether conversion is octal, set base 8
**	3	check whether conversion is binary, set base 2
**	4	set base 10 otherwise
**	5	check whether lower case, if so set lowercase flag
**	6	execute lst_undefined
*/

static void	lst_base(t_pf *lst)
{
	if (lst->conv == 'x' || lst->conv == 'X' || lst->conv == 'p')
		lst->base = 16;
	else if (lst->conv == 'o')
		lst->base = 8;
	else if (lst->conv == 'b' || lst->conv == 'B')
		lst->base = 2;
	else
		lst->base = 10;
	if (!ft_islower(lst->conv))
		lst->uppercase = 1;
	lst_undefined(lst);
}

/*
**	3.5.1.1.4 lst_putflag_conv(lst, str, count)
**	check for flags h, l, j, z, L, adjust length accordingly
*/

static int	lst_putflag_conv(t_pf *lst, char *str, int count)
{
	if (str[count] == 'h')
		lst->length++;
	else if (str[count] == 'l')
		lst->length += 10;
	else if (str[count] == 'j')
		lst->length += 100;
	else if (str[count] == 'z')
		lst->length += 1000;
	else if (str[count] == 'L')
		lst->length += 100000;
	else
		lst->conv = str[count];
	count++;
	return (count);
}

/*
**	3.5.1.1.5	lst_putdigit(lst, str, count, &neg)
**	1	if '+' is in the position string, set sign flag to +
**		and increment
**	2	if '-' is there, set *neg to 1, and increment
**	3	if 1 is in position, or * or $
**		a	itoa while a digit
**		b	if * or $ and somethign after in str, grab next int
**		c	if dot isn't flagged, field is set by neg * tmp nub
**		d	other nb_tmp is the precision
*/

static int	lst_putdigit(t_pf *lst, char *str, int count, int *neg)
{
	int nb_tmp;

	nb_tmp = 0;
	if (str[count] == '+')
		lst->sign = str[count++];
	else if (str[count] == '-')
		(*neg) = str[count++] - 46;
	else if (ft_isdigit(str[count]) == 1 || str[count] == '*'
			|| str[count] == '$')
	{
		while (str[count] >= '0' && str[count] <= '9')
			nb_tmp = (nb_tmp * 10) + (str[count++] - '0');
		if ((str[count] == '*' || str[count] == '$') && (count++))
			nb_tmp = va_arg(lst->va_copy, int);
		if (lst->dot == 0)
			lst->field = (nb_tmp * (*neg));
		else
			lst->preci = nb_tmp;
	}
	return (count);
}

/*
**	3.5.1.1	lst_putoption(lst, str, 1)
** 			lst = lst
**			str = (char *)format + i + j
**			count = 1
**	1	init var neg, set to 1
**	2	lst_zero sets
**			lst->ul_nb = 0;
**			lst->ful_nb = 0;
**			lst->fl_nb = 0;
**			lst->expo = 0;
**			lst->hash = 0;
**			lst->space = 0;
**			lst->zero = 0;
**			lst->sign = 0;
**			lst->apost = 0;
**			lst->field = 0;
**			lst->dot = 0;
**			lst->preci = 0;
**			lst->uppercase = 0;
**			lst->psign = "";
**			lst->base = 0;
**			lst->length = 0;
**			lst->conv = 0;
**	3	While traversing string and conv is still 0,
**		check for options '.', '0', ''', '#', ' ', and if so
**		set the lst->flag to 1 (i.e., ascii value - (ascii value - 1)),
**		while also increament count by 1
**	4	While traversing string and conv is still 0,
**		check for options digit or +, -, *, $, if so lst_putdigit()
**	5	no option found, set count to lst_putflag_conv(lst, str, count)
**	6	perform lst_base()
**	7	return position on str (count)
*/

int			lst_putoption(t_pf *lst, char *str, int count)
{
	int		neg;

	neg = 1;
	lst_zero(lst);
	while (str[count] != '\0' && lst->conv == 0)
	{
		if (str[count] == '.')
			lst->dot += str[count++] - 45;
		else if (str[count] == '0' && lst->dot == 0)
			lst->zero += str[count++] - 47;
		else if (str[count] == 39)
			lst->apost = str[count++] - 38;
		else if (str[count] == '#')
			lst->hash = str[count++] - 34;
		else if (str[count] == ' ')
			lst->space = str[count++] - 31;
		else if (ft_isdigit(str[count]) == 1 || str[count] == '+' ||
				str[count] == '-' || str[count] == '*' || str[count] == '$')
			count = lst_putdigit(lst, str, count, &neg);
		else
			count = lst_putflag_conv(lst, str, count);
	}
	lst_base(lst);
	return (count);
}
