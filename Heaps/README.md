# 🏔️ Heaps (Priority Queue) Cheatsheet (C++)

A comprehensive guide to Heaps, covering `std::priority_queue`, Min/Max Heap implementations, and essential patterns for sorting and selection problems.

## 📖 Overview

A **Heap** is a specialized tree-based data structure (usually a Complete Binary Tree) that satisfies the Heap Property.

### Standard Library (`<queue>`)
* **Max Heap:** `priority_queue<int> pq;`
* **Min Heap:** `priority_queue<int, vector<int>, greater<int>> pq;`

---

## 🛠 Standard Operations

### 1. Max Heap (Default)
```cpp
void maxHeapOps() {
    priority_queue<int> pq; 

    pq.push(10); // O(log N)
    pq.push(30);

    int max = pq.top(); // 30 (O(1))
    pq.pop();           // Removes 30 (O(log N))
}
```

### 2. Min Heap
```cpp
void minHeapOps() {
    // <Type, Container, Comparator>
    priority_queue<int, vector<int>, greater<int>> minPQ;

    minPQ.push(10);
    minPQ.push(5);

    int min = minPQ.top(); // 5
    minPQ.pop();
}
```

---

## 🧠 Essential Techniques (The "Cheat Codes")

### 1. K-th Largest Element (Min Heap Pattern)
**Logic:** Maintain a Min Heap of size **K**. The heap will contain the K largest elements seen so far. The top is the smallest of the large ones (the K-th largest).

```cpp
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for (int num : nums) {
        minHeap.push(num);
        if (minHeap.size() > k) {
            minHeap.pop(); 
        }
    }
    return minHeap.top();
}
```

### 2. Merge K Sorted Lists
**Logic:** Push current heads of all lists to Min Heap. Extract min, push its `next`.

```cpp
struct Compare {
    bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
    for (auto list : lists) if (list) pq.push(list);
    
    ListNode dummy(0), *tail = &dummy;
    
    while (!pq.empty()) {
        tail->next = pq.top(); pq.pop();
        tail = tail->next;
        if (tail->next) pq.push(tail->next);
    }
    return dummy.next;
}
```

### 3. Median of Stream
**Logic:** Two Heaps. Max Heap for lower half, Min Heap for upper half.

```cpp
// Add Num
maxHeap.push(num);
minHeap.push(maxHeap.top()); maxHeap.pop();
if (minHeap.size() > maxHeap.size()) {
    maxHeap.push(minHeap.top()); minHeap.pop();
}
```

---

## ⚡ Complexity Cheatsheet

| Operation | Time Complexity | Note |
| :--- | :--- | :--- |
| **Push** | $O(\log N)$ | |
| **Pop** | $O(\log N)$ | |
| **Top** | $O(1)$ | |
| **Build (Heapify)**| $O(N)$ | Faster than N insertions |