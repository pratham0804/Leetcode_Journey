class Solution {
private:
    bool solve(int index , int target , vector<int> &nums , vector<vector<int>> &dp){
        if(target == 0){
            return true;
        }

        if(index == 0){
            if(nums[index] == target){
                return true;
            }

            return false;
        }

        if(dp[index][target] == 1) return true;
        else if(dp[index][target] == 0) return false;

        // exclude
        bool nottake = solve(index-1 , target , nums , dp);
        
        // include..
        bool take  = false;
        if(target >= nums[index]){
             take = solve(index-1 , target-nums[index] , nums , dp);
        }

        if((nottake || take) == false){
            dp[index][target] = 0;
        }
        else{
            dp[index][target] = 1;
        }
        return nottake || take ;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int index = n-1;
        int target = 0;
        for(int i=0 ; i<n ; i++){
            target += nums[i];
        }
        if(target%2 != 0) return false;

        vector<vector<int>> dp(n+1, vector<int>(target+1 , -1));
        return solve(index , target/2 , nums , dp);
    }
};