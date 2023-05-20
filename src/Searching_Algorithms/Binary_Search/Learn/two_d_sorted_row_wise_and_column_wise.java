package Searching_Algorithms.Binary_Search.Learn;

public class two_d_sorted_row_wise_and_column_wise {
    public static void main(String[] args) {
        int[][] arr= {
                {10, 20, 30, 40},
                {15, 25, 35, 45},
                {27, 29, 37, 48},
                {32, 33, 39, 50}
        };
        System.out.println(search(arr, 10));

    }

    public static boolean search(int[][] arr, int target){
        int row = 0, col = arr.length-1;
        while(row <= arr[0].length-1  && col >= 0){
            if(arr[row][col] == target){
                System.out.println(row+" "+col);
                return true;
            } else if(arr[row][col] > target){
                col--;
            } else{
                row++;
            }
        }
        return false;
    }
}
