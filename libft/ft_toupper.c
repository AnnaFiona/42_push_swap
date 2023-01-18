/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplank <aplank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:10:43 by aplank            #+#    #+#             */
/*   Updated: 2022/10/24 12:28:29 by aplank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int x)
{
	if (x >= 97 && x <= 122)
		return (x -= 32);
	return (x);
}
/*
int	main(void)
{
	printf("%c\n", ft_toupper('+'));
}*/