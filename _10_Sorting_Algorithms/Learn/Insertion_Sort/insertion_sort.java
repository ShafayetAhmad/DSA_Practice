package _10_Sorting_Algorithms.Learn.Insertion_Sort;

import java.util.Arrays;

public class insertion_sort {
    public static void main(String[] args) {
        int[] arr = {4,7,3,1,8};
        insertion_sort_algo(arr);
        System.out.println(Arrays.toString(arr));
    }

    public static void insertion_sort_algo(int[] arr){
        for(int i = 0; i < arr.length-1; i++){
            for(int j = i+1; j > 0; j--){
                if(arr[j-1] < arr[j]){
                    // because prev part is already sorted
                    break;
                }
                    int temp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = temp;
            }
        }
    }
}
