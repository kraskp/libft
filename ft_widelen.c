/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_widelen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:51:27 by kkraszew          #+#    #+#             */
/*   Updated: 2019/11/16 17:10:08 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wlen(char *s, wchar_t arg)
{
	int i;

	i = 0;
	if (arg < 0x010000)
	{
		s[0] = ((arg >> 12) & 0x0F) | 0xE0;
		s[1] = ((arg >> 6) & 0x3F) | 0x80;
		s[2] = ((arg >> 0) & 0x3F) | 0x80;
		i = 3;
	}
	else if (arg < 0x110000)
	{
		s[0] = ((arg >> 18) & 0x07) | 0xF0;
		s[1] = ((arg >> 12) & 0x3F) | 0x80;
		s[2] = ((arg >> 6) & 0x3F) | 0x80;
		s[3] = ((arg >> 0) & 0x3F) | 0x80;
		i = 4;
	}
	return (i);
}

int			ft_widelen(wchar_t arg)
{
	char	*s;
	int		i;

	s = ft_strnew(5);
	i = 0;
	if (arg < 0x80)
	{
		s[0] = ((arg >> 0) & 0x7F) | 0x00;
		i = 1;
	}
	else if (arg < 0x0800)
	{
		s[0] = ((arg >> 6) & 0x1F) | 0xC0;
		s[1] = ((arg >> 0) & 0x3F) | 0x80;
		i = 2;
	}
	else
		ft_wlen(s, arg);
	return (i);
}
