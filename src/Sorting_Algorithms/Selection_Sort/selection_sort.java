package Sorting_Algorithms.Selection_Sort;

import java.util.Arrays;

public class selection_sort {
    public static void main(String[] args) {
        int[] arr = {7,6,4,3,2,1};
        selection_sort_algo(arr);
        System.out.println(Arrays.toString(arr));

    }

    public static void selection_sort_algo(int[] arr){
        for(int i = 0; i < arr.length-1; i++){
            int j = i+1, smallest = i;

            // this loop is used to select the smallest element
            while(j < arr.length){
                if(arr[j] < arr[smallest]){
                    smallest = j;
                }
                j++;
            }
            // swap the smallest element with first element
            int temp = arr[i];
            arr[i] = arr[smallest];
            arr[smallest] = temp;
        }
    }
}
