/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpacor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:15:23 by mpacor            #+#    #+#             */
/*   Updated: 2019/11/26 19:44:26 by mpacor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned aux;

	if (nb < 0)
	{
		nb = nb * (-1);
		aux = nb;
		put_char('-');
	}
	aux = nb;
	if (aux >= 10)
	{
		ft_putnbr(aux / 10);
		ft_putnbr(aux % 10);
	}
	else
	{
		put_char(aux + '0');
	}
}
