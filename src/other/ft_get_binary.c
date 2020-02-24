/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_binary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:30:02 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 01:30:02 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_get_binary(unsigned char c, char *tmp_str)
{
	char base[3];
	char tmp;
	int k;

	ft_strcpy(base, "01");
	k = 0;
	while (c != 0)
	{
		tmp_str[k++] = base[c % 2];
		c /= 2;
	}
	while (k != 8)
		tmp_str[k++] = base[0];
	tmp_str[k] = '\0';
	k = 0;
	while (k != 4)
	{
		tmp = tmp_str[k];
		tmp_str[k] = tmp_str[7 - k];
		tmp_str[7 - k] = tmp;
		k++;
	}
	return (tmp_str);
}
