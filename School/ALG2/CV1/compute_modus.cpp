#include "compute_modus.h"
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <chrono>
#include <iostream>

// Constructor: Reads words from the file and initializes words and words_sorted
ModusCalculator::ModusCalculator(const std::string& file_path) {
    std::string word;
    std::ifstream MyWords(file_path);

    while (std::getline(MyWords, word)) {
        if (!word.empty()) {  
            this->words.push_back(word);
        }
    }

    this->words_sorted = this->words;
    std::sort(this->words_sorted.begin(), this->words_sorted.end());
}

// Method to compute modus without sorting the vector
void ModusCalculator::compute_modus_unsorted() {
    std::unordered_map<std::string, int> modus_unsorted;

    for (int i = 0; i < this->words.size(); i++) {
        modus_unsorted[this->words[i]]++;
    }

    int max_count = 0;
    std::string modus;
    for (const auto& pair : modus_unsorted) {
        if (pair.second > max_count) {
            max_count = pair.second;
            modus = pair.first;
        }
    }
    std::cout << "Modus (unsorted): '";
    for(int i = 0; i < modus.size() - 1; i++)
    {
        std::cout << modus[i];
    }
    std::cout << "' with frequency: " << max_count << std::endl;
}

// Method to compute modus with sorted vector
void ModusCalculator::compute_modus_sorted() {
    int max_count = 1;
    int current_count = 1;
    std::string modus_word = this->words_sorted.at(0);

    for (int i = 1; i < this->words_sorted.size(); i++) {
        if (this->words_sorted.at(i) == this->words_sorted.at(i - 1)) {
            current_count++;  
        } else {
            if (current_count > max_count) {
                max_count = current_count;
                modus_word = this->words_sorted.at(i - 1); 
            }
            current_count = 1;  
        }
    }

    if (current_count > max_count) {
        max_count = current_count;
        modus_word = this->words_sorted.back();
    }

    std::cout << "Modus (sorted): '";

    for(int i = 0; i < modus_word.size() - 1; i++)
    {
        std::cout << modus_word[i];
    }
    std::cout << "' with frequency: " << max_count << std::endl;
}

// Method to test both mode computation methods and measure their time
void ModusCalculator::test_both() {
    auto start = std::chrono::high_resolution_clock::now();
    compute_modus_unsorted();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Time taken (unsorted): " << elapsed.count() << " seconds." << std::endl;

    start = std::chrono::high_resolution_clock::now();
    compute_modus_sorted();
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "Time taken (sorted): " << elapsed.count() << " seconds." << std::endl;
}
