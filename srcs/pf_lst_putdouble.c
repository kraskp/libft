/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_lst_putdouble.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:09:59 by kkraszew          #+#    #+#             */
/*   Updated: 2019/11/28 19:40:18 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	3.5.1.2.6.5	lst_putdouble_pos(lst, nb, 1)
**		lst is lst, nb is nb, coef is 1
**	1	while coef multiplied by base is less than nb cast as unsigned long,
**		and nb isn't 0:
**		a.	multi-crement coef by base
**		b.	increament exponent by 1
**	2	set ul_nb to nb cast as unsigned long divided by coef
**	3	set ful_nb to nb MINUS ul_nb multipled by coef
**	4	set fl_nb to nb MINUS nb cast as unsigned long
*/

static void	lst_putdouble_pos(t_pf *lst, long double nb, unsigned long coef)
{
	while (((coef * lst->base) < (unsigned long)nb) && nb != 0)
	{
		coef *= lst->base;
		lst->expo++;
	}
	lst->ul_nb = (unsigned long)nb / coef;
	lst->ful_nb = nb - (lst->ul_nb * coef);
	lst->fl_nb = nb - (unsigned long)nb;
}

/*
**	3.5.1.2.6.6	lst_putdouble_neg(lst, nb, 1)
**		lst is lst, nb is nb, coef is 1
**	1	while (coef multiplied by nb) cast as unsigne long is <= 0, and
**		nb isn't 0:
**		a.	multi-crement coef by base
**		b.	decrement exponent by 1
**	2	set ul_nb to (nb multiplied by coefficient) cast as unsigned long
**	3	set fl_nb as nb multiplied by coefficient minus ul_nb
*/

static void	lst_putdouble_neg(t_pf *lst, long double nb, unsigned long coef)
{
	while (((unsigned long)(coef * nb) <= 0) && nb != 0)
	{
		coef *= lst->base;
		lst->expo--;
	}
	lst->ul_nb = (unsigned long)(nb * coef);
	lst->fl_nb = (nb * coef) - lst->ul_nb;
}

/*
**	3.5.1.2.6	lst_putdouble_main(lst, nb);
**	1	check if num is neg, if so, set psign to -
**	2	if num is pos and sign is set to +, set psign to +
**	3	if dot flag is NOT set, set precision to 6
**	4	if 'f' or 'F' flag is set,
**		set lst->ul_nb to nb cast as unsigned long
**		set lst->fl_nb to nb MINUS nb cast as unsigned long
**	5	otherwise check if nb cast as unsigned long is > 0, and if so
**		execute lst_putdouble_pos(lst, nb, 1)
**	6	otherwise execute lst_putdouble_neg(lst, nb, 1)
*/

static void	lst_putdouble_main(t_pf *lst, long double nb)
{
	if (nb < 0)
	{
		nb = -nb;
		lst->psign = "-";
	}
	else if (nb >= 0 && lst->sign == '+')
		lst->psign = "+";
	if (lst->dot == 0)
		lst->preci = 6;
	if (lst->conv == 'f' || lst->conv == 'F')
	{
		lst->ul_nb = (unsigned long)nb;
		lst->fl_nb = nb - (unsigned long)nb;
	}
	else if ((unsigned long)nb > 0)
		lst_putdouble_pos(lst, nb, 1);
	else
		lst_putdouble_neg(lst, nb, 1);
}

/*
**	3.5.1.2
**	1	init long double var (nb) and unsigned long *(tab_nb)
**	2	if lst->length is over 100000, set nb to next arg in va_copy called
**		is known to be a long double
**	3	else set nb to next arg in va_copy called, known to be double, and
**		cast that as a long double
**	4	if nb is 1/0 or -1/0 print INF or inf, depending on if maj flag is set
**	5	if nb doesn't equal number, print NAN or nan, depending on if maj flag
**		is set
**	6	else execute lst_putdouble_main(lst, nb)
**	7	allocate memory for tab_nb at size of unsigned long * (precision plus
**		two plus result of ulen_base(ul_nb, base))
**			ulen_base recursively divides number by base, returns either min + 1
**			or 1 depending on whether nb is greater than base
**	8 	if allocation fails print error
**	9	execute conv_double();
*/

void		lst_putdouble(t_pf *lst)
{
	long double			nb;
	unsigned long		*tab_nb;

	if (lst->length == 100000)
		nb = va_arg(lst->va_copy, long double);
	else
		nb = (long double)va_arg(lst->va_copy, double);
	if ((1.0 / 0.0) == nb || (-1.0 / 0.0) == nb)
		put_buff(lst, (lst->uppercase == 1 ? "INF" : "inf"), 3, 0);
	else if (nb != nb)
		put_buff(lst, (lst->uppercase == 1 ? "NAN" : "nan"), 3, 0);
	else
	{
		lst_putdouble_main(lst, nb);
		if (!(tab_nb = (unsigned long*)ft_memalloc(sizeof(unsigned long) *
						(lst->preci + 2 + ulen_base(lst->ul_nb, lst->base)))))
			printf_error(lst, "lst_putdouble error");
		conv_double(lst, tab_nb, 0);
	}
}
