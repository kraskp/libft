/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:18:54 by kkraszew          #+#    #+#             */
/*   Updated: 2019/11/23 16:57:41 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

/*
** Text
*/

# define T_WHITE	"\033[0m"
# define T_BLACK	"\033[30m"
# define T_RED		"\033[31m"
# define T_GREEN	"\033[32m"
# define T_YELLOW	"\033[33m"
# define T_BLUE		"\033[34m"
# define T_PURPLE	"\033[35m"
# define T_CYAN		"\033[36m"
# define T_LGREY    "\033[37m"

# define T_DGREY	"\033[1;30m"
# define T_LRED		"\033[1;31m"
# define T_LGREEN	"\033[1;32m"
# define T_LYELLOW	"\033[1;33m"
# define T_LBLUE	"\033[1;34m"
# define T_LPURPLE	"\033[1;35m"
# define T_LCYAN	"\033[1;36m"

/*
** Background
*/

# define B_WHITE	"\033[0m"
# define B_BLACK	"\033[40m"
# define B_RED		"\033[41m"
# define B_GREEN	"\033[42m"
# define B_YELLOW	"\033[43m"
# define B_BLUE		"\033[44m"
# define B_PURPLE	"\033[45m"
# define B_CYAN		"\033[46m"
# define B_GREY		"\033[47m"

/*
** Format
*/

# define F_DEF		"\033[0m"
# define F_BOLD		"\033[1m"
# define F_UDERLINE	"\033[4m"
# define F_BLINK	"\033[5m"
# define F_REVERSE	"\033[6m"
# define F_INVISIBL	"\033[6m"

#endif
