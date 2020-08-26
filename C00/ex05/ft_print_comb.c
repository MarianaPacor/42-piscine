/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpacor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 00:18:52 by mpacor            #+#    #+#             */
/*   Updated: 2019/11/27 20:40:05 by mpacor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int g_a;
int g_b;
int g_c;

char	print_char(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	g_a = 0;
	g_b = 1;
	g_c = 2;
	while (g_a <= 7)
	{
		while (g_b <= 8)
		{
			while (g_c <= 9)
			{
				print_char(g_a + '0');
				print_char(g_b + '0');
				print_char(g_c + '0');
				write(1, ", ", 2);
				g_c++;
			}
			g_c = g_b + 2;
			g_b++;
		}
		g_b = g_a + 2;
		g_c = g_b + 1;
		g_a++;
	}
	write(1, "\b\b", 2);
}

int main()
{
	ft_print_comb();
}
