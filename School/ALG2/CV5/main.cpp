#include <iostream>
#include "Heap.h"

using namespace std;

int main()
{
    string input;
    
    getline(cin, input);

    vector<int> input = {1,-3,2};

    Heap heap(input);

    heap.print_heap();
    heap.print_sorted();
    heap.remove_root();
    heap.print_heap();
    heap.insert_element(72);
    heap.insert_element(0);
    heap.insert_element(-42);
    heap.print_heap();
    heap.remove_root();
    heap.print_heap();

    return 0;
}
