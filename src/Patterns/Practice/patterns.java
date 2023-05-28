package Patterns.Practice;

public class patterns {
    public static void main(String[] args) {
        pattern10(6);
    }

    static void pattern1(int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print("*" + " ");
            }
            System.out.println();
        }
    }

    static void pattern2(int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                System.out.print("*" + " ");
            }
            System.out.println();
        }
    }

    static void pattern3(int n) {
        for (int i = 0; i < n; i++) {
            for (int j = n - i; j > 0; j--) {
                System.out.print("*" + " ");
            }
            System.out.println();
        }
    }

    static void pattern4(int n) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print(j + " ");
            }
            System.out.println();
        }
    }

    static void pattern5(int n) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <=i; j++) {
                System.out.print("*" + " ");
            }
            System.out.println();

        }
        for (int i = n; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                System.out.print("*" + " ");
            }
            System.out.println();

        }
    }

    static void pattern6(int n) {

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n - i; j++) {
                System.out.print(" "+" ");
            }

            for (int k = 1; k <= i; k++) {
                System.out.print("*"+" ");
            }

            System.out.println();
        }

    }

    static void pattern7(int n) {

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j ++){
                System.out.print(" "+" ");
            }
            for(int k = n-i; k > 0; k--){
                System.out.print("*"+" ");
            }
            System.out.println();
        }

    }

    static void pattern8(int n) {

        for(int i = 0; i < n; i++){
            for(int j = n-i; j > 0 ; j --){
                System.out.print(" ");
            }
            for(int k = i*2+1; k > 0 ; k--){
                System.out.print("*");
            }
            System.out.println();
        }

    }

    static void pattern9(int n) {

        for(int i = n; i >= 0; i--){
            for(int j = n-i; j > 0 ; j --){
                System.out.print(" ");
            }
            for(int k = i*2+1; k > 0 ; k--){
                System.out.print("*");
            }
            System.out.println();
        }

    }

    static void pattern10(int n) {

        for(int i = 0; i < n; i++){
            for(int j = n-i; j > 0 ; j --){
                System.out.print(" ");
            }
            for(int k = i*2+1; k > 0 ; k--){
                if(k%2 == 0)
                    System.out.print(" ");
                else
                    System.out.print("*");
            }
            System.out.println();
        }

    }




}
