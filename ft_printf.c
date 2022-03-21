/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcobos-d <jcobos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:38:30 by jcobos-d          #+#    #+#             */
/*   Updated: 2022/03/21 17:38:00 by jcobos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(long nbr, char *base, int size);
int	ft_writeabs(int nbr, char *base);
int	ft_putstr_fd_counter(char *s, int fd);
int	ft_putptr(long nbr);

int	ft_printf(const char *str, ...)
{
	va_list	arguments;
	int		retval;

	va_start(arguments, str);
	retval = 0;
	while (*str)
	{
		if (*str != '%')
			retval += write(1, str, 1);
		else
		{
			if (*(str + 1) == 'c')
			{
				char c = va_arg(arguments, int);
				retval += write(1, &c, 1); // could we do: retval += write(1, &va_arg(arguments, int), 1) ??
			}
			else if (*(str + 1) == 's')
				retval += ft_putstr_fd_counter(va_arg(arguments, char *), 1);
			else if (*(str + 1) == 'p')
				retval += ft_putptr((long)(va_arg(arguments, void*)));
			else if (*(str + 1) == 'd' || *(str + 1) == 'i')
					retval += ft_putnbr_base(va_arg(arguments, int), "0123456789", 10);
			else if (*(str + 1) == 'u')
					retval += ft_putnbr_base(va_arg(arguments, unsigned int), "0123456789", 10);
			else if (*(str + 1) == 'x')
				retval += ft_putnbr_base(va_arg(arguments, unsigned int), "0123456789abcdef", 16);
			else if (*(str + 1) == 'X')
				retval += ft_putnbr_base(va_arg(arguments, unsigned int), "0123456789ABCDEF", 16);
			else if (*(str + 1) == '%')
				retval += write(1, "%", 1);
			str++;
		}
		str++;
	}
	va_end(arguments);
	return (retval);
}

int	ft_putstr_fd_counter(char *s, int fd)
{
	int	pos;

	if (!s)
		return (-1);
	pos = 0;
	while (s[pos])
	{
		write(fd, s + pos, 1); // can I pos += write?
		pos++;
	}
	return (pos);
}

int	ft_putnbr_base(long nbr, char *base, int size)
{
	int	retval;

	retval = 0;
	if (nbr == 0)
		retval += write(1, base, 1);
	else if (nbr / size != 0)
	{
		retval += ft_putnbr_base(nbr / size, base, size);
		retval += ft_writeabs(nbr % size, base);
	}
	else
	{
		if (nbr < 0)
			retval += write(1, "-", 1);
		retval += ft_writeabs(nbr, base);
	}
	return (retval);
}

int	ft_writeabs(int nbr, char *base)
{
	char	c;

	if (nbr < 0)
		c = *(base - nbr);
	else
		c = *(base + nbr);
	return (write(1, &c, 1));
}

int	ft_putptr(long nbr)
{
	int		retval;
	char	c;
	long int		pow_hex;

	//printf("my address is %l \n", nbr);
	pow_hex = 4294967296;
	retval = write(1, "0x", 2);
	while (pow_hex > 0)
	{
		if (nbr / pow_hex < 10)
			c = nbr / pow_hex + '0';
		else
			c = nbr / pow_hex + 'a' - 10;
		retval += write(1, &c, 1);
		nbr = nbr % pow_hex;
		pow_hex = pow_hex / 16;
	}
	return (retval);
}