class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0 ; i<n ; i++){
            
            int x = target-nums[i];
            
            auto it = mp.find(x);

            if(it != mp.end()){
                ans.push_back(it->second);
                ans.push_back(i);
                return ans;
            }

            mp[nums[i]] = i ;

        }

        return ans;
    }
};