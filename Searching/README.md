# 🔍 Binary Search Cheatsheet (C++)

A comprehensive guide to Binary Search, covering standard implementations, boundary searches, and the powerful "Binary Search on Answer" pattern.

## 📖 Overview

**Binary Search** is an efficient algorithm to find a target value in a **sorted** collection.

* **Logic:** Repeatedly divide the search interval in half.
* **Requirement:** The search space must be **monotonic** (sorted).
* **Efficiency:** $O(\log N)$ vs $O(N)$.

### Midpoint Calculation Safety
```cpp
int mid = left + (right - left) / 2; // Prevents overflow
```

---

## 🛠 1. Standard Binary Search
**Goal:** Find exact index.

```cpp
int binarySearch(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
```

---

## 🎯 2. The "Bounds" (First & Last Occurrence)

### Lower Bound (First $\ge$ Target)
```cpp
int lowerBound(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int result = nums.size();

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) {
            result = mid;   
            right = mid - 1; // Try left
        } else {
            left = mid + 1;
        }
    }
    return result;
}
```
*STL Equivalent:* `lower_bound(v.begin(), v.end(), target) - v.begin()`

### Upper Bound (First $>$ Target)
```cpp
int upperBound(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int result = nums.size();

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > target) {
            result = mid;
            right = mid - 1; // Try left
        } else {
            left = mid + 1;
        }
    }
    return result;
}
```

---

## 🧠 3. Binary Search on Answer
**Pattern:** "Minimize the Maximum" or "Maximize the Minimum".
**Logic:** Search over the **range of possible answers**, not the array indices.

**Template:**
```cpp
bool isPossible(int x, vector<int>& nums) {
    // Logic to check if 'x' is a valid solution
    return true;
}

int solve() {
    int left = MIN_POSSIBLE_ANS;
    int right = MAX_POSSIBLE_ANS;
    int ans = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (isPossible(mid)) {
            ans = mid;      // Found valid, try to optimize
            right = mid - 1;// Try smaller (if minimizing)
        } else {
            left = mid + 1; // Invalid, need larger
        }
    }
    return ans;
}
```

---

## 🔄 4. Rotated Sorted Array
**Logic:** One half (left or right) is always sorted.

```cpp
int searchRotated(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;

        // Check if Left side is sorted
        if (nums[left] <= nums[mid]) {
            if (target >= nums[left] && target < nums[mid]) right = mid - 1;
            else left = mid + 1;
        } 
        // Right side is sorted
        else {
            if (target > nums[mid] && target <= nums[right]) left = mid + 1;
            else right = mid - 1;
        }
    }
    return -1;
}
```

---

## ⚡ Complexity Cheatsheet

| Algorithm | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Standard Search** | $O(\log N)$ | $O(1)$ |
| **Search on Answer** | $O(\log(\text{Range}) \cdot F(N))$ | $O(1)$ |