#include "check_unique.h"
#include <iostream>
#include <string>

int main() {
    const std::string file_path_1 = "numbers_1.txt";
    const std::string file_path_2 = "numbers_2.txt";
    const std::string file_path_3 = "numbers_3.txt";

    Unique_checker myChecker1(file_path_1);
    Unique_checker myChecker2(file_path_2);
    Unique_checker myChecker3(file_path_3);

    std::cout << "Testing first file: " << std::endl;
    myChecker1.test_both();
    std::cout << "Testing second file: " << std::endl;
    myChecker2.test_both();
    std::cout << "Testing third file" << std::endl;
    myChecker3.test_both();

    return 0;
}

