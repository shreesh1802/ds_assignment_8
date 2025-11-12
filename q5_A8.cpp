#include <iostream>
#include <vector>
using namespace std;


void heapify(vector<int>& arr, int n, int i, bool isMaxHeap) {
    int extreme = i;  
    int left = 2 * i + 1;
    int right = 2 * i + 2;

   
    if (isMaxHeap) {
        if (left < n && arr[left] > arr[extreme])
            extreme = left;
        if (right < n && arr[right] > arr[extreme])
            extreme = right;
    } else { 
        if (left < n && arr[left] < arr[extreme])
            extreme = left;
        if (right < n && arr[right] < arr[extreme])
            extreme = right;
    }


    if (extreme != i) {
        swap(arr[i], arr[extreme]);
        heapify(arr, n, extreme, isMaxHeap);
    }
}


void heapSort(vector<int>& arr, bool increasing = true) {
    int n = arr.size();
    bool isMaxHeap = increasing;  

   
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, isMaxHeap);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]); 
        heapify(arr, i, 0, isMaxHeap);
    }


    if (!increasing)
        reverse(arr.begin(), arr.end());
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    vector<int> incArr = arr;
    heapSort(incArr, true);
    cout << "Heap Sort (Increasing order): ";
    for (int x : incArr) cout << x << " ";
    cout << endl;

    vector<int> decArr = arr;
    heapSort(decArr, false);
    cout << "Heap Sort (Decreasing order): ";
    for (int x : decArr) cout << x << " ";
    cout << endl;

    return 0;
}
