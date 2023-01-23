/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_divider_and_redirect.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ip <ip@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:42:21 by aplank            #+#    #+#             */
/*   Updated: 2023/01/24 00:33:02 by ip               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_divider(t_data *data)
{
	if (data->len_a >= 10000)
		data->divider = 51;
	else if (data->len_a >= 5000)
		data->divider = 35;
	else if (data->len_a >= 1000)
		data->divider = 21;
	else if (data->len_a >= 500)
		data->divider = 11;
	else if (data->len_a >= 100)
		data->divider = 5;
	else if (data->len_a >= 50)
		data->divider = 7;
	else if (data->len_a < 50)
		data->divider = 3;
}


void	redirect_threes(t_data *data)
{
	t_stack	*temp;

	temp = data->head_a;
	if (temp->integer > temp->next->integer && temp->integer > temp->prev->integer)
	{
		if (temp->next->integer > temp->prev->integer)
			case_three_two_one(data);
		else if (temp->next->integer < temp->prev->integer)
			case_three_one_two(data);
	}
	else if (temp->integer < temp->next->integer && temp->integer > \
			temp->prev->integer && temp->next->integer > temp->prev->integer)
		case_two_three_one(data);
	else if (temp->integer > temp->next->integer && temp->integer < \
			temp->prev->integer && temp->next->integer < temp->prev->integer)
		case_two_one_three(data);
	else if (temp->integer < temp->next->integer && temp->integer < \
			temp->prev->integer && temp->next->integer > temp->prev->integer)
		case_one_three_two(data);
}

void	redirect(t_data *data)
{
	if (data->len_a > 5)
		get_divider(data);
	else if (data->len_a = 3)
		redirect_threes;
	else if (data->len_a = 4)
		case_four(data);
	else if (data->len_a = 5)
		case_five(data);
}
