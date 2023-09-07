package _02_Recursion_and_Backtracking.Learn;

public class binarySeachUsingRecursion {
    public static void main(String[] args) {
        int[] arr = {4,8,2,3,6,9,0,2};
        System.out.println(recursionBS(arr,0,arr.length,0));
    }
    static int recursionBS(int[] arr, int start, int end, int target){
        if(start > end){
            return -1;
        }
        int mid = start + (end-start)/2;
        if(arr[mid] == target){
            return mid;
        }
        if(target < arr[mid]){
            return recursionBS(arr,mid+1,end,target);
        }
        return recursionBS(arr,start,mid-1,target);
    }
}
