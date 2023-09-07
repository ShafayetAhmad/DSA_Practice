Prefix sum is a technique used to efficiently compute the sum of elements within a specified range in an array. It involves preprocessing the array to generate a prefix sum array, where each element at index `i` stores the cumulative sum of elements from index 0 to `i` in the original array. This allows for quick calculation of the sum of elements within a range `[left, right]` using the formula `prefixSum[right + 1] - prefixSum[left]`. This technique is beneficial for scenarios requiring frequent range sum queries on the same array, reducing the time complexity from linear to constant time for each query.

Certainly! Here are some problems related to both monotonic increasing and decreasing queues:

**Monotonic Increasing Queue (Deque):**

1. **Sliding Window Maximum:** [LeetCode Problem 239](https://leetcode.com/problems/sliding-window-maximum/)
   - Given an array `nums` and an integer `k`, find the maximum value in each sliding window of size `k`.

2. **Next Greater Element II:** [LeetCode Problem 503](https://leetcode.com/problems/next-greater-element-ii/)
   - Given a circular array `nums`, find the next greater element for each element in the array.

3. **Trapping Rain Water:** [LeetCode Problem 42](https://leetcode.com/problems/trapping-rain-water/)
   - Given an array representing the heights of walls, calculate how much rainwater can be trapped after a rainfall.

4. **Constrained Subsequence Sum:** [LeetCode Problem 1425](https://leetcode.com/problems/constrained-subsequence-sum/)
   - Given an array of integers and an integer `k`, find the maximum sum of any non-empty subsequence such that for every `x` in the subsequence, `x + k` is not in the subsequence.

**Monotonic Decreasing Queue (Deque):**

1. **Maximum of Minimums in All Subarrays:** [LeetCode Problem 907](https://leetcode.com/problems/sum-of-subarray-minimums/)
   - Given an array `nums` and an integer `k`, find the maximum value among the minimum values of all contiguous subarrays of size `k`.

2. **Longest Subarray with At Most Two Distinct Elements:** [LeetCode Problem 159](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/)
   - Find the length of the longest subarray with at most two distinct elements.

3. **Number of Subarrays with Bounded Maximum:** [LeetCode Problem 795](https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/)
   - Given an array `nums` and two boundaries `L` and `R`, count the number of contiguous subarrays where the maximum element is between `L` and `R`.

4. **Online Stock Span:** [LeetCode Problem 901](https://leetcode.com/problems/online-stock-span/)
   - Given a stream of stock prices, calculate the span of stock's price for each day. The span is defined as the maximum number of consecutive days (including the current day) that the price is less than or equal to today's price.

