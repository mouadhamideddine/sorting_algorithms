#include "sort.h"

/**
 * quick_swap - Swaps two elements in an array and prints the array if the
 *               elements were swapped.
 * @array: The array of integers.
 * @i: Index of the first element.
 * @j: Index of the second element.
 * @size: Size of the array.
 * Return: Always 0.
 */
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

/**
 * pass_array - Passes through an array
 * @array: The array of integers.
 * @pivot_index: Index of the pivot element.
 * @size: Size of the array.
 * Return: -1 if no swaps were made, 0 otherwise.
 */
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
	if (j == pivot_index)
	{
		quick_swap(array, i, j, size); /* Swap pivot to i position */
	}
	if (i == j)
	{
		return (-1);
	}
	return (0);
}

/**
 * sortArray - Sorts a small array of size 2 using bubble sort.
 * @arr: The array to be sorted.
 * Return: Void.
 */
void sortArray(int arr[])
{
	int temp;

	if (arr[0] > arr[1])
	{
		temp = arr[0];
		arr[0] = arr[1];
		arr[1] = temp;
		print_array(arr, 2);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using quicksort.
 * @array: The array of integers.
 * @size: Size of the array.
 * Return: Void.
 */
void quick_sort(int *array, size_t size)
{
	size_t pivot_index;
	int change_pivot;
	size_t while_counter = 0;

	pivot_index = size - 1;
	if (!array)
	{
		pivot_index = 0;
	}
	if (size == 2)
	{
		pivot_index = 0;
		sortArray(array);
	}
	if (size == 1)
	{
		pivot_index = 0;
	}
	while (pivot_index > 0)
	{
		change_pivot = pass_array(array, pivot_index, size);
		if (change_pivot == -1)
		{
			pivot_index--;
		}
		while_counter++;
	}
}
