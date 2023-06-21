package _10_Sorting_Algorithms.Learn.Cycle_Sort;

import java.util.Arrays;

public class Cycle_Sort {
    public static void main(String[] args) {
        int[] arr = {3,5,1,4,2};
        CycleSort(arr);
        System.out.printf(Arrays.toString(arr));

    }

    public static void CycleSort(int[] arr){
        int i = 0;
        while(i < arr.length){
            int correct = arr[i] - 1;
            // check if the element at index i == i+1 or not. if not exchange with arr[value]-1 index
            if(arr[i] != arr[correct]){
                int temp = arr[i];
                arr[i] = arr[correct];
                arr[correct] = temp;
            } else{
                i++;
            }
        }
    }
}
