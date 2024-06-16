#include "myHeap.hpp"

void heapMedian(const std::vector<int>* instructions) {
    const auto t1_start = std::chrono::steady_clock::now();

    std::priority_queue<int> maxHeap; // creates a max heap, maxHeap will hold the median
    std::priority_queue<int, std::vector<int>, std::greater<int> > minHeap; // creates a min heap
    std::vector<int> myMedian; // create a new vector to hold the median values

    for(auto it = instructions->begin(); it != instructions->end(); it++) { // loops through the instructions vector
        if(*it == -1) { // if the value is '-1'..
            if(!maxHeap.empty() || !minHeap.empty()) { // checks to see if either the maxHeap or minHeap is not empty
                myMedian.push_back(maxHeap.top()); // pushes the top element of the maxHeap into 'myMedian' vector
                maxHeap.pop(); // removes the top element of the maxHeap

                if(maxHeap.size() > minHeap.size() + 1) { // checks to see if maxHeap size is greater than minHeap's size + 1
                minHeap.push(maxHeap.top()); // pushes the maxHeap's top element into the minHeap
                maxHeap.pop(); // removes the root element of the maxHeap
                } else if (minHeap.size() > maxHeap.size()) { // if minHeap's size is greater than maxHeap's size
                    maxHeap.push(minHeap.top()); // pushes the minHeap's top element into the maxHeap
                    minHeap.pop(); // removes the root of the minHeap
            }
        } 

        } else {
            if(minHeap.empty() || *it <= maxHeap.top()) { // if the minHeap or if the current value of 'it' is less than or equal to the maxHeap's root
                maxHeap.push(*it); // pushes the current value of 'it' into the maxHeap
            } else {
                minHeap.push(*it); // else push the current value of 'it' into the minHeap
            }

            // Balance the heap
            if(maxHeap.size() > minHeap.size() + 1) { // checks to see if the maxHeap's size is greater than minHeap's size + 1
                minHeap.push(maxHeap.top()); // pushes the maxHeap's root value into minHeap
                maxHeap.pop(); // removes the root value
            } else if (minHeap.size() > maxHeap.size()) { // checks to see if the minHeap's size is greater than the maxHeap's size
                maxHeap.push(minHeap.top()); // pushes the minHeap's root into the maxHeap
                minHeap.pop(); // removes the root value
            }
        }
    }

    const auto t1_end = std::chrono::steady_clock::now(); // calculates the time complexity
    int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();

    //std::cout << "Time to insert and pop medians for heaps: " << t1 << " microseconds" << std::endl;

    for(int i = 0; i < myMedian.size(); i++) {
        std::cout << myMedian[i] << " ";
    }
}