class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp = nums;
        int mini1 = INT_MAX;
        int mini1idx = -1;
        int mini2 = INT_MAX;
        int mini2idx = -1;

        
        int ans;
        

        for(int i=0 ; i<n ; i++){
            if(nums[i] < mini1){
                mini1 = nums[i];
                mini1idx = i;
            }
        }

        for(int j =0;j<n ; j++){
            if((nums[j] < mini2) && (j != mini1idx)){
                mini2 = nums[j];
                mini2idx = j;
            }
        }

        ans = mini1 + mini2 ;

        if(mini1idx != 0 && mini2idx != 0){
           ans += nums[0];
           
        }
        else{
            int mini3 = INT_MAX;
            for(int i=0 ; i<n ; i++){
                if(i != mini1idx && i != mini2idx && nums[i] < mini3 ){   
                    mini3 = nums[i];
                }
            }

            ans += mini3;

        }

        return ans;

        

        


    }
};