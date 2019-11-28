/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_lst_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:36:05 by kkraszew          #+#    #+#             */
/*   Updated: 2019/11/28 19:39:59 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	lst_zero(t_pf *lst)
{
	lst->ul_nb = 0;
	lst->ful_nb = 0;
	lst->fl_nb = 0;
	lst->expo = 0;
	lst->hash = 0;
	lst->space = 0;
	lst->zero = 0;
	lst->sign = 0;
	lst->apost = 0;
	lst->field = 0;
	lst->dot = 0;
	lst->preci = 0;
	lst->uppercase = 0;
	lst->psign = "";
	lst->base = 0;
	lst->length = 0;
	lst->conv = 0;
}

/*
**	1	Here with initialize the list with lst_int().
**	1.1	malloc size for t_pf *lst
**	1.2	if malloc fails, print_error()
**	1.3	set lst->count to 0;
**	1.4	set lst->buff_count to 0;
**	1.5	set lst->str to null;
**	1.6	return lst
*/

t_pf	*lst_init(void)
{
	t_pf *lst;

	if (!(lst = (t_pf*)malloc(sizeof(t_pf))))
		printf_error(lst, "lst_init error");
	lst->count = 0;
	lst->buff_count = 0;
	lst->str = NULL;
	return (lst);
}
