package Searching_Algorithms.Binary_Search.Learn;

public class InfiniteArrayBS {
    public static int solution(int[] arr, int target){
        int start = 0;
        int end = 1;

        // increasing the size of the window exponentially
        while(arr[end]<target){
            int newStart = end+1;
            end = end + (end - start + 1) * 2;
            start = newStart;
        }
        return BinarySearch(arr, target, start, end);
    }

    public static int BinarySearch(int[] arr, int target, int start, int end){
        while(start < end){
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
    public static void main(String[] args) {
        int[] arr = {3, 5, 7, 9, 10, 90,
                100, 130, 140, 160, 170};
        System.out.println(solution(arr, 10));
    }
}