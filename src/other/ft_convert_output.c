/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_output.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:29:50 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 14:21:29 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_len(long long nb, size_t base_len)
{
	size_t		size;
	long long	nb_tmp;

	size = 0;
	nb_tmp = nb;
	while (nb_tmp != 0)
	{
		nb_tmp /= base_len;
		size++;
	}
	return (size);
}

static char		*ft_convert_base_offset(char *decimal, char *base, t_flag *flag)
{
	char		*output;
	long long	result;
	size_t		i;
	size_t		len;
	int			mem;

	i = -1;
	result = 0;
	while (decimal[++i])
		result = result * 10 + (decimal[i] - '0');
	len = get_len(result, ft_strlen(base));
	mem = ft_len_to_alloc(len, flag);
	if (!(output = (char *)ft_memalloc(sizeof(char) * (mem + 1))))
		return (NULL);
	output[len--] = '\0';
	if (result == 0)
		output[0] = base[0];
	while (result != 0)
	{
		output[len--] = base[result % ft_strlen(base)];
		result /= ft_strlen(base);
	}
	return (output);
}

static int		is_convertible(t_flag *flag)
{
	return (flag->conv == 'o' || flag->conv == 'x' || flag->conv == 'X' ||
			flag->conv == 'b' || flag->conv == 'p');
}

char			*ft_convert_output(char *str, t_flag *flag)
{
	char	*output;

	output = NULL;
	if (is_convertible(flag))
	{
		if (flag->conv == 'o')
			output = ft_convert_base_offset(str, BASE_O, flag);
		if (flag->conv == 'x')
			output = ft_convert_base_offset(str, BASE_X, flag);
		if (flag->conv == 'X')
			output = ft_convert_base_offset(str, BASE_X_MAJ, flag);
		if (flag->conv == 'b')
			output = ft_convert_base_offset(str, BASE_B, flag);
		if (flag->conv == 'p')
			output = ft_convert_base_offset(str, BASE_X, flag);
		ft_memdel((void **)&str);
		return (output);
	}
	return (str);
}
