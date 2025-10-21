# 📚 Data Structures & Algorithms (DSA) with LeetCode Solutions

This repository contains a topic-wise collection of DSA problems and LeetCode solutions implemented primarily in C++.  
Each folder groups problems by data structure or algorithm pattern so you can study, run, and extend solutions easily.

---

## ✅ Objectives

- Build a strong foundation in core DSA concepts
- Solve LeetCode problems topic-wise with multiple approaches
- Prepare for coding interviews and competitive programming

---

## Repository Structure (top-level)
- [1. DSA fundamentals](1.%20DSA%20fundamentals/)  
- [2. Sorting](2.%20Sorting/)  
- [3. Two Pointers](3.%20Two%20Pointers/)  
- [5. Matrixs](5.%20Matrixs/)  
- [8. Linked List](8.%20Linked%20List/)  
- [9. Stack](9.%20Stack/)  
- [10. Queue](10.%20Queue/)  
- [14. Binary Tree](14.%20Binary%20Tree/)  
- [15. Binary Search Tree](15.%20Binary%20Search%20Tree/)  
- [16. Heap(Priority Queue)](16.%20Heap(Priority%20Queue)/)  
- [19. Dynamic Programming](19.%20Dynamic%20Programming/)  
- [20. Graphs](20.%20Graphs/)  
(Full folder list available in the repo root.)

---

## Quick links — notable implementations
- Arrays / fundamentals
  - [`insertAtPosition`](1.%20DSA%20fundamentals/Arrays_Basics.cpp), [`deleteElementAtIndex`](1.%20DSA%20fundamentals/Arrays_Basics.cpp) — [1. DSA fundamentals/Arrays_Basics.cpp](1.%20DSA%20fundamentals/Arrays_Basics.cpp)

- Queue implementations
  - Stack using queue(s): [`MyStack1`](10.%20Queue/1.%20Implementation%20Problem/LeetCode_225.cpp), [`MyStack2`](10.%20Queue/1.%20Implementation%20Problem/LeetCode_225.cpp) — [10. Queue/1. Implementation Problem/LeetCode_225.cpp](10.%20Queue/1.%20Implementation%20Problem/LeetCode_225.cpp)
  - Queue using stacks: [`MyQueue`](10.%20Queue/1.%20Implementation%20Problem/LeetCode_232.cpp) — [10. Queue/1. Implementation Problem/LeetCode_232.cpp](10.%20Queue/1.%20Implementation%20Problem/LeetCode_232.cpp)

- Binary Search Tree
  - Delete node in BST: [`deleteNode`](15.%20Binary%20Search%20Tree/1.%20Basic%20Operations/Leetcode_450.cpp) — [15. Binary Search Tree/1. Basic Operations/Leetcode_450.cpp](15.%20Binary%20Search%20Tree/1.%20Basic%20Operations/Leetcode_450.cpp)
  - BST → Greater Sum Tree: [`Helper` / `bstToGst`](15.%20Binary%20Search%20Tree/2.%20Construction%20of%20BST/Leetcode_1038.cpp) — [15. Binary Search Tree/2. Construction of BST/Leetcode_1038.cpp](15.%20Binary%20Search%20Tree/2.%20Construction%20of%20BST/Leetcode_1038.cpp)

- Matrix transformations
  - Rotate image (in-place): [`Solution::rotate`](5.%20Matrixs/Transformation%20and%20modification/LeetCode_48.cpp) — [5. Matrixs/Transformation and modification/LeetCode_48.cpp](5.%20Matrixs/Transformation%20and%20modification/LeetCode_48.cpp)

- Array / Two pointers
  - Rotate array (in-place): [`Solution2::rotate`](3.%20Two%20Pointers/On%20Arrays/LeetCode_189.cpp) — [3. Two Pointers/On Arrays/LeetCode_189.cpp](3.%20Two%20Pointers/On%20Arrays/LeetCode_189.cpp)
  - Merge frequency arrays: [`mergeArrays`](3.%20Two%20Pointers/On%20Arrays/LeetCode_2570.cpp) — [3. Two Pointers/On Arrays/LeetCode_2570.cpp](3.%20Two%20Pointers/On%20Arrays/LeetCode_2570.cpp)

- Dynamic Programming
  - Climbing stairs (multiple solutions): [`Solution1::climbStairs`], [`Solution3::climbStairs`] — [19. Dynamic Programming/Leetcode_70.cpp](19.%20Dynamic%20Programming/Leetcode_70.cpp)

---

## How to build & run a single file (example)
Compile and run any C++ file with g++:
```sh
g++ "3. Two Pointers/On Arrays/LeetCode_189.cpp" -std=c++17 -O2 -o out && ./out
```
Adjust path and filename for the solution you want to test.

---

## Contribution & testing tips
- Add a short comment header for any new file describing problem, constraints and expected complexity (pattern used throughout repo).
- Keep main/test harness code near the bottom of the file and guarded or separated for easy compilation.
- Run valgrind or sanitizers when debugging memory issues:
```sh
g++ -fsanitize=address,undefined -g file.cpp && ./a.out
```

---

## 🔥 Upcoming
- More problem variants per topic
- Detailed approach notes and complexity annotations
- Small unit-test harnesses for frequent problems

---

If you want, I can directly commit this updated README content to [readme.md](readme.md) or adjust the Quick Links to highlight different files/classes.
