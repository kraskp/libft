/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:47:08 by kkraszew          #+#    #+#             */
/*   Updated: 2019/11/28 19:34:29 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	3.5.1.4.1.2 	 lst_putnb_unb
**	1	if length is 1 set ul_nb as casted unsigned short from ap
**	2	if length is 2 set ul_nb as casted unsigned char from ap
**	3	if legnth is 10 set ul_nb as long from ap
**	4	if length is 20 set ul_nb as unsigned long from ap
**	5	if length is 100 set ul_nb as intmax_t from ap
**	6	if length is 1000 set ul_nb as size_t from ap
**	7	if conversion is o,x,X,u, set ul_nb as unsigned int
**	8	otherwise set ul_nb as unsigned long
**	9	if sign is + and conversion is integer, set psign to +
*/

static void	lst_putnb_unb(t_pf *lst)
{
	if (lst->length == 1)
		lst->ul_nb = (unsigned short)va_arg(lst->va_copy, unsigned long);
	else if (lst->length == 2)
		lst->ul_nb = (unsigned char)va_arg(lst->va_copy, unsigned long);
	else if (lst->length == 10)
		lst->ul_nb = va_arg(lst->va_copy, long);
	else if (lst->length == 20)
		lst->ul_nb = va_arg(lst->va_copy, unsigned long);
	else if (lst->length == 100)
		lst->ul_nb = va_arg(lst->va_copy, intmax_t);
	else if (lst->length == 1000)
		lst->ul_nb = va_arg(lst->va_copy, size_t);
	else if (lst->conv == 'o' || lst->conv == 'x' || lst->conv == 'X' ||
			lst->conv == 'u')
		lst->ul_nb = va_arg(lst->va_copy, unsigned int);
	else
		lst->ul_nb = va_arg(lst->va_copy, unsigned long);
	if (lst->sign == '+' && (lst->conv == 'd' || lst->conv == 'i'))
		lst->psign = "+";
}

/*
**	3.5.1.4.1.1 	 lst_putnb_snb
**	1	cast as short if length is 1
**	2	cast as int if length is two
**	3	cast as long is length is 10 or 20
**	4	cast as intmax_t if length is 100
**	5	cast as size_t if length is 1000
**	6	cast as long is length isn't 0
**	7	otherwise cast as int
**	8	if nb is negative set psign to -, otherwise empty
**	9	if nb is positive and integer, set psign to +
**	10	set ul_nb to absolute value if nb is negative
*/

static void	lst_putnb_snb(t_pf *lst)
{
	long nb_tmp;

	if (lst->length == 1)
		nb_tmp = (short)va_arg(lst->va_copy, int);
	else if (lst->length == 2)
		nb_tmp = (char)va_arg(lst->va_copy, int);
	else if (lst->length == 10 || lst->length == 20)
		nb_tmp = va_arg(lst->va_copy, long);
	else if (lst->length == 100)
		nb_tmp = va_arg(lst->va_copy, intmax_t);
	else if (lst->length == 1000)
		nb_tmp = va_arg(lst->va_copy, size_t);
	else if (lst->length != 0)
		nb_tmp = va_arg(lst->va_copy, long);
	else
		nb_tmp = va_arg(lst->va_copy, int);
	lst->psign = (nb_tmp < 0 ? "-" : "");
	if (lst->sign == '+' && nb_tmp >= 0 && (lst->conv == 'd' ||
			lst->conv == 'i'))
		lst->psign = "+";
	lst->ul_nb = (nb_tmp < 0 ? -nb_tmp : nb_tmp);
}

/*
**	3.5.1.4.1 	 lst_putint
**	1	if conversion is integer, go to lst_putnb_snb
**	2	if conversion isn't, go to lst_putnb_unb
**	3	if conversion is pointer or hex, go to lst_putnb_snb AND hash is set
**		and ul_nb isn't 0, set psign to OX or Ox depending on whether x or X
*/

