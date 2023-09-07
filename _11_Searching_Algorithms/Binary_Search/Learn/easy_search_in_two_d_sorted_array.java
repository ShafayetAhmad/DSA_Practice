package _11_Searching_Algorithms.Binary_Search.Learn;

import java.util.Arrays;

public class easy_search_in_two_d_sorted_array {
    public static void main(String[] args) {
        int[][] mat = {
                {1, 2, 3, 4},
                {5, 6, 7, 8},
                {9, 10,11,12},
                {13,14,15,16}
        };

        System.out.println(Arrays.toString(searchMatrix(mat,10)));
    }

    // we treat the 2d array as a 1d array
    public static int[] searchMatrix(int[][] mat, int target){
        int rowSize = mat.length;
        int colSize = mat[0].length;
        int start = 0;
        // the end of the 1d array
        int end = rowSize*colSize-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            // mid/colSize gives row and mid%colSize gives column
            int midValue = mat[mid/colSize][mid%colSize];
            if(midValue == target){
                return new int[]{mid/colSize, mid%colSize};
            } else if(midValue < target){
                start = mid+1;
            } else {
                end = mid-1;
            }
        }
        // not found
        return new int[]{-1,-1};
    }
}
