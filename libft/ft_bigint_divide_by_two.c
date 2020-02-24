/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_divide_by_two.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:55:28 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 01:55:29 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char ft_get_next_digit(char digit, int next_is_even)
{
	if (next_is_even == 0)
	{
		if (digit == '0' || digit == '1')
			return ('0');
		if (digit == '2' || digit == '3')
			return ('1');
		if (digit == '4' || digit == '5')
			return ('2');
		if (digit == '6' || digit == '7')
			return ('3');
		if (digit == '8' || digit == '9')
			return ('4');
	}
	if (digit == '0' || digit == '1')
		return ('5');
	if (digit == '2' || digit == '3')
		return ('6');
	if (digit == '4' || digit == '5')
		return ('7');
	if (digit == '6' || digit == '7')
		return ('8');
	if (digit == '8' || digit == '9')
		return ('9');
	return (0);
}

static int is_over(char *output, size_t *p_i, size_t *p_j, size_t limit)
{
	int finished;

	finished = 0;
	while (*p_i < limit - 1 && output[*p_i] && ft_isdigit(output[*p_i]) == 0)
	{
		output[*p_i - 1] = output[*p_i];
		*p_i = *p_i + 1;
	}
	*p_j = *p_i + 1;
	while (*p_j < limit - 1 && output[*p_j] && ft_isdigit(output[*p_j]) == 0)
	{
		output[*p_j - 1] = output[*p_j];
		*p_i = *p_i + 1;
		*p_j = *p_j + 1;
	}
	if (output[*p_j] == 0)
	{
		output[*p_j] = '0';
		output[*p_j + 1] = 0;
		finished = 1;
	}
	return (finished);
}

char *ft_bigint_divide_by_two(char *output, size_t limit)
{
	size_t i;
	size_t j;
	int finished;
	int even;

	output = ft_bigint_shift_right(output, 1, limit);
	output[0] = '0';
	i = 0;
	j = 0;
	finished = 0;
	while (i < limit && output[i] && finished != 1)
	{
		even = (output[i] - '0') % 2;
		finished = is_over(output, &i, &j, limit);
		output[i] = ft_get_next_digit(output[j], even);
		i = j;
	}
	return (ft_bigint_trim(output));
}