void		lst_putint(t_pf *lst)
{
	if (lst->conv == 'd' || lst->conv == 'i')
		lst_putnb_snb(lst);
	else
		lst_putnb_unb(lst);
	if (lst->conv == 'p' || ((lst->conv == 'x' || lst->conv == 'X')
				&& lst->hash == 1 && lst->ul_nb != 0))
		lst->psign = (lst->uppercase == 1 ? "0X" : "0x");
}

/*
**	3.5.1.4.4	ft_spacecalc
**	1	if hash flag is set AND conversion is o AND not ((ul_nb is 0 AND
**		dot flag is set and precision is greater than 0) OR dot flag is
**		not set and ul_nb is):
**		a.	set has flag
**		b.	if dot flag is set and precision is > length, decrement
**			precision unless it is 0, in which case, keep it 0
**		c.	if field is < 0, increment field;
**	2	otherwise set hash to off
**	3	if dot flag is set and precision is ≥ 0, set zero to 0;
**	4	if space flag is set AND sign isn't positive and length of psign
**		is 0 and conversation is 'u'
**		a.	put_prefix
**		b.	decrement field while it's > 0
**		c.	increament field while it's < 0
*/

static void	ft_spacecalc(t_pf *lst, int len)
{
	if ((lst->hash == 1 && lst->conv == 'o') &&
		!((lst->ul_nb == 0 && lst->dot == 1 && lst->preci > 0) ||
			(lst->dot == 0 && lst->ul_nb == 0)))
	{
		lst->hash = 1;
		if ((lst->dot == 1 && lst->preci > len))
			lst->preci = (lst->preci != 0 ? lst->preci - 1 : lst->preci);
		if (lst->field < 0)
			lst->field++;
	}
	else
		lst->hash = 0;
	if (lst->dot == 1 && lst->preci >= 0)
		lst->zero = 0;
	if (lst->space == 1 && lst->sign != '+' && ft_strlen(lst->psign) == 0
			&& lst->conv != 'u')
	{
		put_prefix(lst, 0, 1, 0);
		if (lst->field > 0)
			lst->field--;
		else if (lst->field < 0)
			lst->field++;
	}
}

/*
**	3.5.1.4	conv_int
**	1	first lst_putint to deal with whether signed or not, etc
**	2	set len to ulen_base
**			ulen_base recursively divides number by base, returns either min + 1
**			or 1 depending on whether nb is greater than base
**	3	set len to 0, if ul_nb is 0, dot flag is set, and precision is 0
**	4	execute ft_spacecalc();
**	5	set max to the larger of len and precision, increment by psign
**	6	if zero is set, putbuff
**	7	put_prefix for hash
**	8	if zero isn't set, putbuff
**	9	put prefix
**	10	put prefix for precision
**	11	if not dot set, precision and ul_nb 0, convert ul_nb to ascii
**	12	decrement field and put prefix
*/

void		conv_int(t_pf *lst)
{
	int len;
	int max;

	lst_putint(lst);
	len = ulen_base(lst->ul_nb, lst->base);
	if (lst->ul_nb == 0 && lst->dot == 1 && lst->preci == 0)
		len = 0;
	ft_spacecalc(lst, len);
	max = ft_max(len, lst->preci) + ft_strlen(lst->psign);
	if (lst->zero == 1)
		put_buff(lst, lst->psign, ft_strlen(lst->psign), 0);
	put_prefix(lst, max + lst->hash, lst->field, lst->zero);
	if (lst->zero == 0)
		put_buff(lst, lst->psign, ft_strlen(lst->psign), 0);
	put_prefix(lst, 0, lst->hash, 1);
	put_prefix(lst, len, lst->preci, 1);
	if (!(lst->dot == 1 && lst->preci == 0 && lst->ul_nb == 0))
		put_itoa(lst, lst->ul_nb);
	put_prefix(lst, max, -lst->field, 0);
}
