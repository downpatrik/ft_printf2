/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:30:11 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 14:23:14 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const t_color	g_tab_colors[] =
{
	{"cyan", ANSI_COLOR_CYAN},
	{"red", ANSI_COLOR_RED},
	{"green", ANSI_COLOR_GREEN},
	{"yellow", ANSI_COLOR_YELLOW},
	{"blue", ANSI_COLOR_BLUE},
	{"magenta", ANSI_COLOR_MAGENTA},
	{"eoc", ANSI_COLOR_RESET},
	{"", ""},
};

char					*ft_get_color(const char *str)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (str[len] && str[len] != '}')
		len++;
	if (len == 0)
		return (NULL);
	while ((g_tab_colors[i].key)[0])
	{
		if (ft_strncmp(g_tab_colors[i].key, str, len) == 0)
		{
			return ((char *)g_tab_colors[i].str);
		}
		i++;
	}
	return (NULL);
}
