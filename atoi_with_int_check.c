/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_with_int_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplank <aplank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:19:05 by aplank            #+#    #+#             */
/*   Updated: 2023/01/17 14:19:06 by aplank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_int(t_data *data, char *nptr, long long int i)
{
	if (i > 2147483647 || i < -2147483648)
		{
			free(nptr);
			ft_printf ("Error\n");
			exit_function(data);
		}
}

int	atoi_with_int_check(t_data *data, char *nptr)
{
	long long int	m;
	long long int	i;
	int				x;

	x = 0;
	i = 0;
	m = 1;
	while (nptr[x] == ' ' || (nptr[x] >= 9 && nptr[x] <= 13))
		x++;
	if (nptr[x] == '-' || nptr[x] == '+')
	{
		if (nptr[x] == '-')
			m *= -1;
		x++;
	}
	while (nptr[x] >= '0' && nptr[x] <= '9')
	{
		i = i * 10 + (nptr[x] - 48);
		x++;
	}
	check_int(data, nptr, i);
	return (i * m);
}
