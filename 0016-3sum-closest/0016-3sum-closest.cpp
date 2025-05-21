class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int min_diff = INT_MAX;
         int flag = 0;
        sort(nums.begin(),nums.end());
        for(int i=0 ;i<n-2 ; i++){
            int j = i+1;
            int k = n-1;
           
            while(j < k){
                if(nums[i]+nums[j]+nums[k] == target){
                   return target;
                }
                else if(nums[i]+nums[j]+nums[k] < target){
                    int old_min_diff = min_diff;
                    min_diff = min(min_diff,abs(target - (nums[i]+nums[j]+nums[k])));
                    if(old_min_diff != min_diff){
                        flag = 1;
                    }
                    
                    
                    j++;
                }
                else{
                    int old_min_diff = min_diff ;
                    min_diff = min(min_diff , abs(target - (nums[i]+nums[j]+nums[k])));
                    if(old_min_diff != min_diff){
                        flag = 0;
                    }
                    k--;
                }

            }


        }
        if(flag == 1){
            return target-min_diff ;
        }
        return min_diff + target;
    }
};