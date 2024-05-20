#include "../includes/push_swap.h"

void app_opp(t_list **stack_a, t_list **stack_b, int num)
{
    if(num == 0)
        sa(stack_a, 0);
    else if(num == 1)
        sb(stack_b, 0);
    else if(num == 2)
        ss(stack_a, stack_b, 0);
    else if(num == 3)
        pa(stack_a, stack_b, 0);
    else if(num == 4)
        pb(stack_a, stack_b, 0);
    else if(num == 5)
        ra(stack_a, 0);
    else if(num == 6)
        rb(stack_b, 0);
    else if(num == 7)
        rr(stack_a, stack_b, 0);
    else if(num == 8)
        rra(stack_a, 0);
    else if(num == 9)
        rrb(stack_b, 0);
    else if(num == 10)
        rrr(stack_a, stack_b, 0);
}
int check_num(char *str)
{
    if (ft_strncmp(str, "sa\n", 4) == 0)
        return(0);
    else if (ft_strncmp(str, "sb\n", 4) == 0)
        return(1);
    else if (ft_strncmp(str, "ss\n", 4) == 0)
        return(2);
    else if (ft_strncmp(str, "pa\n", 4) == 0)
        return(3);
    else if (ft_strncmp(str, "pb\n", 4) == 0)
        return(4);
    else if (ft_strncmp(str, "ra\n", 4) == 0)
        return(5);
    else if (ft_strncmp(str, "rb\n", 4) == 0)
        return(6);
    else if (ft_strncmp(str, "rr\n", 4) == 0)
        return(7);
    else if (ft_strncmp(str, "rra\n", 5) == 0)
        return(8);
    else if (ft_strncmp(str, "rrb\n", 5) == 0)
        return(9);
    else if (ft_strncmp(str, "rrr\n", 5) == 0)
        return(10);
    else
        return(-1);
}
int checker(t_list **stack_a, t_list **stack_b)
{
    char *cmd;
    int len_b;
    int num;

    len_b = ft_lstsize(*stack_b);
    while (1)
    {
        cmd = get_next_line(1);
        if(!cmd)
            break;
        num = check_num(cmd); 
        if(num == -1)
        {
            free(cmd);
            return(write(2, "Error\n", 6), 1);
        }
        app_opp(stack_a, stack_b, num);
        free(cmd);
    }
    if(is_sorted(*stack_a) || *stack_b)
        return(write(1, "KO\n", 3), 1);
    ft_printf("OK\n");
    return(0);
}
int is_duplicated(t_list *tmp)
{
    t_list *tmp1;

    tmp1= tmp;
    while (tmp)
    {
        tmp1 = tmp->next;
        while (tmp1)
        {
            if((*(int*)tmp->content) == (*(int *)tmp1->content))
                return(1);
            tmp1 = tmp1->next;
        }
        tmp = tmp->next;
    }
    return(0);
}
int main(int ac, char **av)
{
    t_list *stack_a;
    t_list *stack_b;

    if(ac < 2)
        exit(0);
    stack_a = 0;
    stack_b = 0;
    if(ft_read(av, &stack_a, ac) || is_duplicated(stack_a))
    {
        ft_free_list(stack_a);
        return(write(2, "Error\n", 6), 1);
    }
    checker(&stack_a, &stack_b);
    ft_free_list(stack_a);
    ft_free_list(stack_b);
}