/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:04:06 by kkraszew          #+#    #+#             */
/*   Updated: 2019/11/28 19:36:17 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_error(t_pf *lst, char *str)
{
	ft_putstr_fd("\nWARNING\nFT_PRINT ERROR", 2);
	ft_putstr_fd(str, 2);
	if (lst != NULL)
	{
		if (lst->str != NULL)
			free(lst->str);
		free(lst);
	}
	exit(0);
}

int		ulen_base(unsigned long nb, size_t base)
{
	return (nb >= base ? ulen_base(nb / base, base) + 1 : 1);
}
