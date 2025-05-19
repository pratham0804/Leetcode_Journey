class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        int l = 0;
        int h = n-1;
        while(l <= h){
            int mid = l+(h-l)/2;
            if( mid < n-1 && mid > 0  && nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1] ) return nums[mid];
            if(mid == 0 && nums[mid] != nums[mid+1]) return nums[mid];
            if(mid == n-1 && nums[mid] != nums[mid-1]) return nums[mid];
            if(nums[mid] == nums[mid-1] && mid%2 == 0 || nums[mid] == nums[mid+1] && mid%2 != 0){
                h  = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return -1;
    }
};