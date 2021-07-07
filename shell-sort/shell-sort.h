
/* Include Guard */

#ifndef _SHELL_SORT_H_
#define _SHELL_SORT_H_

#include <bits/stdc++.h>

/* shell sort algorithm */
template <typename T>
void shell_sort(T* array, ssize_t array_size) {

    /* start with a larger gap-interval then reduce gap-interval */
    for (ssize_t interval {(array_size / 2)}; interval >= 1; interval /= 2) {

        /* do a gap insertion sort of size stored in variable interval */
        for (ssize_t i {interval}; i < array_size; i++) {
            T current_element = *(array + i);
            ssize_t j;

            /* shift earlier gap-sorted elements up until the
             * correct location for current_element is found */
            for (j = i;j >= interval && *(array + j - interval) > current_element;j -= interval) {
                *(array + j) = *(array + j - interval);
            }

            /* put current_element at its correct
             * position in interval sorted array */
            *(array + j) = current_element;
        }
    }
}

#endif