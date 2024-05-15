#include "../includes/push_swap.h"


int ft_cal(int num, int index)
{
    if (index == 0)
        return(1);
    return(num * ft_cal(num, index-1));
}
int ft_sqrt(int num)
{
    int i;
    int tmp;
    // int j;

    i = 1;
    while (i < num / 2)
    {
        tmp = ft_cal(i, 2);
        printf("the num is %i\n", tmp);
        if(tmp > num)
            break;
        i++;
    }

    return(i - 1);
}
int find_num(int num, int *arr, int size)
{
    int min;
    int max;
    int mid;

    min = 0;
    max = size - 1;
    while (min <= max)
    {
        mid = min + (max - min)  / 2;
        if (arr[mid] == num)
            return(mid);
        else if (arr[mid] < num)
            min = mid + 1;
        else if(arr[mid] > num)
            max = mid - 1;
    }
    return(-1);
}