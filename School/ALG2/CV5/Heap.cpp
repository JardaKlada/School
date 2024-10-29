#include <iostream>
#include "Heap.h"

using namespace std;

Heap::Heap(vector<int> input)
{
    for(int i = 0; i < input.size(); i++)
    {   
        this->heap.push_back(input.at(i)); 
    }
    build_max_heap();
    heap_sort();
    
}

void Heap::build_max_heap()
{
    print_heap();
    int index = this->heap.size();
    for(int i = this->heap.size() - 1 ; i > -1; i--)
    {
        heapify(i);
    }
}

void Heap::heapify(int index)
{
    vector<int> heaped;
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if(left < this->heap.size() && this->heap.at(left) > this->heap.at(largest))
    {
        int temp = largest;
        largest = left;
        left = temp;
    }
    if(right < this->heap.size() && this->heap.at(right) > this->heap.at(largest))
    {
        int temp = largest;
        largest = right;
        right = temp;
    }
    if(this->heap.at(largest) != this->heap.at(index))
    {
        std::swap(this->heap[largest], this->heap[index]);
        heapify(largest);
    }

}
void Heap::heap_sort()
{
    vector<int> tempheap = this->heap;
    for(int i = tempheap.size() - 1; i >= 0; i--)
    {
        std::swap(tempheap[0], tempheap[i]);
        this->sorted.push_back(tempheap[i]);
        tempheap.pop_back();
        heapify(0);
    }
}
void Heap::insert_element(int new_element)
{
    this->heap.push_back(new_element);
    for(int i = this->heap.size() - 1; i > -1; i--)
    {
        heapify(i);
    }
}
void Heap::remove_root()
{
    this->heap.erase(this->heap.begin());
    for(int i = this->heap.size() - 1; i > -1; i--)
    {
        heapify(i);
    }
}
void Heap::print_heap()
{
    for(int i = 0; i < this->heap.size(); i++)
    {
        std::cout << this->heap.at(i) << " ";
    }
    std::cout << endl;
}
void Heap::print_sorted()
{
    for(int i = 0; i < this->sorted.size(); i++)
    {
        std::cout << this->sorted.at(i) << " ";
    }
    std::cout << endl;
}
