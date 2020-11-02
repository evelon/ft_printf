/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_spec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <ezemango@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 14:26:24 by jolim             #+#    #+#             */
/*   Updated: 2020/11/01 13:40:43 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_read_width(char **c, va_list *ap)
{
	int	p;
	int	num;

	p = 0;
	num = 0;
	if (**c == '*')
	{
		num = va_arg(*ap, int);
		(*c)++;
		return (num);
	}
	while (**c <= '9' && **c >= '0')
	{
		num *= 10;
		num += **c - '0';
		(*c)++;
	}
	return (num);
}

static int		ft_read_precision(char **c, va_list *ap)
{
	int	num;

	if (**c == '*')
	{
		num = va_arg(*ap, int);
		(*c)++;
		return (num);
	}
	num = 0;
	if (**c > '9' || **c < '0')
		return (0);
	if (**c == '0')
		(*c)++;
	while (**c <= '9' && **c >= '0')
	{
		num *= 10;
		num += **c - '0';
		(*c)++;
	}
	return (num);
}

static char		ft_read_sp(char **c)
{
	char	*specifier;
	int		i;

	specifier = "cspdiuxX%";
	i = 0;
	while (specifier[i])
	{
		if (**c == specifier[i])
			return (*((*c)++));
		i++;
	}
	return (0);
}

static t_spec	*ft_read_flag(t_spec *spec, char **c)
{
	while (**c == '-' || **c == '0')
	{
		if (**c == '0')
			spec->f_zero = 1;
		else
			spec->f_hyphen = 1;
		(*c)++;
	}
	if (spec->f_hyphen == 1)
		spec->f_zero = 0;
	return (spec);
}

t_spec			*ft_read_spec(char **c, va_list *ap)
{
	t_spec	*spec;

	spec = ft_set_spec();
	ft_read_flag(spec, c);
	spec->width = ft_read_width(c, ap);
	if (spec->width < 0)
	{
		spec->f_hyphen = 1;
		spec->width *= -1;
		spec->f_zero = 0;
	}
	if (**c == '.')
	{
		spec->f_dot = 1;
		(*c)++;
		if (0 > (spec->precision = ft_read_precision(c, ap)))
		{
			spec->f_dot = 0;
			spec->precision = 0;
		}
	}
	if (spec->f_dot)
		spec->f_zero = 0;
	spec->sp = ft_read_sp(c);
	return (spec);
}
