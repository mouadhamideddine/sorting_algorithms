#include "sort.h"
#include <stdio.h>

/**
 * swap_elements - swap
 * @array: arr
 * @index1: int
 * @index2: int
 * Return: None
*/
void swap_elements(int *array, size_t index1, size_t index2)
{
	int temp;

	temp = array[index1];
	array[index1] = array[index2];
	array[index2] = temp;
}
/**
 * find_minimum - find_minimum num in array
 * @array: arr
 * @size: size_t
 * @index: size_t
 * Return: None
*/
void find_minimum(int *array, size_t size, size_t index)
{
	size_t i;
	int start;
	size_t small_so_far_index;
	int small_sofar;
	int token = 0;

	start = array[index];
	small_sofar = start;
	for (i = index; i < size; i++)
	{
		if (start > array[i])
		{
			if (array[i] < small_sofar)
			{
				token = 1;
				small_sofar = array[i];
				small_so_far_index = i;
			}
		}
	}
	if (token != 0)
	{
		swap_elements(array, index, small_so_far_index);
		print_array(array, size);
	}
}
/**
 * selection_sort - selection_sort
 * @array: arr
 * @size: size_t
 * Return: None
*/
void selection_sort(int *array, size_t size)
{
	size_t index;

	for (index = 0; index < size; index++)
	{
		find_minimum(array, size, index);
	}
}
