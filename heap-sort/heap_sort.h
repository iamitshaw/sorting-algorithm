
/* Include Guard */

#ifndef _HEAP_SORT_H_
#define _HEAP_SORT_H_

#include "binary_heap.h"

template <typename T>
void heap_sort(T* array, ssize_t array_size) {
    BinaryHeap<T> binaryHeap;

    /* build binaryHeap from provided array elements */
    binaryHeap.build_heap(array, array_size);

    /* sorting procedure */
    for (int i = (binaryHeap.heap_size() - 1); i >= 0; i--) {
        array[i] = binaryHeap.extract_max();
    }
}

#endif