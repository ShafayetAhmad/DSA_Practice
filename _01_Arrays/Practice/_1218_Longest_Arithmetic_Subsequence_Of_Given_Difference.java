package _01_Arrays.Practice;

import java.util.*;
public class _1218_Longest_Arithmetic_Subsequence_Of_Given_Difference {
    public static void main(String[] args) {
        int[] arr = {1,5,7,8,5,3,4,2,1};
        System.out.println(longestSubsequence(arr,-1));
    }
    public static int longestSubsequence(int[] arr, int diff) {
        Map<Integer, Integer> map = new HashMap<>();
        int res = 1;
        for (int num : arr) {
            int prev = map.getOrDefault(num - diff, 0);
            map.put(num, prev + 1);
            res = Math.max(map.get(num), res);
        }
        return res;
    }
}
