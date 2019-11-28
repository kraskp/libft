/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:02:32 by kkraszew          #+#    #+#             */
/*   Updated: 2019/11/19 18:02:35 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printtab(char **tab)
{
	ft_printtab_fd(tab, 1);
}

void	ft_printtab_fd(char **tab, int fd)
{
	int count1;

	count1 = 0;
	while (tab[count1] != NULL)
	{
		ft_putstr_fd(tab[count1], fd);
		if (tab[count1][ft_strlen(tab[count1]) - 1] != '\n')
			ft_putchar_fd('\n', fd);
		count1++;
	}
}

int		ft_maxlen_tab(char **tab, int index)
{
	int a;
	int b;
	int len;

	a = 0;
	len = 0;
	while (tab[a] != NULL)
	{
		b = 0;
		while (tab[a][b] != '\0')
			b++;
		if (b > len)
			len = b;
		a++;
	}
	if (index == 1)
		return (len);
	return (a);
}
