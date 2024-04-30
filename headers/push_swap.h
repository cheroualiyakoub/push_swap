/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:06:25 by ycheroua          #+#    #+#             */
/*   Updated: 2024/04/30 23:42:21 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

# include "libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
	int				size;
	char			*name;
	char			*swap;
	char			*push;
	char			*rotate;
	char			*rotate_reverse;
}					t_stack;

/// Check validation of inputs
int		ps_promp_er_return();
int		ps_check_digit(char c);
int		ps_valid_input(int argc, char **argv);
int		*ps_parse_input(int argc, char **argv, int count);
int		ps_check_longint(long int numr);
void	ps_init_stacks(t_stack *stack_a, t_stack *stack_b, int *values, int count);
t_node	*ps_create_push_node(int value, t_stack *stack, int index);
int 	ps_check_double_input(int *values, int count);
void 	ps_sort_values_array(int *values, int count);
void 	ps_swap(t_stack *stack);
void	ps_pop(t_stack *stack);
void	ps_print_mouv(char *mouv, char *stack);
void	ps_get_index(int *values, t_stack *stack_a,int count);
void	ps_free_objects(int num_objects, ...);
void	ps_free_stacks(int num_objects, ...);
int 	ps_sortstack(t_stack *stack_a, t_stack *stack_b, int count);
int		ps_get_min_index(t_stack *stack);
void	ps_rotate(t_stack *stack);
void	ps_reverse_rotate(t_stack *stack);
void	ps_push(t_stack *stack_src, t_stack *stack_des);
int		main(int argc, char **argv);

/// parsing the inputs 

//// movements 

/// utilis

/// sorting the stacks

#endif