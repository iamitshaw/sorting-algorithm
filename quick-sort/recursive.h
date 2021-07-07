
/* Include Guard */

#ifndef _RECURSIVE_QUICK_SORT_H
#define _RECURSIVE_QUICK_SORT_H

#include <bits/stdc++.h>

/* random pivot element */
template <typename T>
ssize_t partition(T* array, ssize_t left, ssize_t right) {

    /* initialize the seed value for the random engine generator */
    static auto seed {std::chrono::system_clock::now().time_since_epoch().count()};

    /* seed the random engine with the seed value */
    std::default_random_engine defaultRandomEngine(seed);

    std::uniform_int_distribution<size_t> distinct_number(left, right);
    size_t index{distinct_number(defaultRandomEngine)};

    /* place the randomly selected element at end of the current list */
    std::swap(array[index], array[right]);

    /* initialize i to store the count of elements less
     * than the element array[right] in the sub-array */
    ssize_t i{left - 1};
    for (auto j{left};j < right;j++) {
        if (array[j] < array[right]) {
            i += 1;
            std::swap(array[i], array[j]);
        }
    }
    std::swap(array[i+1], array[right]);
    return (i + 1);
}

/* recursive quick sort algorithm */
template <typename T>
void quick_sort(T* array, ssize_t right_index, ssize_t left_index=0) {
    if (left_index < right_index) {
        /* get a pivot index value */
        ssize_t pivot{partition(array, left_index, right_index)};

        /* decompose the array around pivot index value */
        quick_sort(array, pivot - 1, left_index);
        quick_sort(array, right_index, pivot + 1);
    }
}

#endif