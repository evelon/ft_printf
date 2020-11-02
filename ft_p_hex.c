/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <ezemango@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 09:57:57 by jolim             #+#    #+#             */
/*   Updated: 2020/11/01 18:49:28 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_p_hex(t_spec *spec, va_list *ap)
{
	char	*num;
	int		minlen;
	int		count;

	num = ft_xtoa(va_arg(*ap, unsigned int), spec->sp);
	if (spec->f_dot && spec->precision > 0)
		num = ft_pad_zero(num, spec->precision - ft_strlen(num));
	else if (spec->f_dot && spec->precision == 0 && *num == '0')
	{
		free(num);
		if (!(num = (char *)malloc(1 * sizeof(char))))
			return (0);
		*num = '\0';
	}
	minlen = ft_strlen(num);
	if (spec->f_hyphen)
		num = ft_align_left(num, spec->width - minlen);
	else if (spec->f_zero)
		num = ft_pad_zero(num, spec->width - minlen);
	else
		num = ft_align_right(num, spec->width - minlen);
	count = ft_print_stdout(num);
	free(num);
	return (count);
}
