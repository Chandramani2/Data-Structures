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
// MAX HEAP INSERTION
// Rule: Parent must be GREATER than children
// ---------------------------------------------------------
void insertMaxHeap(vector<int>& heap, int val) {
    // Step 1: Add new element to the end
    heap.push_back(val);
    
    // Step 2: "Bubble Up" / "Heapify Up"
    int index = heap.size() - 1;
    
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        
        // If child is greater than parent, swap (Violates Max-Heap)
        if (heap[index] > heap[parentIndex]) {
            swap(heap[index], heap[parentIndex]);
            index = parentIndex; // Move up to parent's position
        } else {
            // Heap property is satisfied
            return;
        }
    }
}

// ---------------------------------------------------------
// MIN HEAP INSERTION
// Rule: Parent must be SMALLER than children
// ---------------------------------------------------------
void insertMinHeap(vector<int>& heap, int val) {
    // Step 1: Add new element to the end
    heap.push_back(val);
    
    // Step 2: "Bubble Up" / "Heapify Up"
    int index = heap.size() - 1;
    
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        
        // If child is smaller than parent, swap (Violates Min-Heap)
        if (heap[index] < heap[parentIndex]) {
            swap(heap[index], heap[parentIndex]);
            index = parentIndex; // Move up to parent's position
        } else {
            // Heap property is satisfied
            return;
        }
    }
}

int main() {
    // --- MAX HEAP ---
    cout << "--- MAX HEAP INSERTION ---\n";
    vector<int> maxHeap = {50, 30, 20, 15, 10, 8, 16};
    cout << "Original Max Heap: ";
    printHeap(maxHeap);
    
    int X_max = 60; // Inserting a value larger than root
    cout << "Inserting " << X_max << "...\n";
    insertMaxHeap(maxHeap, X_max);
    
    cout << "Result Max Heap:   ";
    printHeap(maxHeap); 
    // Expected: 60 becomes root
    cout << endl;

    // --- MIN HEAP ---
    cout << "--- MIN HEAP INSERTION ---\n";
    vector<int> minHeap = {10, 20, 30, 40, 50, 60};
    cout << "Original Min Heap: ";
    printHeap(minHeap);
    
    int X_min = 5; // Inserting a value smaller than root
    cout << "Inserting " << X_min << "...\n";
    insertMinHeap(minHeap, X_min);
    
    cout << "Result Min Heap:   ";
    printHeap(minHeap);
    // Expected: 5 becomes root

    return 0;
}
