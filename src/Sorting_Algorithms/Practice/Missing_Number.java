package Sorting_Algorithms.Practice;

public class Missing_Number {
    public static void main(String[] args) {
        int[] arr = {2,4,0,1};
        System.out.println(missingNumber(arr));


    }

    static int missingNumber(int[] nums){
        int i = 0;
        int correct = nums[i];
        while (i < nums.length){
            if(nums[i] < nums.length && nums[i] != nums[correct]){
                int temp = nums[i];
                nums[i] = nums[correct];
                nums[correct] = temp;
            } else{
                i++;
            }
        }
        for (int j = 0; j < nums.length; j++){
            if(nums[j] != j){
                return j;
            }
        }
        return nums.length;
    }
}
