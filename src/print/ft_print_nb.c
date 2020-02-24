/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:08:04 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 03:22:20 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_print_nb(va_list *ap, t_flag *flag)
{
  char *output;
  unsigned int tmp;
  unsigned long long tmp_val;
  size_t size;
  int sign;

  tmp = va_arg(*ap, unsigned int);
  sign = tmp == 0 ? 0 : 1;
  sign = tmp == 4294967295 ? 2 : sign;
  tmp_val = (unsigned long long)tmp;
  size = ft_nblen_ull(tmp_val);
  size = ft_len_to_alloc(size, flag);
  output = ft_ulltoa_offset(tmp_val, size);
  output = ft_convert_output(output, flag);
  output = ft_apply_precision_nb(output, flag, sign);
  output = ft_apply_padding_nb(output, flag, sign);
  return (output);
}

char *ft_print_nb_h(va_list *ap, t_flag *flag)
{
  char *output;
  unsigned short tmp;
  unsigned long long tmp_val;
  size_t size;
  int sign;

  tmp = (unsigned short)va_arg(*ap, unsigned int);
  sign = tmp == 0 ? 0 : 1;
  tmp_val = (unsigned long long)tmp;
  size = ft_nblen_ull(tmp_val);
  size = ft_len_to_alloc(size, flag);
  output = ft_ulltoa_offset(tmp_val, size);
  output = ft_convert_output(output, flag);
  output = ft_apply_precision_nb(output, flag, sign);
  output = ft_apply_padding_nb(output, flag, sign);
  return (output);
}

char *ft_print_nb_hh(va_list *ap, t_flag *flag)
{
  unsigned char tmp;
  char *output;
  unsigned long long tmp_val;
  size_t size;
  int sign;

  tmp = (unsigned char)va_arg(*ap, unsigned int);
  sign = tmp == 0 ? 0 : 1;
  tmp_val = (unsigned long long)tmp;
  size = ft_nblen_ull(tmp_val);
  size = ft_len_to_alloc(size, flag);
  output = ft_ulltoa_offset(tmp_val, size);
  output = ft_convert_output(output, flag);
  output = ft_apply_precision_nb(output, flag, sign);
  output = ft_apply_padding_nb(output, flag, sign);
  return (output);
}

char *ft_print_nb_l(va_list *ap, t_flag *flag)
{
  unsigned long tmp;
  char *output;
  unsigned long long tmp_val;
  size_t size;
  int sign;

  tmp = (unsigned long)va_arg(*ap, unsigned long int);
  sign = tmp == 0 ? 0 : 1;
  tmp_val = (unsigned long long)tmp;
  size = ft_nblen_ull(tmp_val);
  size = ft_len_to_alloc(size, flag);
  output = ft_ulltoa_offset(tmp_val, size);
  output = ft_convert_output(output, flag);
  output = ft_apply_precision_nb(output, flag, sign);
  output = ft_apply_padding_nb(output, flag, sign);
  return (output);
}

char *ft_print_nb_ll(va_list *ap, t_flag *flag)
{
  char *output;
  unsigned long long tmp;
  unsigned long long tmp_val;
  size_t size;
  int sign;

  tmp = (unsigned long long)va_arg(*ap, unsigned long long int);
  sign = tmp == 0 ? 0 : 1;
  tmp_val = (unsigned long long)tmp;
  size = ft_nblen_ull(tmp_val);
  size = ft_len_to_alloc(size, flag);
  output = ft_ulltoa_offset(tmp_val, size);
  output = ft_convert_output(output, flag);
  output = ft_apply_precision_nb(output, flag, sign);
  output = ft_apply_padding_nb(output, flag, sign);
  return (output);
}