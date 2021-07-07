
/* Include Guard */

#ifndef _ITERATIVE_INSERTION_SORT_H_
#define _ITERATIVE_INSERTION_SORT_H_

#include <bits/stdc++.h>

/* insertion sort algorithm */
template <typename T>
void insertion_sort(T* array, ssize_t array_size) {
    for (ssize_t i{1};i < array_size;i++) {
        T key_value{array[i]};
        ssize_t j{i - 1};

        /* move elements of sorted sequence (arr[0..i-1]) which are greater
         * than key_value to one position ahead of their current position */
        while (j >= 0 && array[j] >= key_value) {
            array[j+1] = array[j];
            j -= 1;
        }

        /* position key_value at its actual
         * position in the sorted array */
        array[j+1] = key_value;
    }
}

#endif