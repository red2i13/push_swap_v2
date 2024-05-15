#include "../includes/push_swap.h"

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
    return(0);
    
}
int main()
{
    int arr[] = {1, 2, 3 ,4 ,5 ,6 ,7 ,8, 9};
    printf("number is found %i\n", find_num(5, arr, 9));
}