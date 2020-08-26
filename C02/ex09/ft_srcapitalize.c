/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srcapitalize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpacor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:19:17 by mpacor            #+#    #+#             */
/*   Updated: 2019/12/12 03:07:07 by mpacor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] = str[i] + 32;
		i++;
	}
	if (str[0] >= 97 && str[0] <= 122)
		str[0] = str[0] - 32;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i - 1] >= 32 && str[i - 1] <= 46)
		{
			if (str[i] >= 97 && str[i] <= 122)
				str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}
