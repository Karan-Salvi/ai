#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        // Find index of minimum element in the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        // Swap the minimum element with the first element of unsorted part
        if (minIndex != i)
            swap(arr[i], arr[minIndex]);
    }
}

void printVector(const vector<int>& arr) {
    for (int val : arr)
        cout << val << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {29, 10, 14, 37, 13};

    cout << "Original vector: ";
    printVector(arr);

    selectionSort(arr);

    cout << "Sorted vector:   ";
    printVector(arr);

    return 0;
}
