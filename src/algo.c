
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
void init_idx_rank(t_list **stack, int *arr, int size)
{
    int i;
    t_list *tmp;

    i= 0;
    tmp = *stack;
    while (tmp)
    {
        tmp->pos = i;
        tmp->rank = find_num(*(int *)tmp->content, arr, size);
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

t_list *find_max(t_list **stack_b)
{
    t_list *tmp;
    t_list *max;

    tmp = *stack_b;
    max = *stack_b;
    while (tmp)
    {
        if (*(int *)tmp->content > *(int *)max->content)
             max = tmp;
        tmp = tmp->next;
    }
    return max;
}
void final_sort(t_list **stack_a, t_list **stack_b, int max_i)
{
    t_list *max;
    int len_b = max_i + 1;

    while (*stack_b)
    {
        max = find_max(stack_b);
        init_index(stack_b);
        while (*stack_b != max)
        {
            if(max->pos > len_b / 2)
                rrb(stack_b, true);
            else
                rb(stack_b, true);
        }
        pa(stack_a, stack_b);
        len_b--;
    }
}

int still_inrange(t_list *stack, int range)
{
    int i;
    
    i = 0;
    while (stack)
    {
        if(stack->rank < range)
            return(i);
        stack = stack->next;
        i++;
    }
    return(i);
}
int algo_start(t_list **stack_a, t_list **stack_b, int *arr)
{
    int len_a;
    int min;
    int range;

    (void)stack_a;
    (void)stack_b;
    len_a = ft_lstsize(*stack_a);
    range = ft_sqrt(len_a) * 3 / 2;
    selection_sort(arr, len_a);
    init_idx_rank(stack_a, arr, len_a);
    min = 0;
    while (*stack_a)
    {
        if((*stack_a)->rank <= min)
        {
            min++;
            pb(stack_a, stack_b);
            rb(stack_b, true);
        }
        else if((*stack_a)->rank <= range + min)
        {
            min++;
            pb(stack_a, stack_b);
        }
        else if(still_inrange(*stack_a, range + min) <= len_a / 2)
            ra(stack_a, true);
        else
            rra(stack_a, true);
    }
    final_sort(stack_a, stack_b, len_a - 1);
    return(0);
}
   

