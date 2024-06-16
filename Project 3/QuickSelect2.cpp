#include "QuickSelect2.hpp"
#include <chrono>

int quickSelect2(const std::string & header, std::vector<int> data) {
    const auto t1_start = std::chrono::steady_clock::now();

    int size = data.size(); // sets the size to the size of the vector data

    std::vector<int> keys;

    int min = 0; // sets minimum value as the 0th index in the array
    int percentile25 = (size / 4) - 1; // calculates the index of the 25th percentile
    int percentile50 = (size / 2) - 1; // calculates the index of the 50th percentile (median_)
    int percentile75 = 3 * (size / 4) - 1; // calculates the index of the 75th percentile
    int max = data.size() - 1; // sets the maximum value as the last index of the array

    keys.push_back(min); // pushes the min value into keys
    keys.push_back(percentile25); // pushes the 25th percentile value into keys
    keys.push_back(percentile50); // pushes the median value into keys
    keys.push_back(percentile75); // pushes the 75th percentile value into keys
    keys.push_back(max); // pushes the max value into keys

    quickSelect(data, 0, size - 1, keys);

    std::cout << header << std::endl; // prints out the header
    std::cout << "Min: " << data[min] << std::endl; // prints out the minimum values
    std::cout << "P25: " << data[percentile25] << std::endl; // prints out the 25th percentile
    std::cout << "P50: " << data[percentile50] << std::endl; // prints out the median
    std::cout << "P75: " << data[percentile75] << std::endl; // prints out the 75th percentile
    std::cout << "Max: " << data[max] << std::endl; // prints out the maximum value

    const auto t1_end = std::chrono::steady_clock::now(); // calculates the time complexity
    int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();

    //std::cout << "Time to insert and pop medians for vector: " << t1 << " microseconds" << std::endl;
}

void insertionSort(std::vector<int>& nums, int left, int right) {
    int i, j, key; // variables

    for(i = left + 1; i <= right; i++) {
        key = nums[i]; // assigns the index of each element to key
        j = i - 1; // makes j the index of the previous element

        while (j >= left && nums[j] > key) { 
            nums[j + 1] = nums[j]; // shifts the element at index j one index to the right
            j--; // decrements
        }
        nums[j + 1] = key; // inserts key into the correct sorted position of the array
    }
}


void quickSelect(std::vector<int>& nums, int left, int right, std::vector<int>& keys) {
    if(right - left + 1 <= 20) { // checks to see if size is <= 20
        insertionSort(nums, left, right); // calls insertion sort
        return;
    }

    if(left < right) { 
        int pivotIndex = partition(nums, left, right); // calls partition to get the position of the pivot
        std::vector<int> leftKeys; //create a vector called leftKeys
        std::vector<int> rightKeys; // creates a vector called rightKeys

        for(int i = 0; i < keys.size(); i++) {
            int key = keys[i];
            if(key < pivotIndex) {
                leftKeys.push_back(key);
            } else if(key > pivotIndex) {
                rightKeys.push_back(key);
            }
        }

        if(!leftKeys.empty()) {
            quickSelect(nums, left, pivotIndex - 1, leftKeys);
        }
        if(!rightKeys.empty()) {
            quickSelect(nums, pivotIndex + 1, right, rightKeys);
        } 
    }
}

int partition(std::vector<int>& nums, int left, int right) {
    int pivot = nums[right]; // sets the pivot to right
    int i = left;

    for(int j = left; j < right; j++) { // loops from left to the right array, not including the right most index
        if(nums[j] <= pivot) { // if the element at index j is <= pivot...
            std::swap(nums[i], nums[j]); // swap the value in nums[i] with the value in nums[j]
            i++;
        }
    }
    std::swap(nums[i], nums[right]); // else swap the nums[i] index with the nums[right] most index
    return i; // returns the index where the pivot has been placed
}
