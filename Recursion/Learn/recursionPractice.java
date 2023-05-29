package Recursion.Learn;

public class recursionPractice {
    public static void main(String[] args) {
        printNum(5);
        System.out.println();
        printNum1(5);
    }

    static void printNum1(int n){
        System.out.println(n);
        printNum2(--n);
    }
    static void printNum2(int n){
        System.out.println(n);
        printNum3(--n);
    }
    static void printNum3(int n){
        System.out.println(n);
        printNum4(--n);
    }
    static void printNum4(int n){
        System.out.println(n);
        printNum5(--n);
    }
    static void printNum5(int n){
        System.out.println(n);
    }



    static void printNum(int n){
        if(n==0){
            return;
        }
        System.out.println(n);
        printNum(--n);
    }
}
