/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:21:27 by kkraszew          #+#    #+#             */
/*   Updated: 2019/11/28 19:34:07 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	3.5.1.3.5	pf_string(lst, ustr, 1);
**		lst is lst, str is our unsigned char str, index is 1
**	1	init size_t var (max)
**	2	check if index is 1, depending on whether dot flag isn't set,
**		set max to length of our ustr or length up to precision
**	3	put prefix
**	4	put buff
**	5	put prefix, decrementing lst-field
*/

void	pf_string(t_pf *lst, unsigned char *str, int index)
{
	size_t	max;

	max = 0;
	if (index == 1)
		max = (lst->dot == 0 ? ft_ustrlen(str) : ft_ustrnlen(str, lst->preci));
	put_prefix(lst, max, lst->field, lst->zero);
	put_buff(lst, str, max, 1);
	put_prefix(lst, max, -lst->field, 0);
}

/*
**	3.5.1.3 conv_string
**	1	init unsigned char str var (ustr)
**	2	malloc memory for ustr
**	3	if malloc fails, duplicate string "null" and turned it into unsigned str
**	4	if malloc succeeds, duplicate the unsigned char str
**	5	print the string with pf_string
*/

void	conv_string(t_pf *lst)
{
	unsigned char	*ustr;

	ustr = (unsigned char*)va_arg(lst->va_copy, char*);
	if (ustr == NULL)
		ustr = ft_strudup("(null)");
	else
		ustr = ft_ustrdup(ustr);
	pf_string(lst, ustr, 1);
}
