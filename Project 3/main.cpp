#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "StdSort.hpp"
//#include "QuickSelect1.hpp"
#include "QuickSelect2.hpp"
#include "CountingSort.hpp"
#include "quickSelect1dino.hpp"

int main() {
    std::string realnum; // holds the first value on the line
    std::string header;
    std::vector<int> numbers;

    std::string file = "inputs.txt";
    std::ifstream read(file);

    if (!read.is_open()) {
        std::cout << "Error!" << file << std::endl;
    }

    std::getline(read, header);
    std::cout << header << std::endl;

    while (read >> realnum) {
        std::istringstream temp2(realnum);
        int num;
        if (temp2 >> num) {
            numbers.push_back(num);
        }
    }

    // for(int i = 0; i < numbers.size(); i++) {
    //     std::cout << numbers[i] << " ";
    // }

    //stdSort("Male elephant seal weights", numbers);
    quickSelect1("Male elephant seal weights", numbers);
    //quickSelect2("Male elephant seal weights", numbers);
    //countingSort("Male elephant seal weights", numbers);
    
}