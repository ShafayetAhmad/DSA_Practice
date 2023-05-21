package Sorting_Algorithms.Bubble_Sort;

import java.util.Arrays;

public class bubble_sort {
    public static void main(String[] args) {
        int[] arr = {1,2,3,8,5};
        bubbleSort(arr);
        System.out.println(Arrays.toString(arr));
    }

    public static void bubbleSort(int[] arr){
        for(int i = 0; i < arr.length; i++){
            boolean swapped = false;
            // this will run until last element sorted.
            for(int j = 1; j < arr.length-i; j++){
                // will swap two adjacent element if first element is greater than second element.
                if(arr[j-1] > arr[j]){
                    int temp = arr[j-1];
                    arr[j-1] = arr[j];
                    arr[j] = temp;
                    swapped = true;
                }
            }
            // if any time the inner loop doesn't swaps any elements that means the array is sorted hence break.
            if(!swapped){
                break;
            }
        }
    }
}
