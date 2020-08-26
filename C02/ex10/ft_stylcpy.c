/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stylcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpacor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 20:40:27 by mpacor            #+#    #+#             */
/*   Updated: 2019/12/04 12:37:17 by mpacor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (src[i] != '\0' && i < size)
	{
		src[i] = dest[i];
		i++;
	}
	while (dest[i] < dest[size])
	{
		dest[i] = '\0';
		i++;
	}
	return (i);
}
