/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putull.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:49:46 by kkraszew          #+#    #+#             */
/*   Updated: 2019/11/16 16:52:53 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putull(unsigned long long n, int *p)
{
	if (n >= 10)
	{
		ft_putull((n / 10), p);
		ft_putull((n % 10), p);
	}
	else
	{
		*p = *p + 1;
		ft_putchar(n + '0');
	}
}
