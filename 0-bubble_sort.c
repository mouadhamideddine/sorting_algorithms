#include "sort.h"
/**
 * bubble_sort - sorts an array of ints using bubble sort
 * @array: array
 * @size: size of the array
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{

	size_t i;
	size_t j;
	int temp;

	for (j = 0; j < size - 1; j++)
	{
		for (i = 0; i < size - 1 - j; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
