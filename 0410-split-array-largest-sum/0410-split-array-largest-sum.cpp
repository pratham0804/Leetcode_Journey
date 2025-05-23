class Solution {
private:
    int noofsplit(vector<int> &nums , int p){
        int k = 1; int sum = 0;
        int n = nums.size();
        for(int i=0 ; i<n ;i++){
            if(sum + nums[i] <= p){
                sum += nums[i];
            }
            else{
                k++;
                sum = nums[i];
            }
        }


        return k;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int l = INT_MIN;
        int h = 0;
        for(int i=0 ; i<n ; i++){
            if(l < nums[i]){
                l = nums[i];
            }

            h+= nums[i];
        }

        int ans  = -1;
        while(l <= h){
            int mid = l+(h-l)/2;
            int kdash = noofsplit(nums,mid);
            if(kdash > k){

                l = mid+1;
            }
            else{
                
                h = mid-1;
            }
        }


        return l;


        
    }
};