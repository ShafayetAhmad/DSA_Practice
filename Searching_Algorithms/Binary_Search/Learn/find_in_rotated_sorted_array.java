package Searching_Algorithms.Binary_Search.Learn;

public class find_in_rotated_sorted_array {
    public static void main(String[] args) {
        int[] arr = {8,9,10,3,4,5,6,7};
        int target = 7;
        System.out.println(solution(arr, target));
    }

    public static int solution(int[] arr, int target){
        int pivot = findPivot(arr);
        if(pivot == -1){
            // array is not rotated at all
            return binarySearch(arr, target, 0, arr.length-1);
        }
        if(arr[pivot] == target){
            return pivot;
        }
        // if first element is greater than target then we don't need to search in start to pivot.
        if(arr[0] > target){
            return binarySearch(arr, target, pivot+1, arr.length-1);
        }
        // // as arr[0] is smaller than equal to target we need to only search from start till pivot -1.
        return binarySearch(arr, target, 0, pivot-1);
    }

    public static int binarySearch(int[] arr, int target, int start, int end){
        while(start <= end){
            int mid = (start+end)/2;    // for large integer {int mid = start+(end-start)/2
            if(arr[mid] == target){
                return mid;
            } else if(arr[mid] < target){
                start = mid+1;
            } else {
                end = mid-1;
            }
        }
        return -1;
    }

    public static int findPivot(int[] arr){
        int start = 0, end = arr.length-1;
        while(start < end){
            int mid = start + (end - start)/2;

            // for array 7 9 10 4 5 6 mid-element is 10, and it's strictly greater than the next element 4
            if(mid < end && arr[mid] > arr[mid+1]){
                return mid;
            }
            // for array 7 9 10 2 3 4 5 6 mid-element is 2, and it's strictly smaller than the next element 10
            if(mid > start && arr[mid] < arr[mid-1]){
                return mid-1;
            }
            // if mid-element is smaller than or equal to first ele ment then we don't need elements mid to end
            if(arr[start] >= arr[mid]){
                end = mid - 1;
            }
            // if mid-element is greater than first element then we don't need elements from start to mid.
            // note: we don't need the mid also because if it was pivot/important then it would have been caught in first condition
            else{
                start = mid + 1;
            }
        }
        return -1;
    }
}