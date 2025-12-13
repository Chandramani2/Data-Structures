# ⚡ Bit Manipulation Cheatsheet (C++)

A guide to mastering bitwise operations, essential for optimizing space and time complexity in competitive programming and systems programming.

## 📖 Overview

Bit manipulation involves applying logical operations on individual bits of integers. It is extremely fast (CPU level instructions) and efficient ($O(1)$).

**Why use it?**
* **Space Efficiency:** Storing boolean flags in a single integer (bitmasking).
* **Time Efficiency:** Mathematical operations (multiplication/division by 2) are faster.
* **Unique Properties:** XOR operations are crucial for solving "missing number" or "single occurrence" problems.

---

## 🛠 Basic Operators

| Operator | Symbol | Description | Example ($A=5, B=3$) |
| :--- | :---: | :--- | :--- |
| **AND** | `&` | 1 if both bits are 1 | `5 & 3` $\to$ `1` |
| **OR** | `|` | 1 if either bit is 1 | `5 | 3` $\to$ `7` |
| **XOR** | `^` | 1 if bits are different | `5 ^ 3` $\to$ `6` |
| **NOT** | `~` | Inverts all bits | `~5` |
| **Left Shift** | `<<` | Shifts bits left (Multiply by $2^k$) | `5 << 1` $\to$ `10` |
| **Right Shift** | `>>` | Shifts bits right (Divide by $2^k$) | `5 >> 1` $\to$ `2` |

---

## 🎮 The "Get, Set, Clear" Trio

The foundation of bit manipulation relies on creating a **Mask** using `1 << k`.

### 1. Check if $k$-th bit is set (Get)
```cpp
bool isSet(int n, int k) {
    return (n & (1 << k)) != 0;
}
```

### 2. Set the $k$-th bit (Turn On)
```cpp
int setBit(int n, int k) {
    return n | (1 << k);
}
```

### 3. Clear the $k$-th bit (Turn Off)
```cpp
int clearBit(int n, int k) {
    return n & ~(1 << k);
}
```

### 4. Toggle the $k$-th bit
```cpp
int toggleBit(int n, int k) {
    return n ^ (1 << k);
}
```

---

## 🧠 Essential Tricks & Hacks

These are $O(1)$ operations that replace loops.

### 1. Check if number is Power of 2
Powers of 2 have exactly one bit set (e.g., 4 is `100`, 8 is `1000`).
```cpp
bool isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}
```

### 2. Clear the Lowest Set Bit
Removes the rightmost '1'. Important for counting bits (Brian Kernighan’s Algorithm).
```cpp
n = n & (n - 1);
// Ex: 0110 (6) -> 0100 (4)
```

### 3. Get the Lowest Set Bit
Isolates the rightmost '1'.
```cpp
int lowBit = n & (-n);
// Ex: 0110 (6) -> 0010 (2)
```

### 4. Swap two numbers (No Temp Var)
Using XOR properties ($a \oplus a = 0$).
```cpp
void swap(int &a, int &b) {
    a ^= b;
    b ^= a;
    a ^= b;
}
```

---

## ⚡ Built-in C++ Functions (GCC/Clang)
These are highly optimized hardware instructions. For competitive programming, use these instead of writing loops.

```cpp
int n = 5; // 00...00101

// Count set bits (Population Count)
int count = __builtin_popcount(n); 

// Count leading zeros
int clz = __builtin_clz(n); 

// Count trailing zeros
int ctz = __builtin_ctz(n); 

// For long long, append 'll' (e.g., __builtin_popcountll)
```

**Note:** For C++20, use the standard header `<bit>`:
`std::popcount(n)`, `std::countl_zero(n)`, etc.

---

## 📝 Example: Single Number

**Problem:** Given an array where every element appears twice except for one. Find that single one.
**Logic:** XORing a number with itself results in 0. XORing with 0 remains unchanged.

```cpp
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int x : nums) {
        result ^= x;
    }
    return result;
}
```