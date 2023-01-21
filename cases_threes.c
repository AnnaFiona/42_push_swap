/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_threes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ip <ip@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:09:38 by ip                #+#    #+#             */
/*   Updated: 2023/01/21 17:34:03 by ip               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    case_three_two_one(t_data *data)
{
	swap_stack(data->head_a, 'a');
	reverse_rotate_stack(&data->head_a, 'a');
}

void    case_three_one_two(t_data *data)
{
	rotate_stack(&data->head_a, 'a');
}

void    case_two_three_one(t_data *data)
{
	reverse_rotate_stack(&data->head_a, 'a');
}

void    case_two_one_three(t_data *data)
{
	swap_stack(data->head_a, 'a');
}

void    case_one_three_two(t_data *data)
{
	reverse_rotate_stack(&data->head_a, 'a');
	swap_stack(data->head_a, 'a');
}
