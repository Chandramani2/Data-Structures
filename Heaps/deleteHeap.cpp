#include "bits/stdc++.h"
using namespace std;
/* 	1 based indexing
		- parent = i/2, child = 2i, 2i+1
	0 based indexing
		- parent = (i-1)/2, child = 2i+1, 2i+2
*/

// Function to print the heap
void printHeap(const vector<int>& heap) {
    for (int i : heap) {
        cout << i << " ";
    }
    cout << endl;
}

// ---------------------------------------------------------
// MAX HEAP DELETION (Remove Root/Max)
// 1. Move last element to root
// 2. Remove last element
// 3. Heapify Down
// ---------------------------------------------------------
void deleteMaxHeap(vector<int>& heap) {
    if (heap.empty()) return;

    int n = heap.size();
    // Step 1: Replace root with the last element
    swap(heap[0], heap[n-1]); // moved root ele to the last
    heap.pop_back();

    // Step 2: "Heapify Down"
    int index = 0;

    while (true) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        // Compare with Left Child
        if (leftChild < n && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }

        // Compare with Right Child
        if (rightChild < n && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }

        // If root is smaller than largest child, swap
        if (largest != index) {
            swap(heap[index], heap[largest]);
            index = largest; // Move down
        } else {
            break; // Position is correct
        }
    }
}

// ---------------------------------------------------------
// MIN HEAP DELETION (Remove Root/Min)
// ---------------------------------------------------------
void deleteMinHeap(vector<int>& heap) {
    if (heap.empty()) return;

    int n = heap.size();
    // Step 1: Replace root with the last element
    swap(heap[0], heap[n-1]); // moved root ele to the last
    heap.pop_back();

    // Step 2: "Heapify Down"
    int index = 0;

    while (true) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;

        // Compare with Left Child
        if (leftChild < n && heap[leftChild] < heap[smallest]) {
            smallest = leftChild;
        }

        // Compare with Right Child
        if (rightChild < n && heap[rightChild] < heap[smallest]) {
            smallest = rightChild;
        }

        // If root is larger than smallest child, swap
        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            index = smallest; // Move down
        } else {
            break; // Position is correct
        }
    }
}

int main() {
    // --- MAX HEAP ---
    cout << "--- MAX HEAP DELETION ---\n";
    vector<int> maxHeap = {50, 30, 20, 15, 10, 8, 16};
    cout << "Original Max Heap: ";
    printHeap(maxHeap);
    
    // Deleting root (MAX Value)
    cout << "Deleting Max (Root)...\n";
    deleteMaxHeap(maxHeap);
    cout << "After Delete: ";
    printHeap(maxHeap);
    cout << endl;

    // --- MIN HEAP ---
    cout << "--- MIN HEAP DELETION ---\n";
    vector<int> minHeap = {10, 20, 30, 40, 50, 60};
    cout << "Original Min Heap: ";
    printHeap(minHeap);
    
    // Deleting root (MIN Value)
    cout << "\nDeleting Min (Root)...\n";
    deleteMinHeap(minHeap);
    cout << "After Delete: ";
    printHeap(minHeap);

    return 0;
}
