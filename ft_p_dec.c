/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_dec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <ezemango@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:36:52 by jolim             #+#    #+#             */
/*   Updated: 2020/11/01 19:29:39 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_neg(t_spec *spec, char *num)
{
	int		len;
	char	*n;

	n = ft_strdup(++num);
	free(--num);
	len = ft_strlen(n);
	if (spec->f_dot && spec->precision > len)
		n = ft_pad_zero(n, spec->precision - len);
	if (spec->f_zero)
		n = ft_pad_zero(n, spec->width - len - 1);
	num = ft_strjoin("-", n);
	free(n);
	len = ft_strlen(num);
	if (spec->f_hyphen)
		num = ft_align_left(num, spec->width - len);
	else
		num = ft_align_right(num, spec->width - len);
	return (num);
}

static char	*ft_pos(t_spec *spec, char *num)
{
	int	min_len;

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

static char	*ft_precise_zero(t_spec *spec, char *num)
{
	if (spec->precision > 0)
	{
		free(num);
		if (!(num = (char *)malloc((spec->precision + 1) * sizeof(char))))
			return (NULL);
		ft_memset(num, '0', spec->precision);
		num[spec->precision] = '\0';
	}
	else if (spec->precision == 0)
	{
		free(num);
		if (!(num = (char *)malloc(1 * sizeof(char))))
			return (NULL);
		num[0] = '\0';
	}
	return (num);
}

static char	*ft_zero(t_spec *spec, char *num)
{
	int	min_len;

	if (spec->f_dot)
		num = ft_precise_zero(spec, num);
	min_len = ft_strlen(num);
	if (spec->precision < spec->width)
	{
		if (spec->f_hyphen)
			num = ft_align_left(num, spec->width - min_len);
		else if (spec->f_zero)
			num = ft_pad_zero(num, spec->width - min_len);
		else
			num = ft_align_right(num, spec->width - min_len);
	}
	return (num);
}

int			ft_p_dec(t_spec *spec, va_list *ap)
{
	char	*num;
	int		count;

	if (spec->f_dot)
		spec->f_zero = 0;
	num = ft_dtoa(va_arg(*ap, int));
	if (*num == '-')
		num = ft_neg(spec, num);
	else if (*num == '0')
		num = ft_zero(spec, num);
	else
		num = ft_pos(spec, num);
	count = ft_print_stdout(num);
	free(num);
	return (count);
}
