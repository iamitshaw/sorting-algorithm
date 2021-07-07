
/* Include Guard */

#ifndef _ITERATIVE_BUBBLE_SORT_H_
#define _ITERATIVE_BUBBLE_SORT_H_

#include <bits/stdc++.h>

/* iterative bubble sort algorithm */
template <typename T>
void bubble_sort(T* array, ssize_t array_size) {
    for (ssize_t i{0};i < array_size - 1;i++) {

        /* is_swapped is an indicator which will
         * signifies that either swap has occurred */
        bool is_swapped{false};
        for (ssize_t j{0};j < array_size - i - 1;j++) {
            if (array[j] > array[j + 1]) {

                /* if elements of the array
                 * aren't in ascending order */
                std::swap(array[j], array[j+1]);
                is_swapped = {true};
            }
        }

        /* if no swap operation has been performed in current
         * iteration then it signifies that array is sorted */
        if (!is_swapped) {
            break;
        }
    }
}

#endif