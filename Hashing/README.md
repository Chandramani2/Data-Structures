# 🔑 Hashing Cheatsheet (C++)

A comprehensive guide to Hashing, covering `std::unordered_map`, `std::unordered_set`, and essential patterns for $O(1)$ lookups.

## 📖 Overview

**Hashing** transforms a key into an index (hash code) to store and retrieve data in an array (Hash Table).

* **Key Idea:** Trade space for time ($O(1)$ average lookups).
* **Collision:** When two keys generate the same hash. STL uses Chaining.

### Standard Library
```cpp
#include <unordered_map>
#include <unordered_set>
```

---

## 🛠 Standard Operations

### 1. Unordered Map (Key-Value)
```cpp
void mapOps() {
    std::unordered_map<std::string, int> m;

    m["apple"] = 1;         // Insert
    int x = m["apple"];     // Access
    
    // Check Existence
    if (m.count("banana")) { 
        // exists 
    }

    // Iterate
    for (auto& [key, val] : m) {
        // process
    }
}
```

### 2. Unordered Set (Key Only)
```cpp
void setOps() {
    std::unordered_set<int> s;
    s.insert(10);
    if (s.count(10)) { /* found */ }
    s.erase(10);
}
```

---

## 🧠 Essential Techniques (The "Cheat Codes")

### 1. Frequency Counter
**Pattern:** `map[element]++`

```cpp
unordered_map<int, int> countFreq(vector<int>& nums) {
    unordered_map<int, int> freq;
    for (int num : nums) freq[num]++;
    return freq;
}
```

### 2. Two Sum (Complements)
**Pattern:** Check `target - current`.

```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> seen; 
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (seen.count(complement)) return {seen[complement], i};
        seen[nums[i]] = i;
    }
    return {};
}
```

### 3. Subarray Sum Equals K (Prefix Sum)
**Pattern:** Store cumulative sums. `curr_sum - k` means subarray exists.

```cpp
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixSum; 
    prefixSum[0] = 1; 
    
    int sum = 0, count = 0;
    for (int num : nums) {
        sum += num;
        if (prefixSum.count(sum - k)) count += prefixSum[sum - k];
        prefixSum[sum]++;
    }
    return count;
}
```

---

## 🔧 Custom Hashing (Pairs)

Standard STL maps don't hash `std::pair` by default.

```cpp
struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

// Usage
unordered_map<pair<int, int>, int, PairHash> m;
```

---

## ⚡ Complexity Cheatsheet

| Operation | Unordered Map/Set (Hash) | Ordered Map/Set (Tree) |
| :--- | :--- | :--- |
| **Insert** | $O(1)$ Average | $O(\log N)$ |
| **Find/Access** | $O(1)$ Average | $O(\log N)$ |
| **Delete** | $O(1)$ Average | $O(\log N)$ |
| **Worst Case** | $O(N)$ (Collisions) | $O(\log N)$ |