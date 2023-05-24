package RandomPractice;

import java.util.Arrays;

public class IncrementLargeInteger {
    public static int[] plusOne(int[] digits) {
        int n = digits.length;

        // Iterate through the digits in reverse order
        for (int i = n - 1; i >= 0; i--) {
            // Increment the current digit by 1
            digits[i]++;

            // If the digit becomes 10, set it to 0 and carry over the 1
            if (digits[i] == 10) {
                digits[i] = 0;
            } else {
                // If the digit is less than 10, no need to carry over, so return the digits array
                return digits;
            }
        }

        // If all digits were 9 and we need to carry over to a new digit
        int[] newDigits = new int[n + 1];
        newDigits[0] = 1;

        return newDigits;
    }

    public static void main(String[] args) {
        int[] digits = {1, 2, 9};
        int[] result = plusOne(digits);

        System.out.println("Result: " + Arrays.toString(result));
    }
}
