/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_and_frees.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ip <ip@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 14:13:28 by aplank            #+#    #+#             */
/*   Updated: 2023/01/21 18:14:09 by ip               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_input(t_data *data, char *input[])
{
	int		x;
	int		y;

	y = 1;
	while (input[y])
	{
		x = 0;
		while (input[y][x])
		{
			if (!((input[y][x] >= '0' && input[y][x] <= '9') || input[y][x] == ' ' || input[y][x] == '-'))
			{
				ft_printf ("Error\n");
				exit_function(data);
			}
			if (input[y][x] == '-' && !(input[y][x + 1] >= '0' && input[y][x + 1] <= '9'))
			{
				ft_printf ("Error\n");
				exit_function(data);
			}
			x++;
		}
		y++;
	}
}

/* void	check_list(t_data *data, t_stack *head)
{
	t_stack	*temp;

	temp = head;
	while (temp->next != head)
	{
		if (temp->integer == temp->next->integer)
		{
			ft_printf("Error\n");
			exit_function(data);
		}
		temp = temp->next;
	}
} */

void	doubles_check(t_data *data)
{
	t_stack	*temp;
	t_stack	*rotater;

	temp = data->head_a;
	if (data->len_a == 2 && temp->integer == temp->next->integer)
	{
		ft_printf("Error\n");
		exit_function(data);
	}
	while (temp->next != data->head_a)
	{
		rotater = temp->next;
		while (rotater->next != data->head_a)
		{
			if (temp->integer == rotater)
			{
				ft_printf("Error\n");
				exit_function(data);
			}
			rotater = rotater->next;
		}
		temp = temp->next;
	}
}


void	free_list(t_stack *head, int len)
{
	t_stack	*temp;

	while(len > 0)
	{
		temp = head;
		head = head->next;
		free(temp);
		len--;
	}
}

void exit_function(t_data *data)
{
	if (data->head_a)
		free_list(data->head_a, data->len_a);
	if (data->head_b)
		free_list(data->head_b, data->len_b);
	if (data->help_list)
		free_list(data->help_list, data->help_len);
	free(data);
	exit(0);
}