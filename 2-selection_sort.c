#include "sort.h"

/**
 * Function name:
 * 	selection_sort
 * Description:
 * 	Implementation of the selection sort algorithm.
 * NTK:
 *	@array: An array of integers.
 * 	@size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			int tmp = *(array + i);
			*(array + i) = *min;
			*min = tmp;
			print_array(array, size);
		}
	}
}
