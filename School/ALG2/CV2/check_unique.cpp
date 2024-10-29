#include "check_unique.h"
#include <fstream>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <set>

// Constructor: Reads words from the file and initializes numbers and numbers_sorted
Unique_checker::Unique_checker(const std::string& file_path) {
    std::string number;
    std::ifstream myNumbers(file_path);

    while(std::getline(myNumbers, number))
    {
        if(stoi(number))
        {
            this->numbers.push_back(stoi(number));
        }
    }
    this->numbers_sorted = this->numbers;
    std::sort(this->numbers_sorted.begin(), this->numbers_sorted.end());
}

// Method to check if the numbers in vector numbers are unique
bool Unique_checker::check_numbers_unsorted() {
    std::set<int> uniqueNumbers(this->numbers.begin(), this->numbers.end());
    return (uniqueNumbers.size() == this->numbers.size());
}

// Method to check if the numbers in vector numbers_sorted are unique
bool Unique_checker::check_numbers_sorted() {
    int current_number = 1;
    for(int i = 1; i < this->numbers_sorted.size() - 1; i++)
    {
        if(this->numbers_sorted.at(current_number) != this->numbers_sorted.at(current_number - 1))
        {
            current_number += 1;
        }
        else 
        {
            return false;
        }
    }
    return true;
}

// Method to test both unique checker methods and measure their time
void Unique_checker::test_both() {
    auto start = std::chrono::high_resolution_clock::now();
    bool result = check_numbers_unsorted();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Time taken (unsorted): " << elapsed.count() << " seconds." << std::endl;
    if(result) {std::cout << "These numbers are unique! " << std::endl;}
    else {std::cout << "These numbers aren't unique! " << std::endl;}

    start = std::chrono::high_resolution_clock::now();
    bool result2 = check_numbers_sorted();
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "Time taken (sorted): " << elapsed.count() << " seconds." << std::endl;
    if(result2) {std::cout << "These numbers are unique! " << std::endl;}
    else {std::cout << "These numbers aren't unique! " << std::endl;}
}