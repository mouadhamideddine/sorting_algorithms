#include <stdio.h>
#include <stdlib.h>
void print_array(const int *array, size_t size)
{
    size_t i;
    int look[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}
int quick_swap(int *array, size_t i, size_t j, size_t size)
{
    int temp;

    if(array[i] == array[j])
    {
        return -1; /*already same number no need  to mingle*/
    }
    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    print_array(array, size);
    return (0);
}
int pass_array(int *array, size_t pivot_index, size_t size)
{
    int already_sorted = -1;
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
    return already_sorted;
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
    int already_sorted;
    size_t while_counter = 0;

    pivot_index = size - 1;
    while(pivot_index > 0)
    {
        already_sorted = pass_array(array, pivot_index, size);
        if (while_counter % 6 == 0)
        {
            pivot_index--;
        }
        while_counter++;
    }
    printf("while_counter = %ld", while_counter);
}
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {68, 12, 45, 89, 33, 76, 2, 55, 91, 10, 87, 23, 99, 59, 43, 81, 6, 37, 94, 17};
    size_t n = sizeof(array) / sizeof(array[0]);
    quick_sort(array, n);
    return (0);
}