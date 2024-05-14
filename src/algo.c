
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
int selection_sort(int *num, int size)
{
    int i;
    int j;
    int tmp;

    i = 1;
    while(i < size)
    {
        j = i;
        while (j > 0 && num[j - 1] > num[j])
        {
            tmp = num[j];
            num[j] = num[j- 1];
            num[j-1] = tmp;
            j--;
        }
        i++;
        
    }
    return(0);
}
int algo_start(t_list **stack_a, t_list **stack_b, int *arr)
{
    int len_a;
    int len_b;
    // int min;
    // int max;
    int range;
    int i;

    (void)stack_a;
    (void)stack_b;
    len_a = ft_lstsize(*stack_a);
    len_b = ft_lstsize(*stack_b);
    range = 
    selection_sort(arr, len_a);
    i = 0;
    while (*stack_a)
    {
        if(arr[i] <= len_b)
            pb(stack_a, stack_b);
        else if(arr[i] <= range + len_b)
            pb(stack_a, stack_b);
        else if(in_range(stack_a, stack_b))
            //
        len_b = ft_lstsize(*stack_b);
    }
    return(0);
}
   

