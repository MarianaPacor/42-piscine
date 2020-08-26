/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltakahas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 19:12:50 by ltakahas          #+#    #+#             */
/*   Updated: 2019/11/24 19:53:27 by ltakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_putchar(char c);
int topline (int x, int y);
int midline (int x, int y);
int botline (int x);

/*
**--- Rush function---
*/

int	rush(int x, int y)
{
	if (x != 0 && y != 0)
	{
		topline(x, y);
	}
	return (0);
}

/*
**--- Topline function---
*/

int	topline(int x, int y)
{
	int		a[x];
	int		c;
	char	car1;
	char	car2;
	char	car3;

	car1 = 'A';
	car2 = 'B';
	car3 = 'A';
	c = 0;
	while (c < x - 1)
	{
		a[0] = car1;
		a[c + 1] = car2;
		ft_putchar(a[c]);
		c++;
	}
	a[x - 1] = car3;
	ft_putchar(a[x - 1]);
	ft_putchar('\n');
	if (y != 1)
	{
		midline(x, y);
	}
	return (0);
}

/*
**--- Midline function---
*/

int	midline(int x, int y)
{
	int		a[y][x];
	int		l;
	int		c;
	char	car1;

	l = 0;
	car1 = 'B';
	while (l < y - 2)
	{
		c = 0;
		while (c < x - 1)
		{
			a[l][0] = car1;
			a[l][c + 1] = ' ';
			ft_putchar(a[l][c]);
			c++;
		}
		a[l][x - 1] = car1;
		ft_putchar(a[l][x - 1]);
		ft_putchar('\n');
		l++;
	}
	botline(x);
	return (0);
}

/*
**--- Botline function---
*/

int	botline(int x)
{
	int		a[x];
	int		c;
	char	car1;
	char	car2;
	char	car3;

	c = 0;
	car1 = 'C';
	car2 = 'B';
	car3 = 'C';
	while (c < x - 1)
	{
		a[0] = car1;
		a[c + 1] = car2;
		ft_putchar(a[c]);
		c++;
	}
	a[x - 1] = car3;
	ft_putchar(a[x - 1]);
	ft_putchar('\n');
	return (0);
}
