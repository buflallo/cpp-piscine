#include "PmergeMe.hpp"

void MergeAndInsert(std::vector<int>& arr, Iterator low, Iterator mid, Iterator high) {
    std::vector<int> temp(low, high + 1);

    Iterator leftIt = temp.begin();
    Iterator rightIt = mid + 1;
    Iterator resultIt = arr.begin() + (low - arr.begin());

    while (leftIt <= mid && rightIt <= high) {
        if (*leftIt <= *rightIt) {
            *resultIt++ = *leftIt++;
        } else {
            *resultIt++ = *rightIt++;
        }
    }

    while (leftIt <= mid) {
        *resultIt++ = *leftIt++;
    }

    while (rightIt <= high) {
        *resultIt++ = *rightIt++;
    }
}

void MergeSort(std::vector<int>& arr, Iterator low, Iterator high) {
    const int threshold = 16; // Threshold for switching to insertion sort

    if (low < high) {
        if (high - low <= threshold) {
            // Perform insertion sort for small subarrays
            for (Iterator i = low + 1; i <= high; ++i) {
                int key = *i;
                Iterator j = i - 1;

                while (j >= low && *j > key) {
                    *(j + 1) = *j;
                    --j;
                }

                *(j + 1) = key;
            }
        } else {
            Iterator mid = low + (high - low) / 2;

            // Recursively sort the two halves
            MergeSort(arr, low, mid);
            MergeSort(arr, mid + 1, high);

            // Merge the sorted halves
            MergeAndInsert(arr, low, mid, high);
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