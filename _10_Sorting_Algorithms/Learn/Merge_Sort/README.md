
The algorithm follows these steps:

1. Divide: The input array is divided into two roughly equal halves.
2. Conquer: Recursively sort each half of the divided array by applying the merge sort algorithm.
3. Combine: Merge the two sorted halves back together by comparing elements from each half and placing them in the correct order in a new array.

The divide step continues recursively until individual elements are obtained (i.e., the array size becomes 1). Then, the conquer step kicks in, sorting the individual elements trivially. The combine step merges the sorted subarrays by comparing elements from both halves and placing them in the correct order.

The key operation in Merge Sort is the merge operation, where two sorted subarrays are merged to form a larger sorted array. This operation requires additional space to store the merged result temporarily. After merging, the result is copied back to the original array.

Merge Sort has a time complexity of O(n log n), where n is the number of elements in the input array. It guarantees stable sorting and performs well even for large datasets. However, it requires additional space proportional to the size of the input array, which can be a drawback when dealing with limited memory.