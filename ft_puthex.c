/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:48:35 by kkraszew          #+#    #+#             */
/*   Updated: 2019/11/16 16:48:54 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex(unsigned int n, int *p)
{
	if (n > 15)
	{
		ft_puthex((n / 16), p);
		ft_puthex((n % 16), p);
	}
	else if (n < 10)
	{
		*p = *p + 1;
		ft_putchar(n + '0');
	}
	else
	{
		*p = *p + 1;
		n == 10 ? ft_putchar('a') : 0;
		n == 11 ? ft_putchar('b') : 0;
		n == 12 ? ft_putchar('c') : 0;
		n == 13 ? ft_putchar('d') : 0;
		n == 14 ? ft_putchar('e') : 0;
		n == 15 ? ft_putchar('f') : 0;
	}
}
