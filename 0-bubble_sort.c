#include "sort.h"

/**
 * Function name:
 * 	bubble_sort 
 * Description:
 * 	Implementation of the bubble sort algorithm.
 * NTK:
 * 	@array: Pointer to an integer array.
 * 	@size: size_t variable representing the size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	BOOL sorted = FALSE;
	int temp;
	size_t idx;

	if (array == NULL || size == 0 || size == 1)
		return;

	while (sorted == FALSE)
	{
		sorted = TRUE;
		for (idx = 0; idx < size - 1; idx++)
		{
			if (array[idx] > array[idx + 1])
			{
				temp = array[idx];
				array[idx] = array[idx + 1];
				array[idx + 1] = temp;
				print_array(array, size);
				sorted = FALSE;
			}
		}
	}
}
