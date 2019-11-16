/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:09:48 by kkraszew          #+#    #+#             */
/*   Updated: 2019/11/16 17:10:23 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_base(unsigned long long int val, int base, int lowcase)
{
	long unsigned int		len;
	static char				*str;
	long unsigned int		v;

	len = 1;
	if (base < 2 && base > 36)
		return (0);
	v = val;
	while (v /= base)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len] = 0;
	while (len-- > 0)
	{
		v = val % base;
		if (lowcase == 1)
			str[len] = (v > 9) ? v + 'a' - 10 : v + '0';
		else
			str[len] = (v > 9) ? v + 'A' - 10 : v + '0';
		val /= base;
	}
	return (str);
}
