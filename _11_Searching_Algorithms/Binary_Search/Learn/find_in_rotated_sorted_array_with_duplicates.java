package _11_Searching_Algorithms.Binary_Search.Learn;

public class find_in_rotated_sorted_array_with_duplicates {
    public static void main(String[] args) {
        int[] arr = {8, 9, 10, 3, 4, 5, 6, 7};
        int target = 7;
        System.out.println(solution(arr, target));
    }

    public static boolean solution(int[] arr, int target) {
        int pivot = findPivotWithDuplicates(arr);
        if (pivot == -1) {
            return binarySearch(arr, target, 0, arr.length - 1) != -1;
        }
        if (arr[pivot] == target) {
            return true;
        }
        if (arr[0] > target) {
            return binarySearch(arr, target, pivot + 1, arr.length - 1) != -1;
        }
        return binarySearch(arr, target, 0, pivot - 1) != -1;
    }

    public static int binarySearch(int[] arr, int target, int start, int end) {
        while (start <= end) {
            int mid = (start + end) / 2;
            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }


    public static int findPivotWithDuplicates(int[] arr) {
        int start = 0;
        int end = arr.length - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;
            // same logic as without duplicate
            if (mid < end && arr[mid] > arr[mid + 1]) {
                return mid;
            }
            // same logic as without duplicate
            if (mid > start && arr[mid] < arr[mid - 1]) {
                return mid - 1;
            }

            // checking if start end and mid are same
            if (arr[start] == arr[mid] && arr[mid] == arr[end]) {
                // if start is greater than start+1 then it is the pivot
                if (arr[start] > arr[start + 1]) {
                    return start;
                }
                // if end-1 is greater than end than end-1 is the pivot
                if (arr[end] < arr[end - 1]) {
                    return end - 1;
                }
                // if both case fails then increase start and end to avoid duplicates
                start++;
                end--;
            }
            // if mid is greater than or equal to start and also greater than end then we from start to mid.
            else if (arr[start] <= arr[mid] && arr[mid] > arr[end]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return -1;
    }
}