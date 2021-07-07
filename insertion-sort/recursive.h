
/* Include Guard */

#ifndef _RECURSIVE_INSERTION_SORT_H_
#define _RECURSIVE_INSERTION_SORT_H_

#include <bits/stdc++.h>

/* recursive insertion sort algorithm */
template <typename T>
void insertion_sort(T* array, ssize_t end_index, ssize_t start_index=1) {
    if (start_index < end_index) {
        T key_value{array[start_index]};
        ssize_t j{start_index - 1};

        /* move elements of sorted sequence (arr[0..i-1]) which are greater
         * than key_value to one position ahead of their current position */
        while (j >= 0 && array[j] >= key_value) {
            array[j+1] = array[j];
            j -= 1;
        }

        /* position key_value at its actual
         * position in the sorted array */
        array[j+1] = key_value;

        /* pick the next element from unsorted subarray */
        insertion_sort(array, end_index, start_index + 1);
    }
}

#endif
