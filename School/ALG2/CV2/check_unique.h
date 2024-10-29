#pragma once

#include <vector>
#include <string>

class Unique_checker {
private:
    std::vector<int> numbers;         // Vector to store the numbers_x.txt
    std::vector<int> numbers_sorted;  // Sorted version of numbers

public:
    // Constructor: Reads words from a file and initializes numbers and numbers_sorted
    Unique_checker(const std::string& file_path);

    // Method to check if the numbers in vector numbers are unique
    bool check_numbers_unsorted();

    // Method to check if the numbers in vector numbers_sorted are unique
    bool check_numbers_sorted();

    // Method to test both unsorted and sorted methods and measure time
    void test_both();
};


