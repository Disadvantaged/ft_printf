/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_charchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgolear <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 13:47:27 by dgolear           #+#    #+#             */
/*   Updated: 2017/02/19 13:52:14 by dgolear          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_width(t_param *params)
{
	int		width;

	width = params->width;
	if (width == 0)
		params->width = 1;
	while (width > 1)
	{
		if (params->flags[2].sign)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width--;
	}
}

int			print_char(t_param *params, va_list ap, char letter)
{
	char	c;

	if (params->mod == l)
		return (print_wchar(params, ap, letter));
	c = va_arg(ap, int);
	if (params->flags[1].sign)
	{
		ft_putchar(c);
		print_width(params);
	}
	else
	{
		print_width(params);
		ft_putchar(c);
	}
	return (params->width);
}
