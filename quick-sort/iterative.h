
/* Include Guard */

#ifndef _ITERATIVE_QUICK_SORT_H
#define _ITERATIVE_QUICK_SORT_H

#include "stack.h"

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

/* iterative quick sort algorithm */
template <typename T>
void quick_sort(T* array, ssize_t right_index, ssize_t left_index=0) {
   Stack<ssize_t> stack(right_index - left_index + 1);

    /* push initial values of
     * left and right to stack */
    stack.pushElement(left_index);
    stack.pushElement(right_index);


    /* loop until stack is empty */
    while (stack.getTop() >= 0) {
        /* pop right_index and left_index
         * respectively from the stack */
        right_index = stack.popElement();
        left_index = stack.popElement();

        /* get a pivot index value */
        ssize_t pivot = partition(array, left_index, right_index);

        /* if unprocessed elements exist on left side
         * of pivot then push left sub-array to stack
         * by specifying start_index and end_index */
        if (left_index < (pivot - 1)) {
            stack.pushElement(left_index);
            stack.pushElement(pivot - 1);
        }

        /* if unprocessed elements exist on right side
         * of pivot then push right sub-array to stack
         * by specifying start_index and end_index */
        if ((pivot + 1) < right_index) {
            stack.pushElement(pivot + 1);
            stack.pushElement(right_index);
        }
    }
}

#endif