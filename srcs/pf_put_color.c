/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_put_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:16:21 by kkraszew          #+#    #+#             */
/*   Updated: 2019/11/28 19:34:56 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	3.5.1.6x	conv_format(lst, str+ret)
**	check for format codes, see color.h, move forward in str
**	return
*/

static int	conv_format(t_pf *lst, char *str)
{
	int ret;

	ret = 1;
	if ((ft_strncmp(str, "F_DEF}", 6) == 0 && (ret = 6)) ||
		(ft_strncmp(str, "F_EOC}", 6) == 0 && (ret = 6)))
		put_buff(lst, F_DEF, ft_strlen(F_DEF), 0);
	else if (ft_strncmp(str, "F_BOLD}", 7) == 0 && (ret = 7))
		put_buff(lst, F_BOLD, ft_strlen(F_BOLD), 0);
	else if (ft_strncmp(str, "F_UDERLINE}", 11) == 0 && (ret = 11))
		put_buff(lst, F_UDERLINE, ft_strlen(F_UDERLINE), 0);
	else if (ft_strncmp(str, "F_BLINK}", 8) == 0 && (ret = 8))
		put_buff(lst, F_BLINK, ft_strlen(F_BLINK), 0);
	else if ((ft_strncmp(str, "F_REVERSE}", 10) == 0) && (ret = 10))
		put_buff(lst, F_REVERSE, ft_strlen(F_REVERSE), 0);
	else if (ft_strncmp(str, "F_INVISIBL}", 11) == 0 && (ret = 11))
		put_buff(lst, F_INVISIBL, ft_strlen(F_INVISIBL), 0);
	return (ret);
}

/*
**	3.5.1.6x	conv_backcolor(lst, str+ret)
**	check for bg olor codes, see color.h, move forward in str
**	goto conv_format for more options, do same.
*/

static int	conv_backcolor(t_pf *lst, char *str)
{
	int ret;

	ret = 1;
	if ((ft_strncmp(str, "B_WHITE}", 8) == 0 && (ret = 8)) ||
			(ft_strncmp(str, "B_EOC}", 6) == 0 && (ret = 6)))
		put_buff(lst, B_WHITE, ft_strlen(B_WHITE), 0);
	else if (ft_strncmp(str, "B_BLACK}", 8) == 0 && (ret = 8))
		put_buff(lst, B_BLACK, ft_strlen(B_BLACK), 0);
	else if (ft_strncmp(str, "B_RED}", 6) == 0 && (ret = 6))
		put_buff(lst, B_RED, ft_strlen(B_RED), 0);
	else if (ft_strncmp(str, "B_YELLOW}", 9) == 0 && (ret = 9))
		put_buff(lst, B_YELLOW, ft_strlen(B_YELLOW), 0);
	else if ((ft_strncmp(str, "B_BLUE}", 7) == 0) && (ret = 7))
		put_buff(lst, B_BLUE, ft_strlen(B_BLUE), 0);
	else if (ft_strncmp(str, "B_PURPLE}", 9) == 0 && (ret = 9))
		put_buff(lst, B_PURPLE, ft_strlen(B_PURPLE), 0);
	else if (ft_strncmp(str, "B_CYAN}", 7) == 0 && (ret = 7))
		put_buff(lst, B_CYAN, ft_strlen(B_CYAN), 0);
	else if (ft_strncmp(str, "B_GREY}", 7) == 0 && (ret = 7))
		put_buff(lst, B_GREY, ft_strlen(B_GREY), 0);
	else
		ret = conv_format(lst, str);
	return (ret);
}

/*
**	3.5.1.6x	conv_textcolor(lst, str+ret)
**	check for color codes, see color.h, move forward in str
**	goto conv_backcolor for more options, do same.
*/

static int	conv_textcolor(t_pf *lst, char *str)
{
	int ret;

	ret = 1;
	if (ft_strncmp(str, "T_DGREY}", 8) == 0 && (ret = 8))
		put_buff(lst, T_DGREY, ft_strlen(T_DGREY), 0);
	else if (ft_strncmp(str, "T_LRED}", 7) == 0 && (ret = 7))
		put_buff(lst, T_LRED, ft_strlen(T_LRED), 0);
	else if (ft_strncmp(str, "T_LGREEN}", 9) == 0 && (ret = 9))
		put_buff(lst, T_LGREEN, ft_strlen(T_LGREEN), 0);
	else if (ft_strncmp(str, "T_LYELLOW}", 10) == 0 && (ret = 10))
		put_buff(lst, T_LYELLOW, ft_strlen(T_LYELLOW), 0);
	else if ((ft_strncmp(str, "T_LBLUE}", 8) == 0) && (ret = 8))
		put_buff(lst, T_LBLUE, ft_strlen(T_LBLUE), 0);
	else if (ft_strncmp(str, "T_LPURPLE}", 10) == 0 && (ret = 10))
		put_buff(lst, T_LPURPLE, ft_strlen(T_LPURPLE), 0);
	else if (ft_strncmp(str, "T_LCYAN}", 8) == 0 && (ret = 8))
		put_buff(lst, T_LCYAN, ft_strlen(T_LCYAN), 0);
	else
		ret = conv_backcolor(lst, str);
	return (ret);
}

/*
**	3.5.1.6	conv_color(lst, str+ret)
**	check for color codes, see color.h, move forward in str
**	goto conv_textcolor for more options, do same.
*/

int			conv_color(t_pf *lst, char *str)
{
	int ret;

	ret = 1;
	if ((ft_strncmp(str, "T_WHITE}", 8) == 0 && (ret = 8)) ||
			(ft_strncmp(str, "T_EOC}", 6) == 0 && (ret = 6)))
		put_buff(lst, T_WHITE, ft_strlen(T_WHITE), 0);
	else if (ft_strncmp(str, "T_BLACK}", 8) == 0 && (ret = 8))
		put_buff(lst, T_BLACK, ft_strlen(T_BLACK), 0);
	else if (ft_strncmp(str, "T_RED}", 6) == 0 && (ret = 6))
		put_buff(lst, T_RED, ft_strlen(T_RED), 0);
	else if (ft_strncmp(str, "T_GREEN}", 8) == 0 && (ret = 8))
		put_buff(lst, T_GREEN, ft_strlen(T_GREEN), 0);
	else if (ft_strncmp(str, "T_YELLOW}", 9) == 0 && (ret = 9))
		put_buff(lst, T_YELLOW, ft_strlen(T_YELLOW), 0);
	else if ((ft_strncmp(str, "T_BLUE}", 7) == 0) && (ret = 7))
		put_buff(lst, T_BLUE, ft_strlen(T_BLUE), 0);
	else if (ft_strncmp(str, "T_PURPLE}", 9) == 0 && (ret = 9))
		put_buff(lst, T_PURPLE, ft_strlen(T_PURPLE), 0);
	else if (ft_strncmp(str, "T_CYAN}", 7) == 0 && (ret = 7))
		put_buff(lst, T_CYAN, ft_strlen(T_CYAN), 0);
	else if (ft_strncmp(str, "T_LGREY}", 8) == 0 && (ret = 8))
		put_buff(lst, T_LGREY, ft_strlen(T_LGREY), 0);
	else
		ret = conv_textcolor(lst, str);
	return (ret);
}
