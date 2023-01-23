/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_four_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ip <ip@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 23:53:34 by aplank           #+#    #+#             */
/*   Updated: 2023/01/23 23:53:34 by ip               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_biggest_int(t_stack *head, int len)
{
	int	place;
	int	x;

	x = 0;
	place = 0;
	while (x < len)
	{
		if (head->integer < head->next->integer)
			place = x;
		x++;
	}
	return (place);
}

static void	get_biggest_int(t_stack **head, int len, char c)
{
	int place;

	place = find_biggest_int(head, len);
	while (place > 0)
	{
		rotate_stack(head, c);
		place--;
	}
}

void	case_four(t_data *data)
{
	get_biggest_int(&data->head_a, data->len_a, 'a');
	push_stack(data, data->head_a, data->head_b, 'b');
	redirect_threes(data);
	push_stack(data, data->head_b, data->head_a, 'a');
	rotate_stack(&data->head_a, 'a');
}

void	case_five(t_data *data)
{
	get_biggest_int(&data->head_a, data->len_a, 'a');
	push_stack(data, data->head_a, data->head_b, 'b');
	get_biggest_int(&data->head_a, data->len_a, 'a');
	push_stack(data, data->head_a, data->head_b, 'b');
	redirect_threes(data);
	push_stack(data, data->head_b, data->head_a, 'a');
	rotate_stack(&data->head_a, 'a');
	push_stack(data, data->head_b, data->head_a, 'a');
	rotate_stack(&data->head_a, 'a');
}