
/* Include Guard */

#ifndef _RECURSIVE_SELECTION_SORT_H_
#define _RECURSIVE_SELECTION_SORT_H_

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
void selection_sort(T* array, ssize_t end_index, ssize_t start_index=0) {
    if (start_index < end_index){

        /* find the index position of minimum
         * element from the unsorted array */
        ssize_t index{minimum_element(array, start_index, end_index)};

        /* swap the minimum element with first
         * element present in unsorted list */
        std::swap(array[start_index],array[index]);

        /* since position start_index has been filled with actual
         * element so that eliminate it from the unsorted array */
        selection_sort(array, end_index, start_index + 1);
    }
}


#endif
