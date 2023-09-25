#include "sort.h"

/**
 * Function name:
 * 	partition 
 * Description:
 * 	Sorts the subarray arround the pivot.
 * NTK:
 * 	@array: Pointer to an integer array.
 * 	@st: Starting index of the subarray.
 * 	@ed: Ending index of the subarray.
 * 	@size: size_t variable representing the size of an array.
 * Return: 
 * 	Middle_index
 */
size_t partition(int *array, size_t st, size_t ed, size_t size)
{
	int pivot, temp;
	size_t idx, sp_idx;

	idx = st;
	pivot = array[ed];
	for (sp_idx = st; sp_idx < ed; sp_idx++)
	{
		if (array[sp_idx] < pivot)
		{
			if (idx != sp_idx && array[idx] != array[sp_idx])
			{
				temp = array[idx];
				array[idx] = array[sp_idx];
				array[sp_idx] = temp;
				print_array(array, size);
			}
			idx++;
		}
	}
	if (idx != sp_idx && array[idx] != array[sp_idx])
	{
		temp = array[idx];
		array[idx] = array[sp_idx];
		array[sp_idx] = temp;
		print_array(array, size);
	}

	return (idx);
}

/**
 * Function name:
 * 	rec_arr_sort
 * Description:
 * 	Partitions the array and sorts the sub arrays
 * NTK:
 * 	@array: Pointer to an integer array.
 * 	@st: Starting index of the subarray.
 * 	@ed: Ending index of the subarray.
 * 	@size: size_t variable representing the size of an array.
 */
void rec_arr_sort(int *array, size_t st, size_t ed, size_t size)
{
	size_t p;

	if (st < ed)
	{
		p = partition(array, st, ed, size);
		if (p > 0)
			rec_arr_sort(array, st, p - 1, size);
		rec_arr_sort(array, p + 1, ed, size);
	}
}

/**
 * Functiona name:
 * 	quick_sort
 * Description:
 * 	Implementation of the quick_sort algorithm
 * NTK:
 * 	@array: Pointer to an integer array.
 * 	@size: size_t variable representing the size of an array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	rec_arr_sort(array, 0, size - 1, size);
}


