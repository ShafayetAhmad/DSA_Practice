package _11_Searching_Algorithms.Binary_Search.Learn;

public class orderAgnosticBS {
    public static int solution(int[] arr, int target){
        int start = 0, end = arr.length-1;
        boolean isAsc = (arr[start] < arr[end]); // checks if the array is in ascending order or not

        while(start <= end){
            int mid = (start+end)/2;    // for large integer {int mid = start+(end-start)/2

            if(arr[mid] == target) {
                return mid;
            }
            // if array in ascending/increasing order this code executes
            if(isAsc){
                if(arr[mid] < target){
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
            // if array in descending/decreasing order this code executes
            else {
                if(arr[mid] > target){
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
    public static void main(String[] args) {
        int[] arr = {-76,-45, -10, 0, 2,5,6,7,8,11,14,23,45};
        int target = 11;
        System.out.println(solution(arr, target));
    }
}
