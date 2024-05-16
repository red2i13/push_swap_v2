#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include "../printf/ft_printf.h"
# include <unistd.h>
# include "get_next_line.h"
//check if we cant use header limit
#include <limits.h>
#include <stdbool.h>

//moves
void sa(t_list **stack_a, bool flag);
void sb(t_list **stack_b, bool flag);
void ss(t_list **stack_a, t_list**stack_b);
void ra(t_list **stack_a, bool flag);
void rra(t_list **stack_a, bool flag);
void rb(t_list **stack_b, bool flag);
void rrb(t_list **stack_b, bool flag);
void rr(t_list **stack_a, t_list **stack_b);
void rrr(t_list **stack_a, t_list **stack_b);
void pa(t_list **stack_a, t_list **stack_b);
void pb(t_list **stack_a, t_list **stack_b);
//algo
int algo_start(t_list **stack_a, t_list **stack_b, int *arr);

typedef struct t_target{
    int num;
    t_list *ptr;
    int count;
}t_target;

//algo function
int ft_sqrt(int num);
int find_num(int num, int *arr, int size);

//debug fucntions
void print_list(t_list *lst, char *msg);

//
#endif
