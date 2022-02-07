/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcobos-d <jcobos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:38:30 by jcobos-d          #+#    #+#             */
/*   Updated: 2022/02/07 16:44:09 by jcobos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"


int	ft_printf(const char *str, ...)
{
	va_list	arguments;
	//int		retval;

	va_start(arguments, str);
	while (*str)
	{
		if (*str != '%')
			write(1, str, 1);
		else
		{
			if (*(str + 1) == 'c')
			{
				char c = va_arg(arguments, int);
				write(1, &c, 1);
			}
			//else if (*(str + 1) == 's')
			//	ft_putstr_fd(va_arg(arguments, char *), 1);
//			else if (*(str + 1) == 'p')
				//print pointer
//			else if (*(str + 1) == 'd' || *(str + 1) == 'i')
				//putnbr
//			else if (*(str + 1) == 'u')
				//putnbr unsigned
//			else if (*(str + 1) == 'x')
				//putnbr base hexa small
//			else if (*(str + 1) == 'X')
				//putnbr base hexa big
			else if (*(str + 1) == '%')
				write(1, "P", 1);
			str++;
		}
		str++;
	}
	write(1, "done in printf\n", 16);
	//va_end(arguments);

	return 1;
}