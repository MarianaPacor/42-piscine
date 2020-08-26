/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpacor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 03:50:32 by mpacor            #+#    #+#             */
/*   Updated: 2019/12/12 03:51:30 by mpacor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_pepino_com_mel(char **str, int *signal)
{
	while (*str && (**str == ' ' || **str == '\n' || **str == '\t'
		|| **str == '\v' || **str == '\f' || **str == '\r'))
		(*str)++;
	while (**str == '-' || **str == '+')
	{
		if (**str == '-')
			*signal *= -1;
		(*str)++;
	}
}

int		ft_atoi(char *str)
{
	int	soma;
	int	signal;

	soma = 0;
	signal = 1;
	ft_pepino_com_mel(&str, &signal);
	while (*str && *str >= '0' && *str <= '9')
	{
		soma = soma * 10 + (*str - '0');
		++str;
	}
	return (soma * signal);
}
