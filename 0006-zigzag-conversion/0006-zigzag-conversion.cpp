class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        int val = 2 * numRows - 2;
        if(val == 0) return s;
        string ans = "";
        for(int i=0; i<n; i+=val){
            ans += s[i];
        }
        for(int i=1; i<numRows-1; i++){
            bool flag = true;
            int j = i;
            while(j < n){
                ans += s[j];
                if(flag){
                    flag = false;
                    j += val - (i * 2);
                }
                else {
                    flag = true;
                    j += i * 2;
                }
            }
        }
        for(int i=numRows-1; i<n; i+=val){
            ans += s[i];
        }
        return ans;
    }
};