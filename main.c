/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ip <ip@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:51:43 by aplank            #+#    #+#             */
/*   Updated: 2023/01/24 00:35:12 by ip               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_node(t_stack **head, int integer)
{
	t_stack	*node;

	if (!*head)
	{
		*head = malloc(sizeof(t_stack));
		(*head)->next = *head;
		(*head)->prev = *head;
		(*head)->integer = integer;
		return ;
	}
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->integer = integer;
	node->next = *head;
	(*head)->prev->next = node;
	node->prev = (*head)->prev;
	(*head)->prev = node;
}

void	convert_input(t_data *data, char *input[])
{
	char	*arr;
	int		x;
	int		y;
	int		z;

	y = 1;
	data->len_a = 0;
	check_input(data, input);
	while (input[y])
	{
		x = 0;
		while (input[y][x])
		{
			z = 0;
			while (input[y][x] == ' ')
				x++;
			while (input[y][x + z] && input[y][x + z] != ' ')	
				z++;
			arr = ft_substr(input[y], x, z);
			make_node(&data->head_a, atoi_with_int_check(data, arr));
			free(arr);
			data->len_a++;
			x += z;
		}
		y++;
	}
}

void	initialize_data(t_data *data)
{
	data->head_a = NULL;
	data->head_b = NULL;
	data->help_list = NULL;
	data->len_a = 0;
	data->len_b = 0;
	data->pos_b = 0;
	data->help_len = 0;
	data->eighth = 0;
}

int	main(int argc, char *argv[])
{
	t_data *data;

	data = malloc(sizeof(t_data));
	initialize_data(data);
	if (argc < 2)
	{
		exit_function(data);
	}
	convert_input(data, argv);
	if (!data->head_a)
		return (1);
	redirect(data);
	make_help_list(data, data->head_a, data->len_a);
	algorithm(data);
	exit_function(data);
	return (0);
}

void print_list(t_stack *head, int len)
{
	int	x;

	x = 0;
	while(len != x)
	{
		ft_printf("a: %i\n", head->integer);
		head = head->next;
		x++;
	}
}
