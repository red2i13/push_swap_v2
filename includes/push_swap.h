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
void ss(t_list **stack_a, t_list**stack_b, bool flag);
void ra(t_list **stack_a, bool flag);
void rra(t_list **stack_a, bool flag);
void rb(t_list **stack_b, bool flag);
void rrb(t_list **stack_b, bool flag);
void rr(t_list **stack_a, t_list **stack_b, bool flag);
void rrr(t_list **stack_a, t_list **stack_b, bool flag);
void pa(t_list **stack_a, t_list **stack_b, bool flag); 
void pb(t_list **stack_a, t_list **stack_b, bool flag);
//algo
int algo_start(t_list **stack_a, t_list **stack_b, int *arr);
int ft_read(char **av, t_list **stack_a, int ac);
void ft_free_list(t_list *lst);
void ft_free_arr(char **arr);
long	f_atoi(const char *nptr);
int is_sorted(t_list *stack);


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
