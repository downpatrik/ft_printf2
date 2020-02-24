/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_shift.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:52:21 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 14:26:39 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_left_shift(char *str, int index_until)
{
	int	j;

	j = 0;
	if (index_until < 0)
	{
		return (str);
	}
	if (index_until == 0)
	{
		str[0] = ' ';
		return (str);
	}
	if (index_until == 1)
	{
		str[0] = str[1];
		str[1] = ' ';
		return (str);
	}
	while (j < index_until - 1)
	{
		str[j] = str[j + 1];
		j++;
	}
	str[j] = ' ';
	return (str);
}

char	*ft_str_right_shift(char *str, int len)
{
	int	j;

	j = len;
	while (j > 0)
	{
		str[j] = str[j - 1];
		j--;
	}
	str[0] = ' ';
	return (str);
}
