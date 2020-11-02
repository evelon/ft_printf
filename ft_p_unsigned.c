/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_unsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <ezemango@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 11:26:01 by jolim             #+#    #+#             */
/*   Updated: 2020/11/01 19:42:35 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_unsigned(t_spec *spec, char *num)
{
	unsigned int	min_len;

	min_len = ft_strlen(num);
	if (spec->f_dot)
		num = ft_pad_zero(num, spec->precision - min_len);
	min_len = ft_strlen(num);
	if (spec->f_hyphen)
		num = ft_align_left(num, spec->width - min_len);
	else if (spec->f_zero)
		num = ft_pad_zero(num, spec->width - min_len);
	else
		num = ft_align_right(num, spec->width - min_len);
	return (num);
}

static char	*ft_u_zero(t_spec *spec, char *num)
{
	unsigned int	min_len;

	min_len = ft_strlen(num);
	if (spec->f_dot)
	{
		free(num);
		if (!(num = (char *)malloc(1 * sizeof(char))))
			return (NULL);
		*num = '\0';
		num = ft_pad_zero(num, spec->precision);
	}
	min_len = ft_strlen(num);
	if (spec->f_hyphen)
		num = ft_align_left(num, spec->width - min_len);
	else if (spec->f_zero)
		num = ft_pad_zero(num, spec->width - min_len);
	else
		num = ft_align_right(num, spec->width - min_len);
	return (num);
}

int			ft_p_unsigned(t_spec *spec, va_list *ap)
{
	char	*num;
	int		count;

	if (spec->f_dot)
		spec->f_zero = 0;
	num = ft_utoa(va_arg(*ap, unsigned int));
	if (*num == '0')
		num = ft_u_zero(spec, num);
	else
		num = ft_unsigned(spec, num);
	count = ft_print_stdout(num);
	free(num);
	return (count);
}
