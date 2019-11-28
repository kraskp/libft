/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_buff_man.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:31:35 by kkraszew          #+#    #+#             */
/*   Updated: 2019/11/28 19:35:06 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	3.4.1.2.1 Buffer conversion
**	(from 3.4.1.2)	convert_buff(lst, tmp, len);
**	1	create str of unsigned chars variable (*new)
**	2	create size_t variable (len_malloc)
**	3	set len_malloc to sum of count, buff_count, len and 1
**	4	if allocation for new fails, print_error()
**	5	add a '\0' to the end of new (which is at len_malloc position)
**	6	memcpy lst->str to new for count spots
**	7	memcpy lst->buff to new incremented by count, for buff_count spots
**	8	if len > 0, memcpy tmp to new incremented by count + buff_count, len
**	9	free lst->str if its not NULL
**	10	set lst->str to new
**	11	increment lst->count by buff_count + len
**	12	set buff_count to 0
*/

void	convert_buff(t_pf *lst, void *tmp, size_t len)
{
	unsigned char	*new;
	size_t			len_malloc;

	len_malloc = lst->count + lst->buff_count + len + 1;
	if ((new = (unsigned char*)ft_memalloc(len_malloc)) == NULL)
		printf_error(lst, "convert_buff error");
	new[len_malloc] = '\0';
	ft_memcpy(new, lst->str, lst->count);
	ft_memcpy(new + lst->count, lst->buff, lst->buff_count);
	if (len > 0)
		ft_memcpy(new + lst->count + lst->buff_count, tmp, len);
	if (lst->str != NULL)
		free(lst->str);
	lst->str = new;
	lst->count += lst->buff_count + len;
	lst->buff_count = 0;
}

/*
**	3.4.1 Buffer management
**	(from 3.4)	put_buff(lst, str + i, j, 0);
**	1	return ; if len = 0;
**	2	if buff_count + len is greater than or eql to 128 or
**		if len is greater than or eql to 128, convert_buff();
**	3	else copy len of tmp to lst->buff incremented by buff_count
**		and increment buff_count by len
**	4	if index is 1, free the tmp string
*/

void	put_buff(t_pf *lst, void *tmp, size_t len, size_t index)
{
	if (len == 0)
		return ;
	if (((lst->buff_count + len) >= BUFF_PRINTF) || len >= BUFF_PRINTF)
		convert_buff(lst, tmp, len);
	else
	{
		ft_memcpy(lst->buff + lst->buff_count, tmp, len);
		lst->buff_count += len;
	}
	if (index == 1)
		free(tmp);
}
