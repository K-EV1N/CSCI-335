#include <cmath>
#include <chrono>
#include "QuickSelect1.hpp"

void quickSelect1(const std::string & header, std::vector<int> data) {
    const auto t1_start = std::chrono::steady_clock::now();

    int size = data.size(); // finds the size of the vector

    int median = quickSelect(data, 0, size - 1, size / 2 + 1); // calculates the median

    int percentile25 = quickSelect(data, 0, size - 1, size / 4); // calculates the 25th percentile

    int percentile75 = quickSelect(data, 0, size - 1, (3 * size) / 4); // calculates the 75th percentile

    int minimum = data[0]; // sets the first value of the array as the minimum
    for(int i = 0; i < size / 4; i++) { // loops through the 25th percentile array
        if(data[i] < minimum) { // if the element value is less than the first index value..
            minimum = data[i]; // set that element value as the min
        }
    }
   
   int maximum = 0; // sets the max as 0
   for(int i = (3 * size) / 4; i < size; i++) { // loops through the 75th percentile array
        if(data[i] > maximum) { // if the element value is greater than 0...
            maximum = data[i]; // set that element value as the max
        }
   } 

    std::cout << header << std::endl; // prints the header
    std::cout << "Min: " << minimum << std::endl; // prints the minimum value
    std::cout << "P25: " << percentile25 << std::endl; // prints the 25th percentile
    std::cout << "P50: " << median << std::endl; // prints the median
    std::cout << "P75: " << percentile75 << std::endl; // prints the 75th percentile
    std::cout << "Max: " << maximum << std::endl; // prints the maximum value
    const auto t1_end = std::chrono::steady_clock::now(); // calculates the time complexity
    int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();

    //std::cout << "Time to insert and pop medians for vector: " << t1 << " microseconds" << std::endl;
}

void insertionSort(std::vector<int>& nums, int k) {
    int i, j, key; // variables

    for(i = 1; i < k; i++) { // loops through the elements in the nums array
        key = nums[i]; // assigns the index of each element to key
        j = i - 1; // makes j the idex of the previous element
    }

    while (j > 0 && nums[j] > key) { 
        nums[j + 1] = nums[j]; // shifts the element at index j one index to the right
        j = j - 1; // decrements
    }
    nums[j + 1] = key; // inserts key into the correct sorted position of the array
}

int partition(std::vector<int>& nums, int left, int right) {
    int pivot = nums[right]; // sets the pivot to right
    int leftMostIndex = left - 1; // sets the left index to left most index

    for(int i = left; i < right; i++) { // loops from left to the right array, not including the right most index
        if(nums[i] <= pivot) { // if the element at index i is <= pivot...
            leftMostIndex++; // increments
            std::swap(nums[leftMostIndex], nums[i]); // swap the value in leftIndex with the value in nums[i]
        }
    }
    std::swap(nums[leftMostIndex + 1], nums[right]); // else swap the leftIndex + 1 index with the right most index
    return leftMostIndex + 1; // returns the index where the pivot has been placed
}


int quickSelect(std::vector<int>& nums, int left, int right, int k) {
    if(right - left + 1 <= 20) { // checks to see if size is <= 20
        insertionSort(nums, right - left + 1); // calls insertion sort
        return nums[left + k - 1]; // returns the kth element from the sorted array
    }

    while(left < right) { 
        int pivotIndex = partition(nums, left, right); // calls partition to get the position of the pivot
        int elements_left_of_pivot = pivotIndex - left + 1; // calculates the size of the left after partitioning

        if(k == elements_left_of_pivot) { // checks to see if k is the pivot element
            return nums[pivotIndex]; // returns the element at pivotIndex
        } else if (k < elements_left_of_pivot) { // checks to see if k is smaller than the size of the left partition
            right = pivotIndex - 1; // assigns 'right' as pivotIndex - 1
        } else {
            left = pivotIndex + 1; // assigns 'left' as pivotIndex + 1
            k -= elements_left_of_pivot; // decrements the value of k by the size of the left partition
        }
    }
    return nums[left]; // returns the kth smallest element
}
