package _02_Recursion_and_Backtracking.Learn;

public class fibonacciUsingRecursion {
    public static void main(String[] args) {
        System.out.println(fib(6));
    }

    static int fib(int n){
        if(n==0 || n== 1){
            return n;
        }
        return fib(n-1)+fib(n-2);
    }
}


