#include "PmergeMe.hpp"
void MergeAndInsert(std::vector<int>& result, std::vector<int>& left, std::vector<int>& right) {
    result.clear();
    result.reserve(left.size() + right.size());  // Pre-allocate memory for the result vector

    Iterator leftIt = left.begin();
    Iterator rightIt = right.begin();

    while (leftIt != left.end() && rightIt != right.end()) {
        if (*leftIt < *rightIt) {
            result.push_back(*leftIt++);
        } else {
            result.push_back(*rightIt++);
        }
    }

    // Append the remaining elements from left and right (if any)
    result.insert(result.end(), leftIt, left.end());
    result.insert(result.end(), rightIt, right.end());
}

void MergeSort(std::vector<int>& arr) {
    int threshold = 16;

    if (arr.size() > 1) {
        if ((int)arr.size() <= threshold) {
            // Perform insertion sort for small subarrays
            for (size_t i = 1; i < arr.size(); ++i) {
                int key = arr[i];
                int j = i - 1;

                while (j >= 0 && arr[j] > key) {
                    arr[j + 1] = arr[j];
                    --j;
                }
                arr[j + 1] = key;
            }
        } 
        else{
            std::vector<int> left, right;

            // Divide the list into two halves
            size_t mid = arr.size() / 2;

            // Reserve memory for left and right vectors
            left.reserve(mid);
            right.reserve(arr.size() - mid);

            // Copy elements to left and right vectors using random access
            std::copy(arr.begin(), arr.begin() + mid, std::back_inserter(left));
            std::copy(arr.begin() + mid, arr.end(), std::back_inserter(right));

            // Recursively sort the two halves
            MergeSort(left);
            MergeSort(right);

            // Merge the sorted halves
            arr.clear();
            arr.reserve(left.size() + right.size());  // Pre-allocate memory for the arr vector

            Iterator leftIt = left.begin();
            Iterator rightIt = right.begin();

            while (leftIt != left.end() && rightIt != right.end()) {
                if (*leftIt < *rightIt) {
                    arr.push_back(*leftIt++);
                } else {
                    arr.push_back(*rightIt++);
                }
            }

            // Append the remaining elements from left and right (if any)
            arr.insert(arr.end(), leftIt, left.end());
            arr.insert(arr.end(), rightIt, right.end());
        }
    }
    
}

void MergeAndInsert(std::list<int>& result, std::list<int>& left, std::list<int>& right) {
    std::list<int>::iterator leftIt = left.begin();
    std::list<int>::iterator rightIt = right.begin();

    while (leftIt != left.end() && rightIt != right.end()) {
        if (*leftIt < *rightIt) {
            result.splice(result.end(), left, leftIt++);
        } else {
            result.splice(result.end(), right, rightIt++);
        }
    }

    result.splice(result.end(), left, leftIt, left.end());
    result.splice(result.end(), right, rightIt, right.end());
}

void MergeSort(std::list<int>& arr) {
    if (arr.size() <= 1) {
        return;
    }

    std::list<int> left, right;

    // Divide the list into two halves
    std::list<int>::iterator it = arr.begin();
    std::advance(it, arr.size() / 2);
    left.splice(left.begin(), arr, arr.begin(), it);
    right.splice(right.begin(), arr, it, arr.end());

    // Recursively sort the two halves
    MergeSort(left);
    MergeSort(right);

    // Merge the sorted halves
    MergeAndInsert(arr, left, right);
}



double GetTime()
{
    struct timeval time;
    gettimeofday(&time, NULL);
    return (time.tv_sec + time.tv_usec);
}