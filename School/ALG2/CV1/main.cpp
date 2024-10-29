#include "compute_modus.h"
#include <iostream>
#include <string>

int main() {
    const std::string file_path = "words.txt";

    ModusCalculator modus(file_path);

    modus.test_both();


    return 0;
}

