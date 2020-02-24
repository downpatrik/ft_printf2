/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:09:21 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 13:55:39 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_itoa_base(unsigned char c, char *output, t_flag *flag)
{
	char	*tmp_str;

	tmp_str = ft_itoa(c);
	if (tmp_str)
		tmp_str = ft_convert_output(tmp_str, flag);
	if (tmp_str && ft_strlen(tmp_str) == 1)
	{
		tmp_str[1] = tmp_str[0];
		tmp_str[0] = '0';
		tmp_str[2] = 0;
	}
	output = ft_strcat(output, tmp_str);
	ft_memdel((void **)&tmp_str);
	return (output);
}

static char	*ft_itoa_p(void *addr, t_flag *flag, int size)
{
	int				i;
	char			*output;
	unsigned char	*t;

	i = (sizeof(void *));
	if (!(t = (unsigned char *)ft_memalloc((sizeof(void *) + 2)
		* sizeof(unsigned char))))
		return (NULL);
	t = ft_memcpy(t, &addr, sizeof(void *));
	if (!(output = (char *)ft_memalloc(size * sizeof(char))))
	{
		ft_memdel((void **)&t);
		return (NULL);
	}
	while (i != -1)
	{
		if (t[i])
			output = ft_itoa_base(t[i], output, flag);
		else
			output = ft_strcat(output, "00");
		i--;
	}
	ft_memdel((void **)&t);
	return (output);
}

char		*ft_print_p(va_list *ap, t_flag *flag)
{
	char	*output;
	void	*addr;
	int		i;
	int		len;
	size_t	size;

	addr = va_arg(*ap, void *);
	size = 100;
	size = ft_len_to_alloc(size, flag);
	output = ft_itoa_p(addr, flag, size);
	i = 0;
	while (output[i] && output[i] == '0')
		i++;
	len = ft_strlen(output) - i;
	output = ft_memmove(output, output + i, len);
	output[len] = 0;
	if (len == 0 && flag->precision != 0)
		output = ft_strcpy(output, "0");
	output = ft_apply_precision_nb(output, flag, 1);
	output = ft_apply_padding_p(output, flag, 1);
	return (output);
}
