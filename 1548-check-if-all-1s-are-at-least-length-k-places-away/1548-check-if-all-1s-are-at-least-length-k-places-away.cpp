class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int x ;
        int i;
        for( i=0 ; i<n ;i++){
            if(nums[i] == 1){
                break;
            }
        }

        if(i == n-1) return true;

        for(int j = i+1; j<n ; j++){
            if(nums[j] == 1){
                if((j-i-1) < k){
                    return false;
                }

                i = j;
            }
        }

        return true;
    }
};