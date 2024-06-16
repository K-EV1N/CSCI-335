#include "myList.hpp"

void listMedian(const std::vector<int>* instructions) {
    const auto t1_start = std::chrono::steady_clock::now();

    std::list<int> data;
    std::vector<int> myMedian;

    for(auto it = instructions->begin(); it != instructions->end(); it++) { // loops through the instructions vector
        if(*it == -1) { // 
            if(data.size() % 2 == 0) { // if the size is even
                auto median = data.begin(); // initializes a iterator 'median' to the beginning of the data list
                std::advance(median, (data.size() / 2) - 1); // moves the iterator 'median' to point to the middle of the data
                myMedian.push_back(*median);
                //std::cout << *median << " ";
                data.erase(median); // removes the element pointed by the 'median' from the data list
            }
            else if (data.size() % 2 != 0) { // if the size is odd
                auto median = data.begin();
                std::advance(median, data.size() / 2); // the itertor 'median' will directly point to the middle element
                myMedian.push_back(*median);
                //std::cout << *median << " ";
                data.erase(median); // removes the element pointed by the 'median' from the data list
            }
        } else {
            auto insertPos = data.begin(); // initializes a iterator 'insertPos' to the beginning of the data
            while(insertPos != data.end() && *insertPos < *it) { // loops the iterator while trying to find a element that is greater than or equal to the current value
                insertPos++; // increments the iterator to the next element
            }
            data.insert(insertPos, *it); // inserts the current element '*it' into the data list at the position pointed by insertPos
        }
    }

    const auto t1_end = std::chrono::steady_clock::now(); // calculates the time complexity
    int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();

    //std::cout << "Time to insert and pop medians for list: " << t1 << " microseconds" << std::endl;


    for(int i = 0; i < myMedian.size(); i++) { // loops through 'myMedian' vector and prints out all the medians
        std::cout << myMedian[i] << " ";
    }
}