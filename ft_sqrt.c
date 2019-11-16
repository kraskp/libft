/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:05:13 by kkraszew          #+#    #+#             */
/*   Updated: 2019/11/16 17:05:27 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_power_calc(int nb)
{
	return (nb * nb);
}

int			ft_sqrt(int nb)
{
	int i;

	i = 0;
	if (nb < 0)
		return (0);
	while (ft_power_calc(i) <= nb)
	{
		if (ft_power_calc(i) == nb)
			return (i);
		i++;
	}
	return (0);
}
