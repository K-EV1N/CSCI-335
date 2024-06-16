#include "myVector.hpp"

void vectorMedian (const std::vector<int>* instructions) {
    const auto t1_start = std::chrono::steady_clock::now();

    std::vector<int> data;
    std::vector<int> myMedian;

    for(auto it = instructions->begin(); it < instructions->end(); it++) { // loops through the vector
        if(*it == -1) {
            if(data.size() % 2 == 0) { // if the size is even
                auto median = (data.begin() + data.size() / 2 - 1); // find the lesser value between the two elements in the middle
                myMedian.push_back(*median); // pushes back the value into 'myMedian' vector
                data.erase(median); // deletes the calculated median from the 'data' vector
            }

            else if(data.size() % 2 != 0) { // if the size is odd
                auto median = (data.begin() + data.size() / 2); // calculates and gets the median
                myMedian.push_back(*median); // pushes back the value into 'myMedian' vector
                data.erase(median); // deletes the calculated median from the 'data' vector
            }
            
        } else {
            auto temporary = lower_bound(data.begin(), data.end(), *it); // finds the iterator pointing to the first element
            data.insert(temporary, *it); // inserts the value based on the iterator "temporary" into the 'data' vector
        }
    }
    
    const auto t1_end = std::chrono::steady_clock::now(); // calculates the time complexity
    int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();

    //std::cout << "Time to insert and pop medians for vector: " << t1 << " microseconds" << std::endl;

    for(int i = 0; i < myMedian.size(); i++) { // loops through the 'myMedian' vector and prints out all the medians
        std::cout << myMedian[i] << " ";
    }
}


