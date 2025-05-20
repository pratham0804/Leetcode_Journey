class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /// lets try it with dp 
        int n  = nums.size();
        // we have two options , continue thee current window , or start a new one 
        int l = 0;
        int r = 0;
        int currsum = 0;
        int maxi = INT_MIN;

        while(r < n){

            if(nums[r]+currsum < nums[r]){
                l = r;
                currsum = nums[r];
                maxi = max(maxi , nums[r]);
            }
            else if(nums[r]+currsum >= nums[r]){
                currsum += nums[r];
                maxi = max(maxi,currsum);
            }
            r++;
           
        }

        return maxi;

    }
};