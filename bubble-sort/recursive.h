
/* Include Guard */

#ifndef _RECURSIVE_BUBBLE_SORT_H_
#define _RECURSIVE_BUBBLE_SORT_H_

#include <bits/stdc++.h>

/* recursive bubble sort algorithm */
template <typename T>
void bubble_sort(T* array, ssize_t array_size) {

    /* is_swapped is an indicator which will
     * signifies that either swap has occurred */
    bool is_swapped{false};
    for (ssize_t j{0};j < array_size - 1;j++) {
        if (array[j] > array[j + 1]) {

            /* if elements of the array
             * aren't in ascending order */
            std::swap(array[j], array[j+1]);
            is_swapped = {true};
        }
    }

    /* if no swap operation has been performed in current
     * iteration then it signifies that array is sorted */
    if (is_swapped) {

        /* since, last element of subarray is at its actual
         * position.Hence, decrement the size of subarray */
        bubble_sort(array, array_size - 1);
    }
}

#endif