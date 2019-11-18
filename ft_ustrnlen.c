/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ustrnlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:30:33 by kkraszew          #+#    #+#             */
/*   Updated: 2019/11/18 19:30:46 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_ustrnlen(const unsigned char *s, size_t max)
{
	size_t count;

	count = 0;
	while (s[count] != '\0' && count < max)
		count++;
	return (count);
}
