/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 17:33:04 by kkraszew          #+#    #+#             */
/*   Updated: 2019/12/03 17:35:48 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnchar(int len, char c)
{
	char	*s;

	if (!(s = (char *)malloc(sizeof(char) * len + 1)))
		return ;
	s[len] = '\0';
	while (len--)
		s[len] = c;
	ft_putstr_free(s);
}
