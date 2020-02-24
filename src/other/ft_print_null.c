/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_null.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:30:37 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 14:16:11 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_null(char *output, t_flag *flag, int fd)
{
	char	c;
	int		i;

	i = 0;
	c = 0;
	while (i < flag->character_i)
	{
		ft_putchar_fd(output[i], fd);
		i++;
	}
	write(1, &c, fd);
	i++;
	while (output[i])
	{
		ft_putchar_fd(output[i], fd);
		i++;
	}
	return (i);
}
