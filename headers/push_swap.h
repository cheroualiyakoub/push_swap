/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:06:25 by ycheroua          #+#    #+#             */
/*   Updated: 2024/05/01 22:06:46 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <stdarg.h>

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

// check degit

int		ps_is_sign(char c);
int		ps_check_strdigit(int argc, char **argv);
int		ps_check_longint(long int numr);
int		ps_check_double_input(int *values, int count);
int		ps_check_digit(char c);

// free

void	ps_free_objects(int num_objects, ...);
void	ps_free_stacks(int num_objects, ...);
void	ps_free_str_split(char **str);

///  init stack

t_node	*ps_create_push_node(int value, t_stack *stack, int index);
void	ps_inti_mouveement(t_stack *stack_a, t_stack *stack_b);
void	ps_init_stacks(t_stack *s_a, t_stack *s_b, int *values, int count);

/// movement stack

void	ps_swap(t_stack *stack);
void	ps_push(t_stack *stack_src, t_stack *stack_des);
void	ps_pop(t_stack *stack);
void	ps_rotate(t_stack *stack);
void	ps_reverse_rotate(t_stack *stack);

/// sort stack

void	ps_sort_u_3(t_stack *stack);
void	ps_sort_u_5(t_stack *stack_a, t_stack *stack_b, int count);
void	ps_ksort_a_to_b(t_stack *stack_a, t_stack *stack_b, int count);
void	ps_ksort_b_to_a(t_stack *stack_b, t_stack *stack_a, int count);

///  sort utilis 

int		ps_get_max_index(t_stack *stack);
int		ps_check_sorted(t_stack *stack);
int		ps_count_mouvement_top(t_stack *stack, int index);
int		ps_top_is_cheapest(t_stack *stack, int index);
int		ps_calculte_range(int count);

///  utilis 

void	ps_print_mouv(char *mouv, char *stack);
int		ps_get_max_index(t_stack *stack);
void	ps_get_index(int *values, t_stack *stack_a, int count);
void	ps_sort_values_array(int *values, int count);
int		ps_promp_er_return(void);

/// main Functions

int		ps_valid_input(int argc, char **argv);
int		*ps_parse_input(int argc, char **argv, int count);
int		ps_sortstack(t_stack *stack_a, t_stack *stack_b, int count);
int		ps_get_min_index(t_stack *stack);

#endif
