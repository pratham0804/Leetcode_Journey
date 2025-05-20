class Solution {
// similar to koko eating bananas question , remember , low is 1 and high is the max_val in the array .
private:
    int divisor(int k , vector<int> & nums){
        int n = nums.size();
        int res = 0;
        for(int i=0 ; i<n ; i++){
            // yaad kar ceil function integer arithmetics me thik se kaam nahi krta hai;
            res += ((nums[i]+k-1)/k);
            // constraints normal hai , nahi toh 1e9 exceed kare toh break wali condition dalni  padti.
        }
        return res;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int max_val = INT_MIN;
        for(int i=0 ; i<n ; i++){
            if(max_val < nums[i]){
                max_val = nums[i];
            }
        }

        int low = 1 ;
        int high = max_val;
        int ans ;
        while(low <= high){
            int mid = low + (high-low)/2 ;
            int res = divisor(mid,nums);

            if(res <= threshold){
                ans = mid;
                high = mid-1;
            } 
            else{
                low = mid+1;
            }
        }

        return ans;


    }
};