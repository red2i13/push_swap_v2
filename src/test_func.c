#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	int				pos;
	int				rank;
}
					t_list;
int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	ptr = (t_list *)malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*(lst) = new;
}
int *int_arr(t_list *stack)
{
    int size;
    int *arr;
    int i;

    i = 0;
    size = ft_lstsize(stack);
    arr = (int *)malloc(sizeof(int) * size);
    while (stack)
    {
        arr[i] = *(int*)stack->content;
        stack = stack->next;
        i++;
    }
    return(arr);
}
int main()
{
    t_list *stack_a = NULL;
    for(int i = 0; i < 5;i++)
    {
        int *j = malloc(sizeof(int));
        *j = i;
        ft_lstadd_front(&stack_a, ft_lstnew(j));
    }
    int *arr = int_arr(stack_a);
    //debug
    int len = ft_lstsize(stack_a);
    for(int k = 0; k < len; k++)
    {
        printf("test arr %i\n", arr[k]);
    }
}

