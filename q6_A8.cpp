#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
    vector<int> heap;
    bool isMaxHeap;

 
    void heapifyDown(int i) {
        int n = heap.size();
        int extreme = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (isMaxHeap) {
            if (left < n && heap[left] > heap[extreme])
                extreme = left;
            if (right < n && heap[right] > heap[extreme])
                extreme = right;
        } else { 
            if (left < n && heap[left] < heap[extreme])
                extreme = left;
            if (right < n && heap[right] < heap[extreme])
                extreme = right;
        }

        if (extreme != i) {
            swap(heap[i], heap[extreme]);
            heapifyDown(extreme);
        }
    }

    void heapifyUp(int i) {
        int parent = (i - 1) / 2;

        if (i > 0) {
            if ((isMaxHeap && heap[i] > heap[parent]) ||
                (!isMaxHeap && heap[i] < heap[parent])) {
                swap(heap[i], heap[parent]);
                heapifyUp(parent);
            }
        }
    }

public:
    PriorityQueue(bool maxHeap = true) {
        isMaxHeap = maxHeap;
    }

    
    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }


    void pop() {
        if (heap.empty()) {
            cout << "Priority Queue is empty!\n";
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty())
            heapifyDown(0);
    }

    int top() {
        if (heap.empty()) {
            cout << "Priority Queue is empty!\n";
            return -1;
        }
        return heap[0];
    }

  
    bool empty() {
        return heap.empty();
    }


    void print() {
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }
};

int main() {
   
    PriorityQueue maxPQ(true);
    maxPQ.push(10);
    maxPQ.push(4);
    maxPQ.push(15);
    maxPQ.push(20);

    cout << "Max-Heap Priority Queue: ";
    maxPQ.print();
    cout << "Top Element: " << maxPQ.top() << endl;

    maxPQ.pop();
    cout << "After removing top: ";
    maxPQ.print();

  
    PriorityQueue minPQ(false);
    minPQ.push(10);
    minPQ.push(4);
    minPQ.push(15);
    minPQ.push(20);

    cout << "\nMin-Heap Priority Queue: ";
    minPQ.print();
    cout << "Top Element: " << minPQ.top() << endl;

    minPQ.pop();
    cout << "After removing top: ";
    minPQ.print();

    return 0;
}
