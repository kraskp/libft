/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:57:59 by kkraszew          #+#    #+#             */
/*   Updated: 2019/11/28 19:34:17 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	3.5.1.2.9.2.9	roundup_double(lst, nb, 0, 0)
**		lst is lst, nb is nb, i is 0, max is 0
**	1	set i to preci + 1
**	2	set max to preci + 1
**	3	while i > 0
**		a.	if nb[i] is >= base / 2 AND i = max OR
**				nb[i] is >= base AND i > 0
**			set nb[i - 1] to nb[i -1] + 1
**			set nb[i] to nb[i] % base
**	4	decrement i
*/

static void	roundup_double(t_pf *lst, unsigned long *nb, int i, int max)
{
	i = lst->preci + 1;
	max = lst->preci + 1;
	while (i > 0)
	{
		if ((nb[i] >= (lst->base / 2) && i == max) ||
			(nb[i] >= lst->base && i > 0))
		{
			nb[i - 1] += 1;
			nb[i] = nb[i] % lst->base;
		}
		i--;
	}
}

/*
**	3.5.1.2.9.2	assign_double(lst, nb, 0, 0)
**		lst is lst, nb is tab_nb, i is 0, j is 0
**	1	init int var (preci), init size_t var (verif)
**	2	set preci to lst->preci plus 1
**	3	set nb[i] to ul_nb and increment i
**	4	set verif to 0
**	5	if ful_nb doesn't equal zero, execute ulen_base(ful_nb, base),
**		if it does equal zero, return 0
**	6	increment i by j
**	7	while j > 0, set nb[j] to ful_nb modulo base, and decrement j
**		set ful_nb to ful_nb divided by base
**	8	whilie preci is > 0
**		set fl_nb to fl_nb multiplied by base
**		set nb[i] to fl_nb cast as int, and increment i
**		set fl_nb to fl_nb minus fl_nb cast as int
**		decrement preci
**	9	execute roundup_double(lst, nb, 0, 0);
*/

static void	assign_double(t_pf *lst, unsigned long *nb, size_t i, int j)
{
	int		preci;
	size_t	verif;

	preci = lst->preci + 1;
	nb[i++] = lst->ul_nb;
	verif = 0;
	j = (lst->ful_nb != 0 ? ulen_base(lst->ful_nb, lst->base) : 0);
	i += j;
	while (j > 0)
	{
		nb[j--] = lst->ful_nb % lst->base;
		lst->ful_nb /= lst->base;
	}
	while (preci > 0)
	{
		lst->fl_nb *= lst->base;
		nb[i++] = (int)lst->fl_nb;
		lst->fl_nb -= (int)lst->fl_nb;
		preci--;
	}
	roundup_double(lst, nb, 0, 0);
}

/*
**	3.5.1.2.9.3	max_calc(lst, 0)
**	1 	check if that space flag is on, sign flag isn't +, length of psign
**		flag is 0. If so,
**	2 	execute put_prefix(lst, 0, 1, 0)
**	3	if field is > 0, decrement field
**	4	otherwise increament field
**	5 	set max to ulen_base(ul_nb, base) plus preci
**	6	increment max by length of psign
**	7	return max
*/

static int	max_calc(t_pf *lst, int max)
{
	if (lst->space == 1 && lst->sign != '+' && ft_strlen(lst->psign) == 0)
	{
		put_prefix(lst, 0, 1, 0);
		if (lst->field > 0)
			lst->field--;
		else if (lst->field < 0)
			lst->field++;
	}
	max = ulen_base(lst->ul_nb, lst->base) + lst->preci;
	max += ft_strlen(lst->psign);
	return (max);
}

/*
**	3.5.1.2.9	conv_double(lst, tab_nb, 0)
**		lst is lst, nb is tab_nb, i is 0
**	1	init var max, set to 0
**	2	execute assign_double(lst, nb, 0, 0)
**	3	set max to result of max_calc(lst, 0)
**	4	if zero flag is set:
**			puffbuff(lst, psign, length of psign, 0)
**	5	put_prefix(lst, max, field, zero)
**	6	if zero flag is not set
**			same as if isn't
**	7	if precision is less than zero
**			putbuff with '.'
**	8	while i minus 1 is less than precision
**			put integer to ascii of lst and nb, increment
*/

void		conv_double(t_pf *lst, unsigned long *nb, int i)
{
	int	max;

	max = 0;
	assign_double(lst, nb, 0, 0);
	max = max_calc(lst, 0);
	if (lst->zero == 1)
		put_buff(lst, lst->psign, ft_strlen(lst->psign), 0);
	put_prefix(lst, max, lst->field, lst->zero);
	if (lst->zero == 0)
		put_buff(lst, lst->psign, ft_strlen(lst->psign), 0);
	put_itoa(lst, nb[i++]);
	if (lst->preci > 0)
		put_buff(lst, ".", 1, 0);
	while ((i - 1) < lst->preci)
		put_itoa(lst, nb[i++]);
}
