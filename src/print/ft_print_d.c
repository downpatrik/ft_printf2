/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptint_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:00:39 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 01:11:38 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_print_d(va_list *ap, t_flag *flag)
{
  char *output;
  unsigned long long tmp_val;
  size_t size;
  int tmp;
  int sign;

  tmp = va_arg(*ap, int);
  sign = tmp;
  tmp_val = tmp < 0 ? -1 * (unsigned long long)tmp : (unsigned long long)tmp;
  size = ft_nblen_ull(tmp_val);
  size = ft_len_to_alloc(size, flag);
  output = ft_ulltoa_offset(tmp_val, size);
  output = ft_apply_precision_nb(output, flag, sign);
  output = ft_apply_padding_nb(output, flag, sign);
  return (output);
}

char *ft_print_d_l(va_list *ap, t_flag *flag)
{
  long tmp;
  char *output;
  unsigned long long tmp_val;
  size_t size;
  int sign;

  tmp = va_arg(*ap, long);
  if (tmp == 0)
    sign = 0;
  else
    sign = tmp < 0 ? -1 : 1;
  tmp_val = tmp < 0 ? -1 * (unsigned long long)tmp : (unsigned long long)tmp;
  size = ft_nblen_ull(tmp_val);
  size = ft_len_to_alloc(size, flag);
  output = ft_ulltoa_offset(tmp_val, size);
  output = ft_apply_precision_nb(output, flag, sign);
  output = ft_apply_padding_nb(output, flag, sign);
  return (output);
}

char *ft_print_d_ll(va_list *ap, t_flag *flag)
{
  long long tmp;
  char *output;
  unsigned long long tmp_val;
  size_t size;
  int sign;

  tmp = va_arg(*ap, long long);
  if (tmp == 0)
    sign = 0;
  else
    sign = tmp < 0 ? -1 : 1;
  tmp_val = tmp < 0 ? -1 * (unsigned long long)tmp : (unsigned long long)tmp;
  size = ft_nblen_ull(tmp_val);
  size = ft_len_to_alloc(size, flag);
  output = ft_ulltoa_offset(tmp_val, size);
  output = ft_apply_precision_nb(output, flag, sign);
  output = ft_apply_padding_nb(output, flag, sign);
  return (output);
}