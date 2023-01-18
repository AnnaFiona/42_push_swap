/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplank <aplank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:08:01 by aplank            #+#    #+#             */
/*   Updated: 2023/01/14 18:28:28 by aplank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack *head, char c)
{
	int	x;

	x = head->next->integer;
	head->next->integer = head->integer;
	head->integer = x;
	if (c == 'a' || c == 'b')
		ft_printf("s%c\n", c);
}

void	rotate_stack(t_stack **head, char c)
{
	*head = (*head)->next;
	if (c == 'a' || c == 'b')
		ft_printf("r%c\n", c);
}

void	reverse_rotate_stack(t_stack **head, char c)
{
	*head = (*head)->prev;
	if (c == 'a' || c == 'b')
		ft_printf("rr%c\n", c);
}

void	push_stack(t_data *data, t_stack **head_push, \
				t_stack **head_recieve, char r)
{
	t_stack *temp;

	if ((data->len_a == 0 && r == 'b') || (data->len_b == 0 && r == 'a'))
		return ;
	(*head_push)->prev->next = (*head_push)->next;
	(*head_push)->next->prev = (*head_push)->prev;
	temp = *head_push;
	*head_push = (*head_push)->next;
	make_node(&*head_recieve, temp->integer);
	reverse_rotate_stack(&*head_recieve, 'x');
	free(temp);
	if (r == 'a')
	{
		data->len_b--;
		data->len_a++;
	}
	if (r == 'b')
	{
		data->len_a--;
		data->len_b++;
	}
	ft_printf("p%c\n", r);
}
