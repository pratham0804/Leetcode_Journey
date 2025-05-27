import java.util.ArrayList;

class Solution {
    public boolean isPalindrome(String s) {
        int l = s.length();
        char str[] = s.toCharArray();
        ArrayList<Character> al = new ArrayList<Character>();

        if (l == 1) return true;

        for (int i = 0; i < l; i++) {
            if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')|| (str[i]>='0'&&str[i]<='9')) {
                char c = Character.toLowerCase(str[i]);
                al.add(c);
            }
        }

        if (al.isEmpty()) return true; // Handle the case of an empty string

        for (int i = 0, j = al.size() - 1; i < al.size() && j >= 0; i++, j--) {
            if (al.get(i) == al.get(j)) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
}
