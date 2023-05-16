package Searching_Algorithms.Binary_Search.Learn;

public class ceiling_of_a_number {

    // for finding ceiling the loop will continue with the condition < only and right = mid. because even if mid>target, mid might be ceiling.
    public static int solution(int[] arr, int target){
        int left = 0;
        int right = arr.length-1;
        while(left < right){
            int mid = (left+right)/2;
            if(arr[mid] == target){
                return mid;
            } else if(arr[mid] < target){
                left = mid+1;
            } else{
                right = mid;
            }
        }
        return right;
    }
    public static void main(String[] args) {
        int[] arr = {2,3,5,9,14,16,18};
        System.out.println(solution(arr, 15));
    }
}

