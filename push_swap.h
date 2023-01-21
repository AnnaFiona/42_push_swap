/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ip <ip@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:37:31 by aplank            #+#    #+#             */
/*   Updated: 2023/01/21 17:31:36 by ip               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	long int		integer;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_data
{
	struct s_stack	*head_a;
	struct s_stack	*head_b;
	struct s_stack	*help_list;
	int				len_a;
	int				len_b;
	int				pos_b;
	int				help_len;
	int				divider;
	int				eighth;
}	t_data;

//algorithm_utils.c
void	get_position_b(t_data *data, int new_int);
void	finish_rotate_b(t_data *data);

//algorithm.c
void	algorithm(t_data *data);

//mixed_bubble_sort.c
void    mixed_bubble_sort(t_stack **head, int len, char c);

//atoi_with_int_check.c
void	check_int(t_data *data, char *nptr, long long int i);
int		atoi_with_int_check(t_data *data, char *nptr);

//cases_threes.c
void	case_three_two_one(t_data *data);
void    case_three_one_two(t_data *data);
void    case_two_three_one(t_data *data);
void    case_two_one_three(t_data *data);
void    case_one_three_two(t_data *data);

//checks_and_frees.c
void	check_input(t_data *data, char *input[]);
void	check_list(t_data *data, t_stack *head);
void	free_list(t_stack *head, int len);
void	exit_function(t_data *data);

//functions.c
void	swap_stack(t_stack *head, char c);
void	rotate_stack(t_stack **head, char c);
void	reverse_rotate_stack(t_stack **head, char c);
void	push_stack(t_data *data, t_stack **head_push, \
		t_stack **head_recieve, char r);

//get_divider_and_redirect.c
void	get_divider(t_data *data);
void	redirect(t_data *data);
void	redirect_threes(t_data *data);

//help_list.c
void	make_help_list(t_data *data, t_stack *head, int len);

//main.c
void	make_node(t_stack **head, int integer);
void	convert_input(t_data *data, char *input[]);
int		main(int argc, char *argv[]);

void print_list(t_stack *head, int len);

#endif