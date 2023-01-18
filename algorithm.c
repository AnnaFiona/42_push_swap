/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplank <aplank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:40:42 by aplank            #+#    #+#             */
/*   Updated: 2023/01/18 22:23:28 by aplank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_to_b_top(t_data *data, int value, int top, int x)
{
	while(x >= top - 1)
	{
		if (data->head_a->integer <= value)
		{
			if (data->len_b > 1)
				get_position_b(data, data->head_a->integer);
			else if (data->len_b == 1 && data->head_a->integer < data->head_b->integer)
				data->pos_b++;
			push_stack(data, &data->head_a, &data->head_b, 'b');
		}
		if (x >= top)
			reverse_rotate_stack(&data->head_a, 'a');
		x--;
	}
	finish_rotate_b(data);
	return (x);
}

static int	push_to_b_bot(t_data *data, int value, int bot, int x)
{
	while(x <= bot)
	{
		if (data->head_a->integer >= value)
		{
			if (data->len_b > 1)
				get_position_b(data, data->head_a->integer);
			else if (data->len_b == 1 && data->head_a->integer < data->head_b->integer)
				data->pos_b++;
			push_stack(data, &data->head_a, &data->head_b, 'b');
		}
		else
			rotate_stack(&data->head_a, 'a');
		x++;
	}
	finish_rotate_b(data);
	return (x);
}


int	push_to_a(t_data *data, int count)
{
	int	x;
	int	i;

	i = 0;
	x = data->len_b;
	while (data->len_b > 0)
	{
		push_stack(data, &data->head_b, &data->head_a, 'a');
	}
	if (count % 2 != 0)
	{
		while (i < data->eighth)
		{
			rotate_stack(&data->head_a, 'a');
			i++;
		}
	}
	return (x);
}

void	finish_rotate_a(t_data *data, int x)
{
	if (data->divider % 2 == 0)
	{
		while (x < data->len_a)
		{
			rotate_stack(&data->head_a, 'a');
			x++;
		}
	}
	else
	{
		while (x >= 0)
		{
			reverse_rotate_stack(&data->head_a, 'a');
			x--;
		}
	}
}


void	algorithm(t_data *data)
{
	t_stack	*temp;
	int		count;
	int		bot;
	int		top;
	int		x;

	x = 0;
	top = 0;
	count = 0;
	bot = data->len_a - 1;
	temp = data->help_list->prev;
	while (count <= data->help_len)
	{
		if (count % 2 == 0)
		{
			x = push_to_b_bot(data, temp->integer, bot, x);
			bot -= push_to_a(data, count);
			temp = temp->prev;
			x = bot;
		}
		else
		{
			x = push_to_b_top(data, data->help_list->integer, top, x);
			top += push_to_a(data, count);
			data->help_list = data->help_list->next;
			x = top;
		}
		count++;
	}
	finish_rotate_a(data, x);
}