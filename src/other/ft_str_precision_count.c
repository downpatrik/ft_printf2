/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_precision_count.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:30:52 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 01:58:30 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_str_precision_count(char *str, int offset)
{
	int count;
	int i;

	i = offset;
	count = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || ft_isalpha(str[i]))
		{
			while (str[i] && (ft_isdigit(str[i]) || ft_isalpha(str[i])))
			{
				count++;
				i++;
			}
			if (str[i] == '\0')
				break;
		}
		i++;
	}
	return (count);
}
