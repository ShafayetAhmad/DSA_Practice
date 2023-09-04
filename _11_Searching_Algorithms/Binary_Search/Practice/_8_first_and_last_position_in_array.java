package _11_Searching_Algorithms.Binary_Search.Practice;

import java.util.Arrays;

public class _8_first_and_last_position_in_array {
    public static int[] solution(int[] arr, int target){
        int[] ans = {-1,-1};
        ans[0] = findOcc(arr, target,true);     // find floor of a number
        ans[1] = findOcc(arr, target, false);   // find ceil of a number
        return ans;
    }

    public static int findOcc(int[] arr,int target,boolean isFirstOcc){
        int left = 0, right = arr.length;
        int ans = -1;
        while(left <= right){
            int mid = (left+right)/2;
            if(arr[mid] == target){
                ans = mid;
                if(isFirstOcc){
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if(arr[mid] < target){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
    public static void main(String[] args) {
        int[] arr = {2,5,7,8,8,8,9,13};
        int target = 8;
        System.out.println(Arrays.toString(solution(arr, target)));
    }
}
