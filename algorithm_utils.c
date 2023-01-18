/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplank <aplank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 22:21:48 by aplank            #+#    #+#             */
/*   Updated: 2023/01/18 22:24:16 by aplank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate_direction(t_data *data, int new_int)
{
	t_stack *temp;
	int		count;
	int		pos;

	count = 0;
	pos = data->pos_b;
	temp = data->head_b;
	while (!(temp->integer > new_int && temp->next->integer < new_int) && \
			!(temp->integer > new_int && pos == data->len_b - 1) && \
 			!(temp->next->integer < new_int && pos == 0))
	{
		temp = temp->next;
		pos++;
		if (pos > data->len_b - 1)
			pos = 0;
		count++;
	}
	if (count <= data->len_b / 2)
		return (count * -1);
	else
		return ((data->len_b) - count);
}

static int	find_position_b(t_data *data, int new_int, int direction)
{
	if ((data->head_b->integer > new_int && data->head_b->next->integer < new_int) || \
		(data->head_b->integer > new_int && data->pos_b == data->len_b - 1) || \
		(data->head_b->next->integer < new_int && data->pos_b == 0))
		return (1);
	if (direction < 0)
	{
		rotate_stack(&data->head_b, 'b');
		data->pos_b++;
	}
	else if (direction > 0)
	{
		reverse_rotate_stack(&data->head_b, 'b');
		data->pos_b--;
	}
	if (data->pos_b < 0)
		data->pos_b = data->len_b - 1;
	if (data->pos_b > data->len_b - 1)
		data->pos_b = 0;
	return (0);
}

void	get_position_b(t_data *data, int new_int)
{
	int direction;

	direction = rotate_direction(data, new_int);
	while (find_position_b(data, new_int, direction) == 0);
	if (data->head_b->integer > new_int && data->head_b->next->integer < new_int)
	{
		rotate_stack(&data->head_b, 'b');
		data->pos_b++;
		if (data->pos_b > data->len_b)
			data->pos_b = 0;
	}
	if ((data->head_b->integer > new_int && data->pos_b == data->len_b - 1))
	{
		rotate_stack(&data->head_b, 'b');
		data->pos_b++;
	}
}

void	finish_rotate_b(t_data *data)
{
	if (data->pos_b >= data->len_b / 2)
	{
		while (data->pos_b < data->len_b)
		{
			rotate_stack(&data->head_b, 'b');
			data->pos_b++;
		}
	}
	else
	{
		while (data->pos_b != 0)
		{
			reverse_rotate_stack(&data->head_b, 'b');
			data->pos_b--;
		}
	}
	data->pos_b = 0;
}
