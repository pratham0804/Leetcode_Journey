class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;

        int n = s.size();

        int l = 0;
        int r = 0;
        vector<int> a(256,-1);

        while(r < n){
            
            if(a[s[r]] != -1 && a[s[r]] >= l){
                
                l = a[s[r]] + 1;
                
            }
             
           
                
            max_length = max(max_length , r-l+1);
           
            a[s[r]] = r;
            r++;
        }

        return max_length;
    }
};