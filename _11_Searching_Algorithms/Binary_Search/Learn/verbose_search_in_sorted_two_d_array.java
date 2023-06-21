package _11_Searching_Algorithms.Binary_Search.Learn;

import java.util.Arrays;

public class verbose_search_in_sorted_two_d_array {
    public static void main(String[] args) {
        int[][] mat = {
                {1, 2, 3, 4},
                {5, 6, 7, 8},
                {9, 10,11,12},
                {13,14,15,16}
        };

        System.out.println(Arrays.toString(searchMatrix(mat,10)));
    }

    public static int[] searchMatrix(int[][] mat, int target){
        int rStart = 0;
        int rEnd = mat.length-1;
        int cStart = 0;
        int cEnd = mat[0].length-1;
        int cMid = (cEnd-cStart)/2;

        // loop will stop with two rows remaining
        while(rStart < rEnd-1){
            int rMid = rStart + (rEnd-rStart)/2;

            if(mat[rMid][cMid] == target){
                return new int[]{rMid,cMid};
            } else if(mat[rMid][cMid] < target){
                rStart = rMid;
            } else{
                rEnd = rMid;
            }
        }

        // only two rows remaining

        // check first rows mid
        if(mat[rStart][cMid] == target){
            return new int[]{rStart, cMid};
        }
        // check left of first row mid.
        int[] check = binarySearch(mat ,target,0, cMid-1, rStart );
        if(check[0]!=-1) return check;

        // check right side of first row mid.
        check = binarySearch(mat ,target,cMid+1, cEnd, rStart );
        if(check[0]!=-1) return check;

        // check last row mid
        if(mat[rEnd][cMid] == target){
            return new int[]{rStart, cMid};
        }
        // check left of second row mid.
        check = binarySearch(mat ,target,0, cMid-1, rEnd );
        if(check[0]!=-1) return check;

        // check right of second row mid.
        check = binarySearch(mat ,target,cMid+1, cEnd, rEnd );
        if(check[0]!=-1) return check;

        // element not found
        return new int[]{-1,-1};
    }

    public static int[] binarySearch(int[][] mat, int target, int cStart, int cEnd, int row){
        while(cStart <= cEnd){
            int mid = cStart+(cEnd-cStart)/2;
            if(mat[row][mid] == target){
                return new int[]{row,mid};
            } else if(mat[row][mid] < target){
                cStart = mid + 1;
            } else{
                cEnd = mid - 1;
            }
        }
        return new int[]{-1,-1};
    }
}
