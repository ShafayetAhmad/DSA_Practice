package RandomPractice;

public class word_pattern {
    public static void main(String[] args) {
        String pattern = "abba";
        String str = "dog cat cat dog";
        System.out.println(wordPattern(pattern, str));
    }

    public static boolean wordPattern(String pattern, String str) {
        String[] words = str.split(" ");
        if (words.length != pattern.length())
            return false;
        String[] map = new String[26];
        for (int i = 0; i < pattern.length(); i++) {
            int index = pattern.charAt(i) - 'a';
            if (map[index] == null) {
                if (contains(map, words[i]))
                    return false;
                map[index] = words[i];
            } else {
                if (!map[index].equals(words[i]))
                    return false;
            }
        }
        return true;
    }

    public static boolean contains(String[] map, String word) {
        for (String s : map) {
            if (s != null && s.equals(word))
                return true;
        }
        return false;
    }
}
