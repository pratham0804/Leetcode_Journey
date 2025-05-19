class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n  = piles.size();
     
        int ans = 0;

        int l = 1;
        int maxi = INT_MIN;
        for(int i=0 ; i<n ; i++){
            if(maxi < piles[i]){
                maxi = piles[i];
            }
        }
        int r = maxi;
        while(l <= r){
            long long sum = 0;
            int mid = l+(r-l)/2;
            for(int i=0 ; i<n ; i++){
                sum += (piles[i]+mid-1)/mid;
                
                
            }

            if(sum > h){
                l = mid+1;
            }
            else{
                ans = mid;
                r = mid-1;
            }

        }


        return ans;
    }
};