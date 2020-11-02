/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <ezemango@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 09:20:34 by jolim             #+#    #+#             */
/*   Updated: 2020/10/31 17:15:02 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_hex_upper_alloc(unsigned long long num, char *a, int len)
{
	int		i;
	char	*hex;

	hex = "0123456789ABCDEF";
	i = 0;
	while (num != 0)
	{
		a[len - i - 1] = hex[num % 16];
		num /= 16;
		i++;
	}
	a[len] = '\0';
	return (a);
}

static char	*ft_hex_lower_alloc(unsigned long long num, char *a, int len)
{
	unsigned int	i;
	char			*hex;

	hex = "0123456789abcdef";
	i = 0;
	while (num != 0)
	{
		a[len - i - 1] = hex[num % 16];
		num /= 16;
		i++;
	}
	a[len] = '\0';
	return (a);
}

char		*ft_xtoa(unsigned long long i, char x)
{
	unsigned int		len;
	char				*a;
	unsigned long long	num;

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
		num /= 16;
	}
	if (!(a = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	if (x == 'X')
		return (ft_hex_upper_alloc(i, a, len));
	return (ft_hex_lower_alloc(i, a, len));
}
