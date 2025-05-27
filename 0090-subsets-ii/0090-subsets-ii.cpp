class Solution {
private:
    void solve(vector<int> nums , int index , vector<int> &output , vector<vector<int>> &ans){
        if(index >= nums.size()){ 
            ans.push_back(output);
            return;
        }

        // include krne  ka logic remains as it is.
        output.push_back(nums[index]);
        solve(nums,index+1,output,ans);
        output.pop_back();

        // exclude krne ka logic along with duplicates ki condition
        while(index+1 < nums.size() && nums[index] == nums[index+1]){
            index++;
        }
        solve(nums,index+1,output,ans);
        
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> output;
        int index =0 ;
        solve(nums,index,output,ans);
        return ans;
    }
};