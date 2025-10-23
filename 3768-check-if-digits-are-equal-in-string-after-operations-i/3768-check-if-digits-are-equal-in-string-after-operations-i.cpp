class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();
        while(n != 2){
            int i= 1;
        
            while( i < n){
                s[i-1] = (((s[i]-'0') +(s[i-1]-'0'))%10) + '0';
                i++;
            }
            n--;

        }

        if(s[0] == s[1]) return true;
        return false;
    }
};