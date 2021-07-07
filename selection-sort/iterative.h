
/* Include Guard */

#ifndef _ITERATIVE_SELECTION_SORT_H_
#define _ITERATIVE_SELECTION_SORT_H_

#include <bits/stdc++.h>

/* find index position of minimum element */
template<typename T>
ssize_t minimum_element(T* array,ssize_t start_index,ssize_t end_index) {
    ssize_t minimum_index{start_index};
    for (ssize_t i{start_index + 1};i < end_index;i++) {

        /* if current element under consideration is smaller than
         * minimum obtained so far then update the minimum_index  */
        if(array[i] < array[minimum_index]){
            minimum_index = i;
        }
    }
    return minimum_index;
}

/* selection sort algorithm */
template <typename T>
void selection_sort(T* array, ssize_t array_size) {
    for (ssize_t i{0};i < array_size - 1;i++){

        /* find the index position of minimum
         * element from the unsorted array */
        ssize_t index{minimum_element(array, i, array_size)};

        /* swap the minimum element with first
         * element present in unsorted list */
        std::swap(array[i],array[index]);
    }
}

#endif
