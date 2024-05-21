/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenmakh <rbenmakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:19:35 by rbenmakh          #+#    #+#             */
/*   Updated: 2024/05/21 15:19:39 by rbenmakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include "../printf/ft_printf.h"
# include "get_next_line.h"
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

// moves
void		sa(t_list **stack_a, bool flag);
void		sb(t_list **stack_b, bool flag);
void		ss(t_list **stack_a, t_list **stack_b, bool flag);
void		ra(t_list **stack_a, bool flag);
void		rra(t_list **stack_a, bool flag);
void		rb(t_list **stack_b, bool flag);
void		rrb(t_list **stack_b, bool flag);
void		rr(t_list **stack_a, t_list **stack_b, bool flag);
void		rrr(t_list **stack_a, t_list **stack_b, bool flag);
void		pa(t_list **stack_a, t_list **stack_b, bool flag);
void		pb(t_list **stack_a, t_list **stack_b, bool flag);
// algo
int			algo_start(t_list **stack_a, t_list **stack_b, int *arr);
int			ft_read(char **av, t_list **stack_a, int ac);
void		ft_free_list(t_list *lst);
void		ft_free_arr(char **arr);
long		f_atoi(const char *nptr);
int			is_sorted(t_list *stack);
int			is_duplicated(t_list *tmp);
int			selection_sort(int *num, int size);
int			ft_read(char **av, t_list **stack_a, int ac);
int			ft_cal(int num, int index);
int			ft_sqrt(int num);
int			find_num(int num, int *arr, int size);
long		f_atoi(const char *nptr);
int			is_sorted(t_list *stack);
void		init_index(t_list **stack);
void		init_idx_rank(t_list **stack, int *arr, int size);
int			min_max(t_list *stack, int flag);
void		find_min(t_list **stack_a, t_list **stack_b, int rank);
t_list		*find_max(t_list **stack_b);
void		rot_max(t_list **stack_a, int pos);
void		final_sort(t_list **stack_a, t_list **stack_b, int max_i);
int			still_inrange(t_list *stack, int range);
int			enqeue(char *n_parse, t_list **stack_a);
typedef struct t_target
{
	int		num;
	t_list	*ptr;
	int		count;
}			t_target;

// algo function
int			ft_sqrt(int num);
int			find_num(int num, int *arr, int size);

// debug fucntions
void		print_list(t_list *lst, char *msg);

//
#endif
