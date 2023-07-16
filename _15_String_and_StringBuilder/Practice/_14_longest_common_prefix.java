package _15_String_and_StringBuilder.Practice;

public class _14_longest_common_prefix {

    public static void main(String[] args) {
        String[] strs = {"flowers", "flow", "flight"};
        System.out.println(longestCommonPrefix(strs));
    }
    public static String longestCommonPrefix(String[] strs) {
        StringBuilder result = new StringBuilder();

        for (int i = 0; i < strs[0].length(); i++) {
            char ch = strs[0].charAt(i);

            for (String str : strs) {
                if (i >= str.length() || str.charAt(i) != ch) {
                    return result.toString();
                }
            }
            result.append(ch);
        }
        return result.toString();
    }
}
