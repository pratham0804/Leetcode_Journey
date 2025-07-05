class Solution {
private:
    int solve(vector<int> &nums,int index , vector<int> &dp){
        if(index == 0) return nums[index];
        if(index == 1) return nums[index];
        int l = 0; 
        int r = 0;

        if(dp[index] != -1) return dp[index];
        if(index > 1){
            l = nums[index] + solve(nums,index-2 , dp);
        }

        if(index > 2){
            r = nums[index] + solve(nums , index-3 ,  dp);
        }

        return dp[index] = max(l,r);
    }
public:
    int rob(vector<int>& nums) {

        int index  = nums.size()-1;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2)  return (nums[0] >= nums[1])? nums[0] : nums[1];
        vector<int> dp(index+2 , -1);

        int x = solve(nums, index , dp);
        int y = solve(nums,index-1 , dp);

        return max(x,y);
    }
};