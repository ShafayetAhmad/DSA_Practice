package _11_Searching_Algorithms.Binary_Search.Learn;

public class easy_finding_pivot_in_rotated_sorted_array {

    // this method is used to find minimum in rotated sorted array but, we can
    // use this to find pivot in rotated array also as minimum element = pivot+1 element

    public int easyFindPivot(int[] nums) {
        int left = 0, right = nums.length-1;
        while(left < right){
            int mid = (right-left)/2 + left;
            if(nums[mid] < nums[right]){
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return nums[left];
    }
    public static int easyFindPivotWithDuplicate(int[] nums){
        int left = 0, right = nums.length-1;
        while(left < right){
            int mid = (right-left)/2 + left;
            if(nums[mid] == nums[right]){
                right--;
            }
            else if(nums[mid] < nums[right]){
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left == 0 ? nums.length-1 : left - 1;
    }
}
