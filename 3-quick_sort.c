#include "sort.h"
int quick_swap(int *array, size_t i, size_t j, size_t size)
{
    int temp;
    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    if (i != j)
    {
        print_array(array, size);
    }
    return (0);
}
int pass_array(int *array, size_t pivot_index, size_t size)
{
    size_t i = 0;
    size_t j = 0;

    for (j = 0; j < pivot_index; j++)
    {
        if (array[j] <= (array[pivot_index]))
        {
            quick_swap(array, i, j, size);
            i++;
        }
    }
    if(j == pivot_index)
    {
        quick_swap(array, i, j, size);/*swap pivot to i position*/
    }
    if (i == j)
    {
        return (-1);
    }
    return (0);
}
/**
 * quick_sort - quick sort algo
 * @array: int
 * @size: size_t
 * Return: VOID
*/
void quick_sort(int *array, size_t size)
{
    size_t pivot_index;
    int change_pivot;
    size_t while_counter = 0;

    pivot_index = size - 1;
    while(pivot_index > 0)
    {
        change_pivot = pass_array(array, pivot_index, size);
        if (change_pivot == -1)
        {
            pivot_index--;
        }
        while_counter++;
    }
}
