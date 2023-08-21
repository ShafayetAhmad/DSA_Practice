The Knuth-Morris-Pratt (KMP) algorithm is a string searching algorithm that efficiently finds occurrences of a substring (pattern) within a longer string (text). It improves upon the naive approach of string matching by utilizing the information gained from previous comparisons to avoid unnecessary backtracking.

Here's how the KMP algorithm works:

1. Preprocessing (Building the Partial Match Table):

   - The KMP algorithm constructs a partial match table (also called the "failure function" or "lps" array) for the pattern.
   - The partial match table stores information about the longest proper prefix (which is also a suffix) of the pattern that matches a substring ending at the current position.

2. Searching:
   - Start comparing the pattern with the text from the beginning.
   - If a mismatch occurs, instead of starting the comparison from the beginning of the pattern, the KMP algorithm uses the information from the partial match table to determine where the next comparison should start. This avoids unnecessary comparisons.
   - The algorithm then continues comparing characters until either a match is found or the end of the pattern is reached.

KMP Algorithm's Time Complexity: O(n + m), where n is the length of the text and m is the length of the pattern.

Here are some LeetCode problems that involve the KMP algorithm:

1. **LeetCode 28. Implement strStr()**
   - Problem: Return the index of the first occurrence of the pattern (needle) within the text (haystack), or -1 if the pattern is not present.
   - This problem essentially asks for a simple implementation of the KMP algorithm.
2. **LeetCode 459. Repeated Substring Pattern**

   - Problem: Given a non-empty string, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.
   - This problem can be solved using the KMP algorithm by observing that if a string can be formed by repeating a substring, then the pattern's length should be a divisor of the string's length.

3. **LeetCode 1392. Longest Happy Prefix**

   - Problem: Given a string, find the longest prefix that is also a suffix of the input string.
   - This problem can be solved using the KMP algorithm by building the partial match table for the string itself.

4. **LeetCode 1044. Longest Duplicate Substring**
   - Problem: Given a string, find the longest substring that occurs at least twice in the string.
   - This problem involves finding a repeated substring, and it can be solved using the KMP algorithm along with binary search.

Remember that while KMP is a powerful algorithm for string matching, it might not be the first choice for all string-related problems. It's important to understand the algorithm and its applications to choose the right approach for each problem.
