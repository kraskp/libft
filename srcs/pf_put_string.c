/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_put_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:08:41 by kkraszew          #+#    #+#             */
/*   Updated: 2019/11/28 19:40:47 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	3.5.1.2.9.9
**	performs itoa on the digits after . for the length of preci
*/

void	put_itoa(t_pf *lst, unsigned long n)
{
	unsigned char	tmp[27];
	int				len;
	int				mlen;

	len = ulen_base(n, lst->base);
	if (lst->apost == 1 && (len - 1) > 3)
		len += ((len / 3) - (len % 3 == 0 ? 1 : 0));
	mlen = len;
	len--;
	while (len >= 0)
	{
		if (lst->apost == 1 && ((mlen - len) % 4 == 0))
			tmp[len--] = ',';
		if ((n % lst->base) < 10)
			tmp[len--] = (n % lst->base) + 48;
		else
			tmp[len--] = (n % lst->base) + (lst->uppercase == 1 ? 55 : 87);
		n = n / lst->base;
	}
	put_buff(lst, tmp, mlen, 0);
}

/*
**	3.5.1.2.9.3.2	put_prefix(lst, 0, 1, 0)
**	1	set llen to nb minue len
**	2	if len is ≥ nb, return
**	3	if llen and buffcount is ≥ buffer,
**		memset 0 or space (depending on whether point flag is set) to tmp
**		for length llen. convert_buff()
**	4	otherwise, memset 0 or space (depending on whether point flag is
**		set) to buff + buffcount, for length llen. increment buffcount by
**		llen
*/

void	put_prefix(t_pf *lst, int len, int nb, int point)
{
	size_t			llen;
	unsigned char	tmp[nb - len];

	llen = (nb - len);
	if (len >= nb)
		return ;
	if ((llen + lst->buff_count) >= BUFF_PRINTF)
	{
		ft_memset(tmp, (point == 1 ? '0' : ' '), llen);
		convert_buff(lst, tmp, llen);
	}
	else
	{
		ft_memset(lst->buff + lst->buff_count, (point == 1 ? '0' : ' '), llen);
		lst->buff_count += llen;
	}
}
