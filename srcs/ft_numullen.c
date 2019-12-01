/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numullen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:29:26 by kkraszew          #+#    #+#             */
/*   Updated: 2019/12/01 14:35:50 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_numullen(unsigned long long n)
{
	unsigned long long	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}
