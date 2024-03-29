/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:16:52 by kkraszew          #+#    #+#             */
/*   Updated: 2019/11/16 18:17:01 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrf(char const *s, int *p)
{
	int x;

	x = -1;
	while (s[++x] != '\0')
	{
		ft_putchar(s[x]);
		*p = *p + 1;
	}
}
