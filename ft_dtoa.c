/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <ezemango@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 09:20:34 by jolim             #+#    #+#             */
/*   Updated: 2020/11/01 19:32:13 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_signed_alloc(int num, char *a, int len)
{
	int		i;
	int		sign;

	if (num < 0)
		sign = -1;
	else
		sign = 1;
	i = 0;
	if (num < 0)
		a[i] = '-';
	while (num != 0)
	{
		a[len - i - 1] = num % 10 * sign + '0';
		num /= 10;
		i++;
	}
	a[len] = '\0';
	return (a);
}

char		*ft_dtoa(int i)
{
	int		len;
	char	*a;
	int		num;

	if (i == 0)
	{
		if (!(a = (char *)malloc(2 * sizeof(char))))
			return (NULL);
		a[0] = '0';
		a[1] = '\0';
		return (a);
	}
	num = i;
	len = 0;
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	if (i < 0)
		len++;
	if (!(a = (char *)malloc((len + 1) * sizeof(int))))
		return (NULL);
	return (ft_signed_alloc(i, a, len));
}

static char	*ft_unsigned_alloc(unsigned int num, char *a, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (num != 0)
	{
		a[len - i - 1] = num % 10 + '0';
		num /= 10;
		i++;
	}
	a[len] = '\0';
	return (a);
}

char		*ft_utoa(unsigned int i)
{
	unsigned int	len;
	char			*a;
	unsigned int	num;

	if (i == 0)
	{
		if (!(a = (char *)malloc(2 * sizeof(char))))
			return (NULL);
		a[0] = '0';
		a[1] = '\0';
		return (a);
	}
	num = i;
	len = 0;
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	if (i < 0)
		len++;
	if (!(a = (char *)malloc((len + 1) * sizeof(int))))
		return (NULL);
	return (ft_unsigned_alloc(i, a, len));
}
