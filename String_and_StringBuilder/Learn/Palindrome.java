package String_and_StringBuilder.Learn;

public class Palindrome {
    public static void main(String[] args) {
        String s = "A man, a plan, a canal: Panama";
        // converts to lowercase then replaces every char other than a-z and 0-9 with "".
        s = s.toLowerCase().replaceAll("[^a-z0-9]", "");
        String reversed = new StringBuilder(s).reverse().toString();
        System.out.println(s.equals(reversed));
    }
}