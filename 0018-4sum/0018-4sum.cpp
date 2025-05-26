class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int >> res;
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0 ; i<n-1 ; i++){
            for(int j = i+1 ; j<n ; j++){
                int k = j+1;
                int w = n-1;

                while(k < w){
                    vector<int> ans;
                    long long sum = (long long)nums[i]+nums[j]+nums[k]+nums[w];
                    if(sum == target){
                        res.insert({nums[i],nums[j],nums[k],nums[w]});
                        k++;
                        w--;

                    }
                    else if(sum < target){
                        k++;
                    }
                    else{
                        w--;
                    }
                }
            }
        }


        return vector<vector<int>>(res.begin(),res.end());
    }
};