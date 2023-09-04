package _01_Arrays.Practice;

//27.Remove Element
//Given an integer array nums and an integer val,remove all occurrences of val in nums in-place.The order of the elements may be changed.Then return the number of elements in nums which are not equal to val.
//
//Consider the number of elements in nums which are not equal to val be k,to get accepted,you need to do the following things:
//
//Change the array nums such that the first k elements of nums contain the elements which are not equal to val.The remaining elements of nums are not important as well as the size of nums.
//Return k.
//https://leetcode.com/problems/remove-element/description/

class _27_Remove_Element {

    public static void main(String[] args) {
        int[] arr = {0, 1, 2, 2, 3, 0, 4, 2};
        printArr(arr, removeElement(arr, 2));
    }

    public static int removeElement(int[] nums, int val) {
        int count = 0;
        for (int num : nums) {
            if (num == val) {
                continue;
            } else {
                nums[count++] = num;
            }
        }
        return count;
    }

    public static void printArr(int[] arr, int size) {
        for (int i = 0; i < size; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}