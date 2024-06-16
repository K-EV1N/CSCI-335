#include <iostream>
#include <vector>
#include <cmath>
#include "StdSort.hpp"
#include <chrono>

void stdSort(const std::string & header, std::vector<int> data) {
    const auto t1_start = std::chrono::steady_clock::now();

    std::cout << header << std::endl; // prints the header

    std::sort(data.begin(), data.end()); // sorts the whole data in ascending order

    // for(int i = 0; i < data.size(); i++) {
    //     std::cout << data[i] << " ";
    // }

    std::cout << std::endl;
    std::cout << std::endl;

    int index25 = (data.size() * 0.25) -1; // calculates the index for 25th percentile
    int index50 = data.size() * 0.50; // calculats the index for the median
    int index75 = (data.size() * 0.75) -1; // calculates the index for 75th percentile

    int percentile25 = data[index25]; // assigns the value at index25 from the data to percentile25
    int percentile50 = data[index50]; // assigns the value at index50 from the data to percentile50
    int percentile75 = data[index75]; // assigns the value at index75 from the data to percentile75

    std::cout << "Min: " << data.front() << std::endl;
    std::cout << "P25: " << percentile25 << std::endl;
    std::cout << "P50: " << percentile50 << std::endl;
    std::cout << "P75: " << percentile75 << std::endl;
    std::cout << "Max: " << data.back() << std::endl;

    const auto t1_end = std::chrono::steady_clock::now(); // calculates the time complexity
    int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();

    //std::cout << "Time to insert and pop medians for vector: " << t1 << " microseconds" << std::endl;
}