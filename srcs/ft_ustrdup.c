/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ustrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:27:57 by kkraszew          #+#    #+#             */
/*   Updated: 2019/11/18 19:28:34 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	*ft_ustrdup(unsigned char *s1)
{
	unsigned char	*dest;
	int				len;
	int				count;

	len = ft_ustrlen(s1);
	count = 0;
	if (!(dest = (unsigned char *)malloc(sizeof(unsigned char) * len + 1)))
		return (NULL);
	while (s1[count] != '\0')
	{
		dest[count] = s1[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}
