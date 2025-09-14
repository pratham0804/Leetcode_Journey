class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int starIdx = -1, match = 0;

        while (i < s.size()) {
            // If characters match or pattern has '?'
            if (j < p.size() && (p[j] == s[i] || p[j] == '?')) {
                i++; j++;
            }
            // If pattern has '*'
            else if (j < p.size() && p[j] == '*') {
                starIdx = j;
                match = i;
                j++;
            }
            // If mismatch but previous char was '*'
            else if (starIdx != -1) {
                j = starIdx + 1;
                match++;
                i = match;
            }
            // If no match and no previous '*'
            else {
                return false;
            }
        }
        // Check for remaining '*' in pattern
        while (j < p.size() && p[j] == '*') {
            j++;
        }
        return j == p.size();
    }
};