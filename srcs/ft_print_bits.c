/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 10:57:05 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/26 19:52:29 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_bits(unsigned char octet)
{
	ft_putchar((octet >> 7 & 1) + '0');
	ft_putchar((octet >> 6 & 1) + '0');
	ft_putchar((octet >> 5 & 1) + '0');
	ft_putchar((octet >> 4 & 1) + '0');
	ft_putchar((octet >> 3 & 1) + '0');
	ft_putchar((octet >> 2 & 1) + '0');
	ft_putchar((octet >> 1 & 1) + '0');
	ft_putchar((octet >> 0 & 1) + '0');
}
