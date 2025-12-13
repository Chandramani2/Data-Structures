# 🔗 Linked List Cheatsheet (C++)

A comprehensive guide to mastering Linked Lists, covering implementation, traversal techniques, and common algorithmic patterns.

## 📖 Overview

A **Linked List** is a linear data structure where elements are not stored in contiguous memory locations. The elements are linked using pointers.

### Node Structure (C++)
```cpp
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
```

---

## 🛠 Standard Operations

### 1. Traversal
```cpp
void traverse(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->val << " -> ";
        curr = curr->next;
    }
}
```

### 2. Deletion
```cpp
void deleteNode(ListNode*& head, int val) {
    if (!head) return;
    
    // Head deletion
    if (head->val == val) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    ListNode* curr = head;
    while (curr->next && curr->next->val != val) {
        curr = curr->next;
    }

    if (curr->next) { 
        ListNode* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
    }
}
```

---

## 🧠 Essential Techniques (The "Cheat Codes")

### 1. The Dummy Node (Sentinel)
Simplifies edge cases (e.g., deleting head, merging). Always return `dummy->next`.

```cpp
ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    
    ListNode* curr = dummy;
    while (curr->next != nullptr) {
        if (curr->next->val == val) {
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
        }
    }
    return dummy->next;
}
```

### 2. Fast & Slow Pointers (Tortoise and Hare)
Used for **Cycle Detection** and **Finding Middle**.

```cpp
// Find Middle Node
ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;      // 1 step
        fast = fast->next->next;// 2 steps
    }
    return slow;
}

// Detect Cycle
bool hasCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}
```

### 3. Reversing a List (Iterative)
Standard interview problem. Uses 3 pointers.

```cpp
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    
    while (curr != nullptr) {
        ListNode* nextTemp = curr->next; 
        curr->next = prev;               
        prev = curr;                     
        curr = nextTemp;                 
    }
    return prev; // New head
}
```

### 4. Merging Two Lists
Using a stack-allocated dummy node for cleaner code.

```cpp
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0); 
    ListNode* tail = &dummy;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    if (l1) tail->next = l1;
    if (l2) tail->next = l2;

    return dummy.next;
}
```

---

## ⚡ Complexity Cheatsheet

| Operation | Singly LL | Doubly LL | Array |
| :--- | :--- | :--- | :--- |
| **Access (Index)** | $O(N)$ | $O(N)$ | $O(1)$ |
| **Insert/Delete (Head)** | $O(1)$ | $O(1)$ | $O(N)$ |
| **Insert/Delete (Middle)**| $O(N)$ | $O(N)$ | $O(N)$ |