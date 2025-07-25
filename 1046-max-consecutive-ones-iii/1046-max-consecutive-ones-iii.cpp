class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int n = nums.size();
        int l =0;
        int r = 0;
        int ans = 0;
        int count = 0;
        while(r < n){
            if(nums[r] == 0) count++;

            if(count > k){
                if(nums[l] == 0){
                    count--;
                }
                l++;
            }
    
            
            ans = max(ans , r-l+1);
            r++;
        }
        return ans;
    }
};