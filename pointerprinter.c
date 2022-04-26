/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointerprinter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcobos-d <jcobos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:51:00 by jcobos-d          #+#    #+#             */
/*   Updated: 2022/04/26 12:51:07 by jcobos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_writeabs(int nbr, char *base);

int	ft_putptr(unsigned long nbr, char *base, int size)
{
	int	retval;

	retval = 0;
	if (nbr == 0)
		retval += write(1, base, 1);
	else if (nbr / size != 0)
	{
		retval += ft_putptr(nbr / size, base, size);
		retval += ft_writeabs(nbr % size, base);
	}
	else
		retval += ft_writeabs(nbr, base);
	return (retval);
}
