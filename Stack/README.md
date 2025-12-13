# 📚 Stack Cheatsheet (C++)

A comprehensive guide to the **Stack** data structure, including standard operations, common interview patterns (Monotonic Stack), and complexity analysis.

## 📖 Overview

A **Stack** is a linear data structure that follows the **LIFO (Last In, First Out)** principle. The last element added is the first one to be removed.

### Standard Library (`<stack>`)
```cpp
#include <stack>
stack<int> s;
```

---

## 🛠 Standard Operations
All basic operations are **$O(1)$**.

| Operation | Function | Description |
| :--- | :--- | :--- |
| **Push** | `s.push(val)` | Adds `val` to the top. |
| **Pop** | `s.pop()` | Removes the top element (returns void). |
| **Top** | `s.top()` | Returns a reference to the top element. |
| **Size** | `s.size()` | Returns the number of elements. |
| **Empty** | `s.empty()` | Returns `true` if the stack is empty. |

---

## 🧠 Essential Techniques (The "Cheat Codes")

### 1. Monotonic Stack (Next Greater Element)
**Use Case:** Finding the Next/Previous Greater/Smaller Element in $O(N)$.
**Logic:** Maintain a stack that is always sorted.

```cpp
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1); 
    stack<int> s; // Stores INDICES

    for (int i = 0; i < n; i++) {
        // Decreasing Stack Logic:
        // If current num > top of stack, we found the "Next Greater" for the top
        while (!s.empty() && nums[i] > nums[s.top()]) {
            int index = s.top();
            s.pop();
            result[index] = nums[i];
        }
        s.push(i);
    }
    return result;
}
```

### 2. Valid Parentheses (Matching)
**Use Case:** Checking balanced symbols `()`, `[]`, `{}`.

```cpp
bool isValid(string str) {
    stack<char> s;
    for (char c : str) {
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        } else {
            if (s.empty()) return false;
            char top = s.top();
            if ((c == ')' && top != '(') || 
                (c == '}' && top != '{') || 
                (c == ']' && top != '[')) return false;
            s.pop();
        }
    }
    return s.empty();
}
```

### 3. Min Stack (Design)
**Problem:** Get minimum element in $O(1)$.
**Logic:** Use an auxiliary stack to track the minimum at every state.

```cpp
class MinStack {
    stack<int> s, min_s;
public:
    void push(int val) {
        s.push(val);
        if (min_s.empty() || val <= min_s.top()) min_s.push(val);
    }
    void pop() {
        if (s.top() == min_s.top()) min_s.pop();
        s.pop();
    }
    int getMin() { return min_s.top(); }
};
```

---

## ⚡ Complexity Cheatsheet

| Operation | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Push/Pop/Top** | $O(1)$ | $O(1)$ |
| **Monotonic Stack**| $O(N)$ | $O(N)$ |