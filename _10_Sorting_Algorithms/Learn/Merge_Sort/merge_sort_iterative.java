package _10_Sorting_Algorithms.Learn.Merge_Sort;
import java.util.Arrays;

public class merge_sort_iterative {
    public static void main(String[] args) {
        int[] arr = {5, 4, 3, 2, 1, 0};
        mergeSortIterative(arr);
        System.out.println("Sorted Array: "+ Arrays.toString(arr));
    }

    static void mergeSortIterative(int[] arr) {
        int n = arr.length;
        for (int curr_size = 1; curr_size <= n-1; curr_size *= 2) {
            for (int left_start = 0; left_start < n-1; left_start += 2*curr_size) {
                int mid = Math.min(left_start + curr_size - 1, n-1);
                int right_end = Math.min(left_start + 2*curr_size - 1, n-1);
                merge(arr, left_start, mid, right_end);
            }
        }
    }

    static void merge(int[] arr, int l, int mid, int r) {
        int[] temp = new int[r-l+1];
        int i = l, j = mid+1, k = 0;
        while (i <= mid && j <= r) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            }
            else {
                temp[k++] = arr[j++];
            }
        }
        while (i <= mid) {
            temp[k++] = arr[i++];
        }
        while (j <= r) {
            temp[k++] = arr[j++];
        }
        for (i = l; i <= r; i++) {
            arr[i] = temp[i-l];
        }
    }
}
