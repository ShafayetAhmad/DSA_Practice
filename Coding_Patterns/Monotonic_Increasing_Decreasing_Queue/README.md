Sure, here's a brief explanation of both monotonic increasing and decreasing queues:

 **Monotonic Increasing Queue:**

   A monotonic increasing queue, often referred to as a "deque" (double-ended queue), is a data structure that maintains a queue of elements in such a way that the elements are in non-decreasing order from front to back. This means that the front of the queue holds the smallest element, and the elements get progressively larger towards the back. Monotonic increasing queues are commonly used to efficiently find the maximum element within a sliding window as you can pop elements from the back that are smaller than the current element, ensuring that the maximum remains at the front.

 **Monotonic Decreasing Queue:**

   Similarly, a monotonic decreasing queue is a data structure that maintains a queue of elements in non-increasing order from front to back. The front of the queue holds the largest element, and the elements decrease in value towards the back. Monotonic decreasing queues are useful for efficiently finding the minimum element within a sliding window. Similar to the increasing queue, elements that are smaller than the current element can be popped from the back, maintaining the minimum at the front.

Both types of monotonic queues are useful for solving various problems that involve sliding windows and optimizing element retrieval within those windows. By keeping the elements in a sorted order, you can avoid unnecessary comparisons and achieve better time complexity for specific types of problems.
1. [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/): Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
2. [Sliding
