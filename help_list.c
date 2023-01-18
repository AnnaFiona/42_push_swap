/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplank <aplank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:27:34 by aplank            #+#    #+#             */
/*   Updated: 2023/01/18 18:30:48 by aplank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_value( t_stack *head, int eighth)
{
	int x;

	x = 0;
	while (x < eighth)
	{
		head = head->next;
		x++;
	}
	return (head->prev->integer);
}

static void	get_marker_values(t_data *data, t_stack *head, int len, int	divider)
{
	int	value;

	value = len / divider;
	data->eighth = len / divider;
	while (value + data->eighth <= data->len_a)
	{
		make_node(&data->help_list, find_value(head, value));
		data->help_len++;
		value += data->eighth;
	}
}

void	make_help_list(t_data *data, t_stack *head, int len)
{
	t_stack	*head_h;
	t_stack *temp;
	int		x;

	x = 0;
	head_h = NULL;
	temp = head;
	while (x < len)
	{
		make_node(&head_h, temp->integer);
		temp = temp->next;
		x++;
	}
	mixed_bubble_sort(&head_h, len, 'h');
	get_marker_values(data, head_h, len, data->divider);
	check_list(data, head_h);
	free_list(head_h, len);
}

