#include "quickSelect1dino.hpp"

void quickSelect1(const std::string &header, std::vector<int> data) {
    int n = data.size();
    int median = quickSelect(data, 0, n - 1, n / 2 + 1); //puts the median in the middle
    int P25 = quickSelect(data, 0, n - 1, n / 4); //25th 
    int P75 = quickSelect(data, 0, n - 1, (3 * n) / 4); //75th

    int min = data[0]; 
    for (int i = 0; i < n / 4; i++) { 
        if (data[i] < min) {
            min = data[i];
        }   
    }

    int max = 0;
    for (int i = (3 * n) / 4; i < n; i++) {
        if (data[i] > max) {
            max = data[i]; 
        }
    }

       // Output the calculated values
    std::cout << header << std::endl;
    std::cout << "Min: " << min << std::endl;
    std::cout << "P25: " << P25 << std::endl;
    std::cout << "P50: " << median << std::endl;
    std::cout << "P75: " << P75 << std::endl;
    std::cout << "Max: " << max << std::endl;
}

void insertionSort(std::vector<int>& data, int k) {
    int i, j, key;
    for (int i = 1; i < k; i++) {
        key = data[i];
        j = i - 1;
    }

    while(j > 0 && data[j] > key) {
        data[j + 1] = data[j];
        j--;
    }
    data[j + 1] = key;
}
int median3(std::vector<int>& data, int left, int right) {
    int pivot = data[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (data[j] <= pivot) {
            i++;
            std::swap(data[i], data[j]);
        }
    }
    std::swap(data[i + 1], data[right]);
    return i + 1;
}

int quickSelect(std::vector<int>& data, int left, int right, int k) {
    if (right - left + 1 <= 20) {
        insertionSort(data, right - left + 1);
        return data[left + k - 1];
    }
        
    while(left < right) {
        int index_of_pivot = median3(data, left, right);
        int left_elements_of_pivot = index_of_pivot - left + 1;

        if(k == left_elements_of_pivot) {
            return data[index_of_pivot];
        } else if(k < left_elements_of_pivot) {
            right = index_of_pivot - 1;
        } else {
            left = index_of_pivot + 1;
            k -= left_elements_of_pivot;
        }
    }
    return data[left];
}

