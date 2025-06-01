class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.size() % 2 != 0) 
            return false;

        int open_count = 0, close_count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (locked[i] == '0' || s[i] == '(')
                open_count++;
            else
                open_count--;
            if (open_count < 0)
                return false;
        }

        open_count = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (locked[i] == '0' || s[i] == ')')
                close_count++;
            else
                close_count--;
            if (close_count < 0)
                return false;
        }

        return true;
    }
};