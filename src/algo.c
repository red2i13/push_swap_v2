
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
int find_pos(t_list *stack, int rank)
{
    while (stack)
    {
        if(stack->rank == rank)
            return (stack->pos);
        stack = stack->next;
    }
    return(0);
}
void rot_max(t_list **stack_a, int pos)
{
    int len;
    int i;

    len = ft_lstsize(*stack_a);  
    i = pos * (pos <= len / 2) + (len - pos)*(pos > len /2);
    while (i)
    {
        if(pos <= len / 2)
            ra(stack_a, true);
        else
            rra(stack_a, true);
        i--;
    }
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
void find_min(t_list **stack_a, t_list **stack_b, int rank)
{
    t_list *tmp;

    tmp =*stack_a;
    while (tmp)
    {
        if(tmp->rank == rank)
        {
            rot_max(stack_a, tmp->pos);
            pb(stack_a, stack_b, true);
        }
        tmp = tmp->next;
    }
}
void ft_sort_five(t_list **stack_a, t_list **stack_b)
{
    find_min(stack_a, stack_b, 0);
    init_index(stack_a);
    find_min(stack_a, stack_b, 1);
    ft_sort_threee(stack_a);
    if(*(int*)(*stack_b)->content > *(int*)(*stack_b)->next->content)
        pa(stack_a, stack_b, true);
    else
    {
        rb(stack_b, true);
        pa(stack_a, stack_b, true);
    }
    pa(stack_a, stack_b, true);
}
void ft_sort_four(t_list **stack_a, t_list **stack_b)
{
    find_min(stack_a, stack_b, 0);
    ft_sort_threee(stack_a);
    pa(stack_a, stack_b, true);
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
        pa(stack_a, stack_b, true);
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
void algo(t_list **stack_a, t_list **stack_b, int len_a, int range)
{
    int min;

    min = 0;
    while (*stack_a)
    {
        if((*stack_a)->rank < min)
        {
            min++;
            pb(stack_a, stack_b, true);
            rb(stack_b, true);
        }
        else if((*stack_a)->rank <= range + min)
        {
            min++;
            pb(stack_a, stack_b, true);
        }
        else if(still_inrange(*stack_a, range + min) <= len_a / 2)
            ra(stack_a, true);
        else
            rra(stack_a, true);
    }
    final_sort(stack_a, stack_b, len_a - 1);
}
int algo_start(t_list **stack_a, t_list **stack_b, int *arr)
{
    int len_a;
    int range;

    len_a = ft_lstsize(*stack_a);
    range = ft_sqrt(len_a) * 3 / 2;
    selection_sort(arr, len_a);
    init_idx_rank(stack_a, arr, len_a);
    if(len_a == 5)
        return(ft_sort_five(stack_a, stack_b),0);
    else if(len_a == 4)
        return(ft_sort_four(stack_a, stack_b), 0);
    else if(len_a == 3)
        return(ft_sort_threee(stack_a),0);
    else if (len_a == 2)
    {
        if(*(int*)(*stack_a)->content > *(int*)(*stack_a)->next->content)
            sa(stack_a, true);
        return(0);
    }
    algo(stack_a, stack_b, len_a, range);
    return(0);
}
   