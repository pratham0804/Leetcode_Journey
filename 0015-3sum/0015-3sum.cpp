class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        for(int i=0 ; i<n-2 ; i++){
            int j = i+1;
            int k = n-1;
            
            while(j < k){
                if(nums[i]+nums[j]+nums[k] == 0){ res.insert({nums[i],nums[j],nums[k]}); j++; k--;}
                else if(nums[i]+nums[j]+nums[k] < 0) {
                    j++;
                }
                else{
                    k--;
                }
            }

          
        }

       return vector<vector<int>>(res.begin() , res.end());
       

    }
};