/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:44:39 by kkraszew          #+#    #+#             */
/*   Updated: 2019/11/18 20:13:39 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		len_wchar_single(wchar_t c)
{
	if (c <= 0x7F)
		return (1);
	if (c <= 0x7FF)
		return (2);
	if (c <= 0xFFFF)
		return (3);
	if (c <= 0x10FFFF)
		return (4);
	return (0);
}

int		len_wchar(wchar_t *str)
{
	size_t	count;
	size_t	a;

	count = 0;
	a = 0;
	while (str[a] != '\0')
		count += len_wchar_single(str[a++]);
	return (count);
}

size_t	len_wuchart(unsigned char *str)
{
	size_t a;

	a = 0;
	while (str[a] != 0)
		a++;
	return (a);
}

int		nlen_wchar(wchar_t *str, size_t len)
{
	size_t	count;
	size_t	count2;
	size_t	a;

	count = 0;
	count2 = 0;
	a = 0;
	while (str[a] != '\0')
	{
		count = len_wchar_single(str[a]);
		if ((count2 + count) > len)
			return (count2);
		else if ((count2 + count) == len)
			return (count2 + count);
		else
			count2 += count;
		a++;
	}
	return (count2);
}

void	convert_wchar(unsigned char **new, wchar_t wc, size_t *i)
{
	if (wc <= 0x7F)
		(*new)[(*i)++] = wc;
	else if (wc <= 0x7FF)
		(*new)[(*i)++] = 192 + (wc / 64);
	else
	{
		if (wc > 0xFFFF)
		{
			(*new)[(*i)++] = 240 + (wc / 262144);
			(*new)[(*i)++] = 128 + ((wc / 4096) % 64);
		}
		else
			(*new)[(*i)++] = 224 + (wc / 4096);
		(*new)[(*i)++] = 128 + ((wc / 64) % 64);
	}
	if (wc > 0x7F)
		(*new)[(*i)++] = 128 + (wc % 64);
	(*new)[(*i)] = '\0';
}
