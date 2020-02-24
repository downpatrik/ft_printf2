/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:17:05 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 14:10:25 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const t_ft_print		g_fts_print[] =
{
	{KEY_PERCENTAGE, 0, &ft_print_percent},
	{KEY_C, 0, &ft_print_c},
	{KEY_S, 0, &ft_print_s},
	{KEY_P, 0, &ft_print_p},
	{KEY_D, 0, &ft_print_d},
	{KEY_D, LENGTH_H, &ft_print_d_h},
	{KEY_D, LENGTH_HH, &ft_print_d_hh},
	{KEY_D, LENGTH_L, &ft_print_d_l},
	{KEY_D, LENGTH_LL, &ft_print_d_ll},
	{KEY_D, LENGTH_J, &ft_print_d_ll},
	{KEY_D, LENGTH_Z, &ft_print_d_ll},
	{KEY_NB, 0, &ft_print_nb},
	{KEY_NB, LENGTH_H, &ft_print_nb_h},
	{KEY_NB, LENGTH_HH, &ft_print_nb_hh},
	{KEY_NB, LENGTH_L, &ft_print_nb_l},
	{KEY_NB, LENGTH_LL, &ft_print_nb_ll},
	{KEY_NB, LENGTH_J, &ft_print_nb_ll},
	{KEY_NB, LENGTH_Z, &ft_print_nb_ll},
	{KEY_F, 0, &ft_print_f},
	{KEY_F, LENGTH_L, &ft_print_f_l},
	{KEY_F, LENGTH_L_MAJ, &ft_print_f_l_maj},
	{KEY_E, 0, &ft_print_e},
	{KEY_E, LENGTH_L, &ft_print_e_l},
	{KEY_E, LENGTH_L_MAJ, &ft_print_e_l_maj},
	{0, 0, NULL},
};

t_ft						*ft_find_print(t_flag *flag)
{
	int	i;
	int	j;

	i = 0;
	while (g_fts_print[i].key)
	{
		if (g_fts_print[i].key == flag->key)
		{
			j = i;
			while (g_fts_print[j].key && g_fts_print[j].key == flag->key)
			{
				if (g_fts_print[j].length == flag->length)
					return (g_fts_print[j].fct);
				j++;
			}
			return (g_fts_print[i].fct);
		}
		i++;
	}
	return (NULL);
}

char						*ft_printf_arg(va_list *ap, t_flag *flag)
{
	t_ft	*fct;
	char	*ret;

	fct = ft_find_print(flag);
	ret = 0;
	if (fct != NULL)
	{
		ret = fct(ap, flag);
		if (ret == NULL)
		{
			ft_memdel((void **)&flag);
			return (NULL);
		}
	}
	return (ret);
}

char						*ft_print_percent(va_list *ap, t_flag *flag)
{
	char	*output;

	(void)ap;
	(void)flag;
	output = ft_strdup_alloc(PERCENTAGE, ft_len_to_alloc(1, flag));
	if (flag->precision != 0)
		output = ft_apply_precision_str(output, flag, 1);
	output = ft_apply_padding_str(output, flag, 1);
	return (output);
}
