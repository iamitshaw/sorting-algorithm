
/* Include Guard */
#ifndef _BINARY_HEAP_H_
#define _BINARY_HEAP_H_

#include "exception.h"

template<typename T>
class BinaryHeap {
private:
    T* heapArray;
    ssize_t countOfElement;
public:
    BinaryHeap();
    ssize_t left_child(ssize_t index) const ;
    ssize_t right_child(ssize_t index) const ;
    bool is_empty() const ;
    ssize_t heap_size() const ;
    void percolate_down(ssize_t index);
    T extract_max();
    void build_heap(T array[], ssize_t array_size);
    ~BinaryHeap();


};

/* default constructor */
template<typename T>
BinaryHeap<T>::BinaryHeap()
 :countOfElement{0} {
    BinaryHeap<T>::heapArray = nullptr;
}

/* get left child */
template<typename T>
ssize_t BinaryHeap<T>::left_child(ssize_t index) const{
    ssize_t left_child_index {2 * index + 1};
    if (left_child_index <= 0 or left_child_index >= BinaryHeap<T>::countOfElement) {
        /* -1 sentinel is used to indicate that their
         * is no left child of the provided node */
        return -1;
    } else {
        /* if left child exist for provided node */
        return left_child_index;
    }
}

/* get right child */
template<typename T>
ssize_t BinaryHeap<T>::right_child(ssize_t index) const{
    ssize_t right_child_index {2*(index + 1)};
    if (right_child_index <= 0 or right_child_index >= BinaryHeap<T>::countOfElement) {
        /* -1 sentinel is used to indicate that their
         * is no right child of the provided node */
        return -1;
    } else {
        /* if right child exist for provided node */
        return right_child_index;
    }
}

/* whether or not heap container is empty */
template<typename T>
bool BinaryHeap<T>::is_empty() const{
    return BinaryHeap<T>::countOfElement == 0;
}

/* compute the size of the heap container */
template<typename T>
ssize_t BinaryHeap<T>::heap_size() const {
    return BinaryHeap<T>::countOfElement;
}

template <typename T>
void BinaryHeap<T>::percolate_down(ssize_t index) {
    /* get the left_child and right_child index
     * of the node present at location index */
    ssize_t left_index{left_child(index)};
    ssize_t right_index{right_child(index)};

    /* declare a pointer to indicate maximum index
     * among node, left child and right child */
    ssize_t max_index{index};

    /* compute the max element among node, left child and right child */
    if (left_index != -1 && this->heapArray[left_index] > this->heapArray[max_index]) {
        /* if left child exist and it's value
         * is greater than its parent node */
        max_index = left_index;
    }
    if (right_index != -1 && this->heapArray[right_index] > this->heapArray[max_index]) {
        /* if right child exist and it's value is
         * greater than max(left_child, parent_node) */
        max_index = right_index;
    }

    /* establish the heap property at current node if max_index
     * and index are pointing to two different node elements */
    if (max_index != index) {
        std::swap(BinaryHeap<T>::heapArray[max_index], BinaryHeap<T>::heapArray[index]);
        percolate_down(max_index);
    }
}

template <typename T>
T BinaryHeap<T>::extract_max() {
    if (this->is_empty()) {
        char error_message[] {"index out_of_range exception!"};
        throw Exception{error_message};
    } else {
        /* store the data that is about to be deleted */
        T deleted_data{BinaryHeap<T>::heapArray[0]};
        std::swap(this->heapArray[0], this->heapArray[this->countOfElement - 1]);

        /* decrease the size of the heap */
        BinaryHeap<T>::countOfElement--;

        /* percolate_down the element at location 0 */
        percolate_down(0);
        return deleted_data;
    }
}

/* build heap */
template <typename T>
void BinaryHeap<T>::build_heap(T* array, ssize_t array_size) {

    /* heap container is holding the provided array */
    BinaryHeap<T>::heapArray = array;

    /* append the array elements in the heap */
    for (size_t i{0};i < array_size;i++) {
        BinaryHeap<T>::heapArray[i] = array[i];
    }

    /* update the heap size */
    BinaryHeap<T>::countOfElement = array_size;

    /* initialize index with first non-leaf node */
    for (ssize_t index{(BinaryHeap<T>::countOfElement - 1) / 2}; index >= 0; index--) {
        percolate_down(index);
    }

}

/* destructor */
template <typename T>
BinaryHeap<T>::~BinaryHeap() {
    BinaryHeap<T>::heapArray = nullptr;
}

#endif