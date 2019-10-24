/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswspace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:49:23 by kkraszew          #+#    #+#             */
/*   Updated: 2019/10/18 17:51:27 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iswspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\v' ||
		c == '\f' || c == '\f' || c == '\n')
		return (1);
	else
		return (0);
}