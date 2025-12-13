# 🚀 Two Pointers Technique (C++)

A comprehensive guide to solving array, string, and linked list problems using the Two Pointers pattern.

## 📖 Overview

The **Two Pointers** technique involves using two integer variables (indices) to traverse a data structure (usually an array or linked list) in a specific direction to satisfy constraints.

**Why use it?**
It typically optimizes a brute-force $O(N^2)$ solution into a linear $O(N)$ solution by utilizing the sorted nature of data or specific logic to skip unnecessary operations.

---

## 🛠 Type 1: Opposite Ends (Converging)

**Use case:** Sorted arrays, Finding pairs (2 Sum), Reversing, Palindromes.
**Movement:** One pointer starts at the beginning (`left`), the other at the end (`right`). They move toward each other until they meet.

### Template
```cpp
void solve(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        // Logic Example: Check sum of pair
        int current_sum = nums[left] + nums[right];

        if (condition_met(current_sum)) {
            // Found the answer
            return;
        } 
        else if (current_sum < target) {
            left++; // Need a bigger number
        } 
        else {
            right--; // Need a smaller number
        }
    }
}
```

### Common Problems
1.  **Two Sum II (Sorted Input):** Find two numbers that add up to a target.
2.  **Valid Palindrome:** Check if a string is a palindrome ignoring cases/spaces.
3.  **Container With Most Water:** Find max area between lines.

---

## 🏃 Type 2: Same Direction (Fast & Slow)

**Use case:** Removing duplicates, Moving elements (Move Zeroes), Cycle Detection (Linked Lists), Sliding Window bases.
**Movement:** Both pointers start at the beginning. One moves fast (reads data), the other moves slow (writes data or marks boundaries).

### Template
```cpp
void solve(vector<int>& nums) {
    int slow = 0;

    for (int fast = 0; fast < nums.size(); fast++) {
        if (condition(nums[fast])) {
            // Logic: Swap or Assign
            // Example: Move non-zero to slow position
            swap(nums[slow], nums[fast]);
            slow++;
        }
    }
    // 'slow' is now the new length or boundary
}
```

### Common Problems
1.  **Remove Duplicates from Sorted Array:** Keep unique elements at the front.
2.  **Move Zeroes:** Push all 0s to end while maintaining order.
3.  **Linked List Cycle:** `fast` moves 2 steps, `slow` moves 1 step. If they meet, there is a cycle.

---

## 🔗 Type 3: Merging (Two Arrays)

**Use case:** Merging sorted arrays, Intersections, Subsequence checks.
**Movement:** Two independent pointers tracking two different arrays.

### Template
```cpp
void merge(vector<int>& A, vector<int>& B) {
    int i = 0; // Pointer for A
    int j = 0; // Pointer for B
    
    while (i < A.size() && j < B.size()) {
        if (A[i] < B[j]) {
            // A[i] is smaller, process it
            i++;
        } else {
            // B[j] is smaller, process it
            j++;
        }
    }
    
    // Process remaining elements (if any)
    while (i < A.size()) i++;
    while (j < B.size()) j++;
}
```

---

## 🧠 Approach Checklist

When you see a problem, ask:

1.  **Is it an Array or Linked List?**
2.  **Is the data sorted?** (Strong hint for Type 1).
3.  **Do I need to find a pair, triplet, or subarray?**
4.  **Do I need to modify the array in-place?** (Strong hint for Type 2).
5.  **Can I improve the $O(N^2)$ brute force?**

## ⚡ Complexity Analysis

| Type | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Converging** | $O(N)$ | $O(1)$ |
| **Fast & Slow** | $O(N)$ | $O(1)$ |
| **Merging** | $O(N + M)$ | $O(1)$ (usually) |

---

## 📝 Example: Two Sum (Sorted)

**Problem:** Given a 1-indexed array of integers `numbers` that is already sorted in non-decreasing order, find two numbers such that they add up to a specific `target`.

```cpp
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int l = 0;
    int r = numbers.size() - 1;

    while (l < r) {
        int sum = numbers[l] + numbers[r];

        if (sum == target) {
            return {l + 1, r + 1}; // 1-based index requirement
        } else if (sum < target) {
            l++; // We need a larger sum, move left pointer up
        } else {
            r--; // We need a smaller sum, move right pointer down
        }
    }
    return {};
}
```