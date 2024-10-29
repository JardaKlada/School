#pragma once
#include <vector>

class Heap
{
private:
    std::vector<int> heap;
    std::vector<int> sorted;
    void build_max_heap();
    void heapify(int index);
    void heap_sort();

public:
    Heap(std::vector<int> input);
    
    void insert_element(int new_element);
    void remove_root();
    void print_heap();
    void print_sorted();
    
};
