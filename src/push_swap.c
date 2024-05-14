#include "../includes/push_swap.h"


long	f_atoi(const char *nptr)
{
	int	i;
	long	result;
	int	sign;

	sign = 1;
	i = 0;
	result = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
        if(!nptr[i])
            return(LONG_MAX - 1);
	}
    if((nptr[i] && !ft_isdigit(nptr[i])) || !nptr[i])
            return(LONG_MAX - 1);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - '0';
		i++;
        if((nptr[i] && !ft_isdigit(nptr[i])) || result * sign > INT_MAX || result * sign < INT_MIN)
            return(LONG_MAX - 1);
	}
	return (result * sign);
}
void print_list(t_list *lst, char *msg)
{
    printf("---------%s-----------\n", msg);
    while (lst)
    {
        ft_printf("node content %i\n", (*(int*)lst->content));
        lst = lst->next;
    }
}
void ft_free_arr(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}
void ft_free_list(t_list *lst)
{
    t_list *tmp;
    while (lst)
    {
        free(lst->content);
        tmp = lst;
        lst = lst->next;
        free(tmp);
    }    
}
int ft_read(char **av, t_list **stack_a, int ac, int st_arr[500])
{
    char **arr;
    int i;
    int j;
    long num;
    int *num_ptr;

    i= 1;
    while (i < ac)
    {
        arr= ft_split(av[i], ' ');
        if(!arr || !arr[0])
            return (ft_free_arr(arr),1);
        j = 0;
        while(arr[j])
        {
            num = f_atoi(arr[j]);
            st_arr[i+j-1] = num;
            num_ptr = malloc(sizeof(int));
            if (num_ptr == NULL || num == LONG_MAX - 1)
            {
                ft_free_arr(arr);
                return (free(num_ptr),1);
            }
            *num_ptr = num; 
            ft_lstadd_back(&(*stack_a), ft_lstnew(num_ptr));
            j++;
        }
        ft_free_arr(arr);
        i++;
    }
    return(0);
}
int main(int ac, char **av)
{
    t_list *stack_a;
    t_list *stack_b;
    static int arr[500];

    (void)av;
    stack_a = NULL;
    stack_b = NULL;
    if(ac < 2)
        return(1);
    if(ft_read(av, &stack_a, ac, arr))
    {
        ft_free_list(stack_a);
        return(write(2, "Error\n", 6), 1);
    }
    //

    t_list *tmp = stack_a;
    t_list *tmp1 = stack_a;
    while (tmp)
    {
        tmp1 = tmp->next;
        while (tmp1)
        {
            if((*(int*)tmp->content) == (*(int *)tmp1->content))
            {
                ft_free_list(stack_a);
                return(write(2, "Error\n", 6), 1);
            }
            tmp1 = tmp1->next;
        }
        tmp = tmp->next;
    }
    algo_start(&stack_a, &stack_b, arr);
    ft_free_list(stack_a);
    ft_free_list(stack_b);
}
