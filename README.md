# C++ STL Cheatsheet

A quick reference guide for the Standard Template Library in C++.

## 1. Headers
Common headers required for STL components.

```cpp
#include <vector>       // Dynamic arrays
#include <list>         // Doubly linked list
#include <deque>        // Double ended queue
#include <set>          // Sorted sets (unique/multi)
#include <map>          // Sorted maps (unique/multi)
#include <unordered_map>// Hash maps
#include <unordered_set>// Hash sets
#include <stack>        // LIFO stack
#include <queue>        // FIFO queue & Priority queue
#include <algorithm>    // Sort, find, binary_search
#include <numeric>      // Accumulate, iota
#include <iterator>     // Iterators
#include <tuple>        // Pairs and tuples
```

---

## 2. Sequence Containers

### `std::vector` (Dynamic Array)
- **Access:** $O(1)$
- **Insert/Delete (End):** $O(1)$ amortized
- **Insert/Delete (Middle):** $O(N)$

```cpp
std::vector<int> v = {1, 2, 3};

// Modifiers
v.push_back(4);             // Add to end
v.pop_back();               // Remove from end
v.insert(v.begin() + 1, 9); // Insert 9 at index 1
v.erase(v.begin() + 1);     // Remove element at index 1
v.clear();                  // Remove all elements

// Access
int x = v[0];               // No bounds checking
int y = v.at(0);            // Bounds checking (throws exception)
int first = v.front();
int last = v.back();

// Capacity
bool e = v.empty();
size_t s = v.size();
v.reserve(100);             // Reserve memory to avoid reallocations
```

### `std::deque` (Double Ended Queue)
- **Access:** $O(1)$
- **Insert/Delete (Both Ends):** $O(1)$

```cpp
std::deque<int> d;
d.push_front(1);
d.push_back(2);
d.pop_front();
d.pop_back();
```

### `std::list` (Doubly Linked List)
- **Access:** $O(N)$
- **Insert/Delete:** $O(1)$ (once iterator is known)

```cpp
std::list<int> l;
l.push_back(10);
l.push_front(5);
l.erase(l.begin()); // Fast removal
```

---

## 3. Associative Containers (Ordered)
Implemented as **Red-Black Trees**. Keys are sorted.
- **Search/Insert/Delete:** $O(\log N)$

### `std::set` & `std::multiset`
- `set`: Unique keys.
- `multiset`: Allow duplicate keys.

```cpp
std::set<int> s;
s.insert(10);
s.insert(10);        // Ignored in set, added in multiset
s.erase(10);         // Removes value

// Find returns iterator or s.end()
auto it = s.find(5); 
if (it != s.end()) { /* found */ }

if (s.count(5)) { /* exists */ }
```

### `std::map` & `std::multimap`
- Key-Value pairs. Sorted by Key.

```cpp
std::map<std::string, int> m;

// Insert or Update O(log N)
m["apple"] = 1;      
m.insert({"banana", 2});

// Access
int val = m["apple"]; 

// Check existence before access (to avoid creating default entry)
if (m.find("carrot") == m.end()) { /* doesn't exist */ }

// Iterating
for (auto const& [key, val] : m) {
    // key is const, val is editable
}
```

---

## 4. Unordered Containers (Hash Tables)
Keys are **not** sorted.
- **Search/Insert/Delete:** $O(1)$ (Average), $O(N)$ (Worst case)

### `std::unordered_set` & `std::unordered_map`

```cpp
std::unordered_map<std::string, int> um;
um["key"] = 100; // O(1) average

// Identical interface to map/set, but no ordering guarantees.
// Requires custom hash function for custom objects (structs/classes).
```

---

## 5. Container Adapters
Restricted interfaces wrapping other containers.

### `std::stack` (LIFO)
```cpp
std::stack<int> s;
s.push(1);
s.pop();       // Returns void, removes top
int top = s.top();
```

### `std::queue` (FIFO)
```cpp
std::queue<int> q;
q.push(1);
q.pop();       // Returns void, removes front
int f = q.front();
int b = q.back();
```

### `std::priority_queue` (Heaps)
- **Insert/Extract:** $O(\log N)$
- **Top:** $O(1)$

```cpp
// Max Heap (Default)
std::priority_queue<int> pq; 
pq.push(10);
pq.push(5);
int top = pq.top(); // 10
pq.pop(); 

// Min Heap
std::priority_queue<int, std::vector<int>, std::greater<int>> min_pq;
min_pq.push(10);
min_pq.push(5);
int low = min_pq.top(); // 5
```

---

## 6. Algorithms
Requires `#include <algorithm>`. Examples use a vector `v`.

### Sorting & Ordering
```cpp
std::vector<int> v = {4, 2, 5, 1, 3};

// Sort Ascending O(N log N)
std::sort(v.begin(), v.end()); 

// Sort Descending
std::sort(v.begin(), v.end(), std::greater<int>()); 

// Custom Comparator (Lambda)
std::sort(v.begin(), v.end(), [](int a, int b) {
    return a < b; // Ascending logic
});

// Reverse
std::reverse(v.begin(), v.end());
```

### Searching (Binary Search)
**Pre-condition:** Container must be sorted!

```cpp
// Check existence
bool exists = std::binary_search(v.begin(), v.end(), 3);

// Lower Bound: First element >= value
auto lb = std::lower_bound(v.begin(), v.end(), 3); 

// Upper Bound: First element > value
auto ub = std::upper_bound(v.begin(), v.end(), 3); 

// Number of occurrences (for sorted range)
int count = ub - lb;
```

### General Find & Count
Works on unsorted containers.

```cpp
// Find (Linear search)
auto it = std::find(v.begin(), v.end(), 3);
if (it != v.end()) { /* found */ }

// Count occurrences
int c = std::count(v.begin(), v.end(), 3);

// Max and Min elements
auto max_it = std::max_element(v.begin(), v.end());
auto min_it = std::min_element(v.begin(), v.end());
// Dereference to get value: *max_it
```

### Permutations
```cpp
std::string s = "abc";
std::sort(s.begin(), s.end()); // Must be sorted for all permutations
do {
    // prints abc, acb, bac, bca, cab, cba
} while (std::next_permutation(s.begin(), s.end()));
```

---

## 7. Pairs & Tuples

### `std::pair`
```cpp
std::pair<int, std::string> p = {1, "apple"};
p.first = 2;
// p.second is "apple"
```

### `std::tuple`
```cpp
#include <tuple>

std::tuple<int, double, std::string> t = {1, 3.14, "pi"};

// Access (compile time index)
int i = std::get<0>(t);
double d = std::get<1>(t);

// Structured Binding (C++17) - Unpacking
auto [id, val, name] = t;
```

---

## 8. Common Numeric Operations
Requires `#include <numeric>`.

```cpp
// Sum of elements
int sum = std::accumulate(v.begin(), v.end(), 0);

// Product of elements
int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());

// Fill with sequential values (0, 1, 2, 3...)
std::vector<int> seq(10);
std::iota(seq.begin(), seq.end(), 0);

// GCD (C++17)
int g = std::gcd(12, 18); // 6
```