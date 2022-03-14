/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcobos-d <jcobos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:38:30 by jcobos-d          #+#    #+#             */
/*   Updated: 2022/03/14 19:33:21 by jcobos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"


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
			{
				char *strvar = va_arg(arguments, char *);
				ft_putstr_fd(strvar, 1);	//modify to count characters, see below
			}
			//			else if (*(str + 1) == 'p')
				//print pointer
			else if (*(str + 1) == 'd' || *(str + 1) == 'i')
				{
					int n = va_arg(arguments, int);
					ft_putnbr_fd(n, 1);		//modify to count characters
				}
			else if (*(str + 1) == 'u')
				{
					unsigned int n = va_arg(arguments, unsigned int);
					ft_putnbr_fd(n, 1);		//this bad, count chars
				}
			//else if (*(str + 1) == 'x')
			//{
				//putnbr base
			//}
//			else if (*(str + 1) == 'X')
				//putnbr base hexa big
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