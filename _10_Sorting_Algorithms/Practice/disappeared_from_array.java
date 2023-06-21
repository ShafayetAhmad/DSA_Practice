package _10_Sorting_Algorithms.Practice;
import java.util.*;

class disappeared_from_array {

    public static void main(String[] args) {
        int[] arr = {4,3,2,7,8,2,3,1};
        findDisappearedNumbers(arr);
        System.out.println(findDisappearedNumbers(arr));
    }
    static List<Integer> findDisappearedNumbers(int[] nums) {
        int i = 0;
        while(i < nums.length){
            int correct = nums[i] - 1;
            if(nums[i] != nums[correct]){
                int temp = nums[i];
                nums[i] = nums[correct];
                nums[correct] = temp;
            } else{
                i++;
            }
        }
        List<Integer> ans = new ArrayList<Integer>();
        for(i = 0; i < nums.length; i++){
            if(nums[i] != i+1){
                ans.add(i+1);
            }
        }
        return ans;
    }
}