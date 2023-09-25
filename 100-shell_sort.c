#include "sort.h"

/**
 * Function name:
 * 	shell_sort 
 * Description:
 * 	Implementation of the shell_sort algorithm
 * 	wirh the Knuth interval sequence.
 * NTK:
 * 	@array: An array of integers.
 * 	@size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t interval, i, j;

	if (array == NULL || size < 2)
		return;

	for (interval = 1; interval < (size / 3);)
		interval = interval * 3 + 1;

	for (; interval >= 1; interval /= 3)
	{
		for (i = interval; i < size; i++)
		{
			j = i;
			while (j >= interval && array[j - interval] > array[j])
			{
				int temp = *(array + j);
				*(array + j) = *(array + (j - interval));
				*(array + (j - interval)) = temp;
				j -= interval;
			}
		}
		print_array(array, size);
	}
}
