/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_e.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:29:32 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 14:24:57 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_output(char *output, int expo, int i)
{
	int	j;

	j = expo;
	if (j > 0)
	{
		while (j != 0)
		{
			if (i == 0)
				break ;
			output[i] = output[i - 1];
			output[i - 1] = '.';
			i--;
			j--;
		}
		return (output);
	}
	while (j != 0)
	{
		output[i] = output[i + 1];
		output[i + 1] = '.';
		i++;
		j++;
	}
	return (output);
}

int			ft_apply_e(char *output)
{
	int i;
	int j;
	int expo;

	i = 0;
	while (output[i] && output[i] != '.')
		i++;
	expo = i;
	j = 0;
	while (output[j] && !(output[j] >= '1' && output[j] <= '9'))
		j++;
	expo = expo - j;
	if (expo > 0)
		expo--;
	if (expo == 0)
		return (0);
	output = get_output(output, expo, i);
	output = ft_bigint_trim(output);
	return (expo);
}
