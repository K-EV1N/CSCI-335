#include "CountingSort.hpp"
#include <chrono>

void countingSort (const std::string & header, std::vector<int> data) {
    const auto t1_start = std::chrono::steady_clock::now();

    std::unordered_map<int, int> hashMap; // creates a hash map that stores integers

    for(int i = 0; i < data.size(); i++) { // loops through the vector
        if(hashMap.count(data[i] == 0)) { // checks to see if each index exists in the hash map
            hashMap[data[i]] = 1; // sets the key to a value of 1 if it doesn't exist in the hash map
        } else {
            hashMap[data[i]] = hashMap[data[i]] + 1; // increments the index of the hash key by 1
        }
    }

    std::vector<std::pair<int, int> > valuesVector; // creates a vector to hold the pair of the number and how many times it repeats
    for(const auto& pair : hashMap) {
        valuesVector.push_back(pair); // pushes the pair into the vector we created
    }

    std::sort(valuesVector.begin(), valuesVector.end()); // sorts the pairs in ascending order

    int uniqueCounter = valuesVector.size(); // makes uniqueCounter the size of valuesVector

    // Sets the Maximum and Minimum
    int minimum, maximum; 
    minimum = valuesVector[0].first; // sets the first index of the vector as the minimum bc ascending order goes from smallest to largest
    maximum = valuesVector[valuesVector.size() - 1].first; // sets the maximum as the last number at the end of the vector

    int percentile25 = -1; // sets the -1 to show it's hasn't been assigned a valid integer
    int percentile50 = -1; // sets the -1 to show it's hasn't been assigned a valid integer
    int percentile75 = -1; // sets the -1 to show it's hasn't been assigned a valid integer
    int counter = 0; // initialize a counter for how many numbers you have encountered
    

    for(int i = 0; i < valuesVector.size(); i++) {
        counter += valuesVector[i].second;

        if(percentile25 == -1 && counter >= data.size() / 4) {
            percentile25 = valuesVector[i].first;
        }
        if(percentile50 == -1 && counter >= data.size() / 2) {
            percentile50 = valuesVector[i].first;
        }
        if(percentile75 == -1 && counter >= (3 * data.size()) / 4) {
            percentile75 = valuesVector[i].first;
            break;
        }
    }

    std::cout << header << std::endl; // prints the header
    std::cout << "Min: " << minimum << std::endl; // prints the minimum value
    std::cout << "P25: " << percentile25 << std::endl; // prints the 25th percentile
    std::cout << "P50: " << percentile50 << std::endl; // prints the median
    std::cout << "P75: " << percentile75 << std::endl; // prints the 75th percentile
    std::cout << "Max: " << maximum << std::endl; // prints the maximum value
    std::cout << "Unique: " << uniqueCounter << std::endl; // prints how many unique values
    const auto t1_end = std::chrono::steady_clock::now(); // calculates the time complexity
    int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();

    //std::cout << "Time to insert and pop medians for vector: " << t1 << " microseconds" << std::endl;
}
