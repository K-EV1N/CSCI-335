#include <iostream>
#include <vector>
//#include "myVector.hpp"
//#include "myList.hpp"
//#include "myHeap.hpp"
#include "myAVLtree.hpp"
#include <fstream>
#include <sstream>


int main() {
    std::string holder;
    std::string getter; // holds the first value on the line
    std::string getter2; // holds the second value on the line
    std::ifstream file("values.txt");
    std::vector<int> vectorInfo;

    while (getline(file, holder)) { //iterating through holder
        std::stringstream convert(holder);
        std::getline(convert, getter, ' '); // grabs the first word and stores it in "getter"
        std::getline(convert, getter2, ' '); // grabs the second word and stores it in "getter2"
        
        if(getter == "insert") {
            int value = std::stoi(getter2); // converts the string to an integer and stores it in a int variable
            vectorInfo.push_back(value); // pushes back the value into the empty vector
        } else {
                vectorInfo.push_back(-1); // else if if it's "pop", you push back "-1" into the vector
            }
    }

    // std::cout << "START \n\n";
    // for (int i = 0; i < vectorInfo.size(); i++) {
    //     std::cout << vectorInfo[i] << " ";
    // }


    //vectorMedian(&vectorInfo);

    //listMedian(&vectorInfo);
    
    //heapMedian(&vectorInfo);

    treeMedian(&vectorInfo);
    
    return 0;
}