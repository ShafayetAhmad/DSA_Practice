package String_and_StringBuilder.Practice;

import java.util.Scanner;

public class stringpractice {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num;
        String str;
        num = sc.nextInt();
        str = sc.nextLine();  // it will take the enter key as input hence it will not take the string input

        System.out.println(num+" "+str);
        sc.close();
    }
}
