class Solution {
public:
    int myAtoi(std::string s) {
        int i = 0, sign = 1, result = 0;

         // Step 1: Ignore leading spaces
        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        // Step 2: Check for '+' or '-'
        if (i < s.length() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Convert digits to integer
        while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';

            // Step 4: Check for overflow
            if (result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return result * sign;
    }
};