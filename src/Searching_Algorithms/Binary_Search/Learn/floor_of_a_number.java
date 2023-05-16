package Searching_Algorithms.Binary_Search.Learn;

public class floor_of_a_number {
    public static int solution(int[] arr, int target){
        int left = 0;
        int right = arr.length-1;
        if(arr[left]>target){
            return -1;          // no floor as first element is greater than target
        }

        while(left <= right){
            int mid = (left+right)/2;
            if(arr[mid] == target){
                return mid;
            } else if(arr[mid] < target){
                left = mid+1;
            } else{
                right = mid-1;
            }
        }
        return right;       // same as ceiling of a number only for floor, we return right
    }
    public static void main(String[] args) {
        int[] arr = {2,3,5,9,14,16,18};
        System.out.println(solution(arr, 15));
    }
}
