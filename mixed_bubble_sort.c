/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mixed_bubble_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplank <aplank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:22:05 by aplank            #+#    #+#             */
/*   Updated: 2023/01/12 16:30:30 by aplank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	bubble_sort(t_stack **head, int bot, int x, char c)
{
	int	check;

	check = 0;
	if((*head)->integer > (*head)->next->integer && (x + 1 != bot))
	{
		swap_stack((*head), c);
		check++;
	}
	if (x + 1 != bot)
		rotate_stack(&(*head), c);
	return (check);
}

static int	reverse_bubble_sort(t_stack **head, int top, int x, char c)
{
	int	check;

	check = 0;
	if (x - 1 != top)
		reverse_rotate_stack(&(*head), c);
	if((*head)->integer > (*head)->next->integer && (x - 1 != top))
	{
		swap_stack((*head), c);
		check++;
	}
	return (check);
}

void    mixed_bubble_sort(t_stack **head, int len, char c)
{
	t_stack	*temp;
	int		check;
	int		top;
	int		bot;
	int		x;

	x = 0;
	top = 0;
	check = 1;
	bot = len;
	temp = (*head);
	while (top < bot || check == 0)
	{
		check = 0;
		while (x < bot)
		{
			check += bubble_sort(head, bot, x, c);
			x++;
		}
		if (check == 0)
			break ;
		bot--;
		while (x > top)
		{
			check += reverse_bubble_sort(head, top, x, c);
			x--;
		}
		top++;
	}
	while ((*head) != temp)
		rotate_stack(&(*head), c);
}