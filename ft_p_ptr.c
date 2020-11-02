/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <ezemango@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:15:48 by jolim             #+#    #+#             */
/*   Updated: 2020/10/31 16:38:49 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_p_ptr(t_spec *spec, va_list *ap)
{
	char	*adrs;
	char	*temp;
	int		min_len;
	int		count;

	if (spec->f_dot)
		spec->f_zero = 0;
	adrs = ft_xtoa(va_arg(*ap, unsigned long long), spec->sp);
	min_len = ft_strlen(adrs);
	if (spec->f_dot && spec->precision > 9)
		adrs = ft_pad_zero(adrs, spec->precision - min_len);
	min_len = ft_strlen(adrs);
	if (spec->f_zero)
		adrs = ft_pad_zero(adrs, spec->width - min_len - 2);
	temp = ft_strjoin("0x", adrs);
	free(adrs);
	adrs = temp;
	min_len = ft_strlen(adrs);
	if (spec->f_hyphen)
		adrs = ft_align_left(adrs, spec->width - min_len);
	else
		adrs = ft_align_right(adrs, spec->width - min_len);
	count = ft_print_stdout(adrs);
	free(adrs);
	return (count);
}
