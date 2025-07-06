class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        if(n == 1) return 0;
        int l = 0;
        int r = 1;
        int  ans = 0;
        while(r < n){
            if(prices[r] > prices[l]){
                ans = max(ans,prices[r]-prices[l]);

            }
            else if(prices[r] < prices[l]){
                l = r;
            }
            r++;
        }

        return ans;
    }
};