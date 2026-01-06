/*
 * Heap Sort Implementation
 * This program implements heap sort algorithm.
 * Heap sort builds a max heap from the array and repeatedly extracts the maximum element.
 * Time Complexity: O(n log n) in all cases
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void heapSort(vector<int>& arr) {
    int n = arr.size();

    
    for (int i = 1; i < n; ++i) {
        int childIndex = i;
        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            if (arr[childIndex] > arr[parentIndex]) {
                std::swap(arr[childIndex], arr[parentIndex]);
                childIndex = parentIndex;
            } else {
                break;
            }
        }
    }

    for (int end = n - 1; end > 0; --end) {
        std::swap(arr[0], arr[end]);
        int parentIndex = 0;
        while (true) {
            int leftChild = 2 * parentIndex + 1;
            int rightChild = leftChild + 1;
            if (leftChild >= end) break;

            int largerChild = leftChild;
            if (rightChild < end && arr[rightChild] > arr[leftChild]) {
                largerChild = rightChild;
            }

            if (arr[largerChild] > arr[parentIndex]) {
                std::swap(arr[parentIndex], arr[largerChild]);
                parentIndex = largerChild;
            } else {
                break;
            }
        }
    }
}

void printArray(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    heapSort(arr);
    printArray(arr);
    return 0;
}


