/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strudup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:25:44 by kkraszew          #+#    #+#             */
/*   Updated: 2019/11/18 19:27:11 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	*ft_strudup(char *s1)
{
	unsigned char	*dest;
	int				len;
	int				count;

	len = ft_strlen(s1);
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
