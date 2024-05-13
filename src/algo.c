
#include "../includes/push_swap.h"

void init_index(t_list **stack)
{
    int i;
    t_list *tmp;

    i= 0;
    tmp = *stack;
    while (tmp)
    {
        tmp->pos = i;
        tmp = tmp->next;
        i++;
    } 
}
int min_max(t_list *stack, int flag)
{
    int val;
    int tmp;

    val = *(int*)stack->content;
    stack = stack->next;
    while (stack)
    {
        tmp = *(int*)stack->content;
        if(flag == 0 && val > tmp)
            val = tmp;
        else if(flag == 1 && val < tmp)
            val = tmp;
        stack = stack->next;
    }
    return(val);
}

int is_sorted(t_list *stack)
{
    int num;
    int compare;

    while (stack->next)
    {
        num = *(int *)stack->content;
        compare = *(int*)stack->next->content;
        if(num > compare)
            return(1);
        stack = stack->next;
    }
    return(0);
}


void    ft_sort_threee(t_list **stack)
{
    int min = min_max(*stack, 0); 
    int max = min_max(*stack, 1); 
    while (is_sorted(*stack))
    {
        if(*(int*)(*stack)->next->content == max)
        {
            rra(stack, true);
            continue;
        }
        else if((*(int*)(*stack)->next->next->content == max && *(int*)(*stack)->next->content == min) || (*(int*)(*stack)->content == max && *(int*)(*stack)->next->next->content == min))
        {
            sa(stack, true);
            continue;
        }
        else if((*(int*)(*stack)->content == max && *(int*)(*stack)->next->content == min))
        {
            ra(stack, true);
            continue;
        }
     }
    init_index(stack);
}
int algo_start(t_list **stack_a, t_list **stack_b)
{
    // int len;
    // int min;
    // int max;

    (void)stack_a;
    (void)stack_b;
    return(0);
}
   

