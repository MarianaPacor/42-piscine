/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpacor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:46:25 by mpacor            #+#    #+#             */
/*   Updated: 2019/11/26 21:43:44 by mpacor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	put_char(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (a < 100)
	{
		b = a + 1;
		while (b < 100)
		{
			put_char(a / 10 + '0');
			put_char(a % 10 + '0');
			put_char(' ');
			put_char(b / 10 + '0');
			put_char(b % 10 + '0');
			write(1, ", ", 2);
			b++;
		}
		a++;
	}
	write(1, "\b\b", 2);
}
