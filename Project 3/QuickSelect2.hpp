#include <iostream>
#include <vector>

int quickSelect2(const std::string & header, std::vector<int> data);
void insertionSort(std::vector<int>& nums, int left, int right);
int partition(std::vector<int>& nums, int left, int right);
void quickSelect(std::vector<int>& nums, int left, int right, std::vector<int>& keys);
