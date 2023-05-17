package Searching_Algorithms.Binary_Search.Learn;

public class peak_element_in_mountain_array {
    public static int solution(int[] arr){
        int start = 0, end = arr.length;
        while(start < end){
            int mid = start + (end-start)/2;
            if(arr[mid] < arr[mid+1]){      // if the mid-element is smaller then, we can subtract left side till mid.
                start = mid + 1;            // mid+1 because we don't mid as it's smaller than mid+1
            } else {
                end = mid;                  // here we need mid because as mid is greater than mid+1 it might be greatest in the array
            }
        }
        return arr[end];                    // both start and end points to the greatest so, we can return any one.
    }
    public static void main(String[] args) {
        int[] arr = {1,2,5,6,9,3,2};
        System.out.println(solution(arr));
    }
}