/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcobos-d <jcobos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:38:30 by jcobos-d          #+#    #+#             */
/*   Updated: 2022/04/26 12:48:56 by jcobos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr_b(long nbr, char *base, int size);
int	ft_writeabs(int nbr, char *base);
int	ft_putstr_fd_counter(char *s, int fd);
int	print_classify(char c, va_list ap);
int	ft_putptr(unsigned long nbr, char *base, int size);

int	print_classify(char c, va_list ap)
{
	int		ret;

	ret = 0;
	if (c == 's')
		ret = ft_putstr_fd_counter(va_arg(ap, char *), 1);
	else if (c == 'p')
	{
		ret = write(1, "0x", 2);
		ret += ft_putptr(va_arg(ap, unsigned long), "0123456789abcdef", 16);
	}
	else if (c == 'd' || c == 'i')
		ret = putnbr_b(va_arg(ap, int), "0123456789", 10);
	else if (c == 'u')
		ret = putnbr_b(va_arg(ap, unsigned int), "0123456789", 10);
	else if (c == 'x')
		ret = putnbr_b(va_arg(ap, unsigned int), "0123456789abcdef", 16);
	else if (c == 'X')
		ret = putnbr_b(va_arg(ap, unsigned int), "0123456789ABCDEF", 16);
	else if (c == '%')
		ret = write(1, "%", 1);
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	va_list	arguments;
	int		retval;
	char	toprint;

	va_start(arguments, str);
	retval = 0;
	while (*str)
	{
		if (*str != '%')
			retval += write(1, str, 1);
		else
		{
			str++;
			if (*(str) == 'c')
			{
				toprint = va_arg(arguments, int);
				retval += write(1, &toprint, 1);
			}
			else
				retval += print_classify(*(str), arguments);
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
		return (write(1, "(null)", 6));
	pos = 0;
	while (s[pos])
	{
		write(fd, s + pos, 1);
		pos++;
	}
	return (pos);
}

int	putnbr_b(long nbr, char *base, int size)
{
	int	retval;

	retval = 0;
	if (nbr == 0)
		retval += write(1, base, 1);
	else if (nbr / size != 0)
	{
		retval += putnbr_b(nbr / size, base, size);
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
