/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpacor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 03:34:11 by mpacor            #+#    #+#             */
/*   Updated: 2019/12/12 03:34:19 by mpacor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len_dest;
	unsigned int	len_src;

	len_src = 0;
	len_dest = 0;
	while (src[len_src] != '\0')
		len_src++;
	while (dest[len_dest] != '\0' && len_dest < size)
		len_dest++;
	i = len_dest;
	while (size && src[i - len_dest] != '\0' && i < (size - 1))
	{
		dest[i] = src[i - len_dest];
		i++;
	}
	if (len_dest < size)
		dest[i] = '\0';
	return (len_dest + len_src);
}
