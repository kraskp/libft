/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:50:31 by kkraszew          #+#    #+#             */
/*   Updated: 2019/11/28 19:31:54 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void			pf_putchar(t_pf *lst, unsigned char c, int index)
{
	size_t	max;

	max = 1;
	put_prefix(lst, max, lst->field, lst->zero);
	put_buff(lst, &c, max, index);
	put_prefix(lst, max, -lst->field, 0);
}

/*
**	3.5.1.7	conv_char
*/

void					conv_char(t_pf *lst)
{
	size_t	val;

	if (lst->conv != 'c')
		pf_putchar(lst, lst->conv, 0);
	else
	{
		val = va_arg(lst->va_copy, int);
		pf_putchar(lst, (char)val, 0);
	}
}
