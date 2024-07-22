# Search Algorithms Documentation

## Table of Contents

1. [Overview](#overview)
2. [Linear Search](#linear-search)
    - [Algorithm](#linear-search-algorithm)
    - [Pseudocode](#linear-search-pseudocode)
    - [Example](#linear-search-example)
    - [Pros and Cons](#linear-search-pros-and-cons)
    - [Use Cases](#linear-search-use-cases)
    - [Complexities](#linear-search-complexities)
3. [Binary Search](#binary-search)
    - [Algorithm](#binary-search-algorithm)
    - [Pseudocode](#binary-search-pseudocode)
    - [Example](#binary-search-example)
    - [Pros and Cons](#binary-search-pros-and-cons)
    - [Use Cases](#binary-search-use-cases)
    - [Complexities](#binary-search-complexities)
4. [Jump Search](#jump-search)
    - [Algorithm](#jump-search-algorithm)
    - [Pseudocode](#jump-search-pseudocode)
    - [Example](#jump-search-example)
    - [Pros and Cons](#jump-search-pros-and-cons)
    - [Use Cases](#jump-search-use-cases)
    - [Complexities](#jump-search-complexities)
5. [Interpolation Search](#interpolation-search)
    - [Algorithm](#interpolation-search-algorithm)
    - [Pseudocode](#interpolation-search-pseudocode)
    - [Example](#interpolation-search-example)
    - [Pros and Cons](#interpolation-search-pros-and-cons)
    - [Use Cases](#interpolation-search-use-cases)
    - [Complexities](#interpolation-search-complexities)
6. [Exponential Search](#exponential-search)
    - [Algorithm](#exponential-search-algorithm)
    - [Pseudocode](#exponential-search-pseudocode)
    - [Example](#exponential-search-example)
    - [Pros and Cons](#exponential-search-pros-and-cons)
    - [Use Cases](#exponential-search-use-cases)
    - [Complexities](#exponential-search-complexities)
7. [Linked List Search](#linked-list-search)
    - [Algorithm](#linked-list-search-algorithm)
    - [Pseudocode](#linked-list-search-pseudocode)
    - [Example](#linked-list-search-example)
    - [Pros and Cons](#linked-list-search-pros-and-cons)
    - [Use Cases](#linked-list-search-use-cases)
    - [Complexities](#linked-list-search-complexities)
8. [Skip List Search](#skip-list-search)
    - [Algorithm](#skip-list-search-algorithm)
    - [Pseudocode](#skip-list-search-pseudocode)
    - [Example](#skip-list-search-example)
    - [Pros and Cons](#skip-list-search-pros-and-cons)
    - [Use Cases](#skip-list-search-use-cases)
    - [Complexities](#skip-list-search-complexities)
9. [Comparison of Search Algorithms](#comparison-of-search-algorithms)
10. [Summary](#summary)

## Overview

Searching algorithms are fundamental in computer science, used to retrieve information stored within a data structure.
This documentation provides an overview of several common searching algorithms: linear search, binary search, jump
search, interpolation search, exponential search, linked list search, and skip list search. Each algorithm is described
with its implementation, pros and
cons, use cases, and complexities.

## 1. Linear Search

### Algorithm

Linear search is a straightforward algorithm that scans each element in the list sequentially until it finds the target
value or reaches the end of the list. This method does not require the list to be sorted and is easy to implement but
can be inefficient for large datasets.

### Pseudocode

```python
def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1
```

### Example

Consider an array `arr = [4, 2, 7, 1, 9, 3]` and target value `7`.

1. Compare `4` with `7` (no match).
2. Compare `2` with `7` (no match).
3. Compare `7` with `7` (match found).

**Result**: Index 2

### Pros and Cons

**Pros:**

- Simple to implement.
- Works on both sorted and unsorted lists.

**Cons:**

- Inefficient for large datasets.
- Time complexity is high as it may need to check each element.

### Use Cases

- Small or unsorted datasets.
- Lists where the cost of sorting is higher than linear search.

### Complexities

- **Best Case**: O(1)
- **Average Case**: O(n)
- **Worst Case**: O(n)
- **Space Complexity**: O(1)

## 2. Binary Search

### Algorithm

Binary search is an efficient algorithm that works on sorted lists. It repeatedly divides the list into halves and
checks the middle element, reducing the search interval by half each time. This logarithmic approach significantly
reduces the number of comparisons needed.

### Pseudocode

```python
def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1
```

### Example

Consider a sorted array `arr = [1, 2, 3, 4, 7, 9]` and target value `7`.

1. Initial array: [1, 2, 3, 4, 7, 9]
2. Middle element is `3` (index 2). Since `3 < 7`, search in the right half: [4, 7, 9]
3. Middle element is `7` (index 4). Match found.

**Result**: Index 4

### Pros and Cons

**Pros:**

- Much more efficient than linear search.
- Lower time complexity for large datasets.

**Cons:**

- Requires a sorted list.
- More complex implementation than linear search.

### Use Cases

- Large, sorted datasets.
- Efficiently finding elements in databases and dictionaries.

### Complexities

- **Best Case**: O(1)
- **Average Case**: O(log n)
- **Worst Case**: O(log n)
- **Space Complexity**: O(1)

## 3. Jump Search

### Algorithm

Jump search is designed for sorted lists. It divides the list into blocks of fixed size and jumps ahead by these blocks
to find the range where the target may be. It then performs a linear search within this range.

### Pseudocode

```python
import math


def jump_search(arr, target):
    n = len(arr)
    step = int(math.sqrt(n))
    prev = 0

    while arr[min(step, n) - 1] < target:
        prev = step
        step += int(math.sqrt(n))
        if prev >= n:
            return -1

    for i in range(prev, min(step, n)):
        if arr[i] == target:
            return i
    return -1
```

### Example

Consider a sorted array `arr = [1, 2, 3, 4, 7, 9]` and target value `7`.

1. Initial array: [1, 2, 3, 4, 7, 9]
2. Jump by 2 (√6 ≈ 2). Check `3` (index 2).
3. Since `3 < 7`, jump again. Check `7` (index 4). Match found.

**Result**: Index 4

### Pros and Cons

**Pros:**

- More efficient than linear search for large, sorted datasets.
- Does not require the entire list to be traversed.

**Cons:**

- Requires a sorted list.
- Less efficient than binary search.

### Use Cases

- Large, sorted datasets.
- Scenarios where a linear search is too slow but binary search is not ideal.

### Complexities

- **Best Case**: O(1)
- **Average Case**: O(√n)
- **Worst Case**: O(√n)
- **Space Complexity**: O(1)

## 4. Interpolation Search

### Algorithm

Interpolation search is an advanced search algorithm for uniformly distributed sorted lists. It estimates the position
of the target based on the values of the elements, akin to how one might search for a word in a telephone directory.

### Pseudocode

```python
def interpolation_search(arr, target):
    low = 0
    high = len(arr) - 1

    while low <= high and target >= arr[low] and target <= arr[high]:
        if low == high:
            if arr[low] == target:
                return low
            return -1

        pos = low + int(((float(high - low) / (arr[high] - arr[low])) * (target - arr[low])))

        if arr[pos] == target:
            return pos
        if arr[pos] < target:
            low = pos + 1
        else:

            high = pos - 1
    return -1
```

### Example

Consider a uniformly distributed sorted array `arr = [1, 2, 3, 4, 7, 9]` and target value `7`.

1. Initial array: [1, 2, 3, 4, 7, 9]
2. Calculate position using the formula.
3. Estimate position is `4`. Check `7` (index 4). Match found.

**Result**: Index 4

### Pros and Cons

**Pros:**

- Efficient for uniformly distributed sorted datasets.
- Can be faster than binary search in some cases.

**Cons:**

- Requires uniformly distributed sorted data.
- Complex implementation.

### Use Cases

- Large, uniformly distributed sorted datasets.
- Efficient search in databases with uniform key distribution.

### Complexities

- **Best Case**: O(1)
- **Average Case**: O(log log n)
- **Worst Case**: O(n)
- **Space Complexity**: O(1)

## 5. Exponential Search

### Algorithm

Exponential search is a combination of binary search and an initial exponential search phase. It first finds the range
where the target may exist by repeatedly doubling the interval, then performs a binary search within this range.

### Pseudocode

```python
def exponential_search(arr, target):
    if arr[0] == target:
        return 0
    n = len(arr)
    i = 1
    while i < n and arr[i] <= target:
        i = i * 2

    return binary_search(arr[:min(i, n)], target)


def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1
```

### Example

Consider a sorted array `arr = [1, 2, 3, 4, 7, 9]` and target value `7`.

1. Initial array: [1, 2, 3, 4, 7, 9]
2. Check `arr[1]`, `arr[2]`, `arr[4]` (by doubling the index each time).
3. Found `7` in the interval [4, 7, 9].
4. Perform binary search in this interval. Match found.

**Result**: Index 4

### Pros and Cons

**Pros:**

- Efficient for large, sorted datasets.
- Combines the benefits of binary search with an initial exponential phase.

**Cons:**

- Requires a sorted list.
- More complex implementation.

### Use Cases

- Large, sorted datasets.
- Efficient search when the position of the target is closer to the beginning of the list.

### Complexities

- **Best Case**: O(1)
- **Average Case**: O(log n)
- **Worst Case**: O(log n)
- **Space Complexity**: O(1)

## 6. Linked List Search

### Algorithm

Linked list search involves traversing the nodes of a linked list one by one until the target value is found. This is
similar to linear search but operates on a linked list data structure.

### Pseudocode

```python
class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


def linked_list_search(head, target):
    current = head
    index = 0
    while current:
        if current.value == target:
            return index
        current = current.next
        index += 1
    return -1
```

### Example

Consider a linked list: `1 -> 2 -> 3 -> 4 -> 7 -> 9` and target value `7`.

1. Start at head: `1` (no match).
2. Move to `2` (no match).
3. Move to `3` (no match).
4. Move to `4` (no match).
5. Move to `7` (match found).

**Result**: Index 4

### Pros and Cons

**Pros:**

- Simple to implement.
- Suitable for linked list data structures.

**Cons:**

- Inefficient for large lists.
- No indexing, requires traversal of nodes.

### Use Cases

- Searching in linked list data structures.
- Scenarios where list size is small.

### Complexities

- **Best Case**: O(1)
- **Average Case**: O(n)
- **Worst Case**: O(n)
- **Space Complexity**: O(1)

## 7. Skip List Search

### Algorithm

Skip list search is an efficient algorithm designed for sorted linked lists with multiple levels of forward pointers,
allowing for fast search operations by "skipping" over nodes.

### Pseudocode

```python
class SkipListNode:
    def __init__(self, value, level):
        self.value = value
        self.forward = [None] * (level + 1)


def skip_list_search(head, target):
    current = head
    for level in range(len(current.forward) - 1, -1, -1):
        while current.forward[level] and current.forward[level].value < target:
            current = current.forward[level]
    current = current.forward[0]
    if current and current.value == target:
        return True
    return False
```

### Example

Consider a skip list with multiple levels, and target value `7`.

1. Start at highest level, move forward while current node value < 7.
2. Drop down a level, continue moving forward.
3. Repeat until reaching the base level.
4. Check base level node for target value.

**Result**: Found or not found.

### Pros and Cons

**Pros:**

- Efficient for large, sorted linked lists.
- Faster search times due to skipping nodes.

**Cons:**

- More complex implementation.
- Requires additional space for forward pointers.

### Use Cases

- Large, sorted linked lists.
- Scenarios where fast search operations are required.

### Complexities

- **Best Case**: O(1)
- **Average Case**: O(log n)
- **Worst Case**: O(log n)
- **Space Complexity**: O(n)

## Comparison of Search Algorithms

| Algorithm                | Best Case | Average Case | Worst Case | Space Complexity | Use Cases                             |
|--------------------------|-----------|--------------|------------|------------------|---------------------------------------|
| **Linear Search**        | O(1)      | O(n)         | O(n)       | O(1)             | Small/unsorted datasets               |
| **Binary Search**        | O(1)      | O(log n)     | O(log n)   | O(1)             | Large/sorted datasets                 |
| **Jump Search**          | O(1)      | O(√n)        | O(√n)      | O(1)             | Large/sorted datasets                 |
| **Interpolation Search** | O(1)      | O(log log n) | O(n)       | O(1)             | Uniformly distributed sorted datasets |
| **Exponential Search**   | O(1)      | O(log n)     | O(log n)   | O(1)             | Large/sorted datasets, early matches  |
| **Linked List Search**   | O(1)      | O(n)         | O(n)       | O(1)             | Linked list data structures           |
| **Skip List Search**     | O(1)      | O(log n)     | O(log n)   | O(n)             | Large/sorted linked lists             |

## Summary

Each search algorithm has its unique characteristics, making it suitable for different scenarios. Linear search is
simple but inefficient for large datasets. Binary search is efficient for sorted datasets, while jump search offers a
balance for large, sorted lists. Interpolation search is highly efficient for uniformly distributed data, exponential
search is useful for large, sorted datasets where early matches are expected, linked list search is simple for linked
list structures, and skip list search provides efficient search operations for large, sorted linked lists.

Choosing the right algorithm depends on the data's size, distribution, and whether it is sorted. Understanding these
algorithms and their trade-offs can significantly improve the performance of search operations in various applications.