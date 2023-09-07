package _11_Searching_Algorithms.Binary_Search.Practice;

public class _11_find_smallest_letter {
    public static char solution(char[] letters, char target) {
        int start = 0, end = letters.length-1;
        while(start<=end){
            int mid = start + (end-start) / 2;
            if(letters[mid] > target) end = mid-1;
            else start = mid + 1;
        }
        return letters[start%letters.length];       // if start becomes equal to length of array then it will return first element otherwise element of letters[start]

    }

    public static void main(String[] args) {
        char[] letters = {'c','f','j'};
        char target = 'k';
        System.out.println(solution(letters, target));
    }
}
