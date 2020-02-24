/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_multiply_by_two.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:55:38 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 14:35:27 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_valid_digit(char c)
{
	if (ft_isdigit(c) || c == '.')
		return (1);
	return (0);
}

char		*ft_bigint_multiply_by_two(char *output, size_t limit)
{
	size_t	len;
	int		ret;
	int		dec;

	len = 0;
	while (output[len] && len < limit)
		len++;
	ret = 0;
	if (len == limit)
		len = limit - 1;
	output[len + 1] = 0;
	while (len != 0 && is_valid_digit(output[len - 1]))
	{
		if (output[len - 1] == '.')
			output[len] = '.';
		else
		{
			dec = output[len - 1] - '0';
			output[len] = ((dec) * 2 + ret) % 10 + '0';
			ret = (dec) * 2 + ret < 10 ? 0 : 1;
		}
		len--;
	}
	output[len] = ret + '0';
	return (ft_bigint_trim(output));
}
