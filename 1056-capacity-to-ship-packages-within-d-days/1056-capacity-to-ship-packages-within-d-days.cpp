class Solution {
private:
    bool ispossible(vector<int> &weights , int days , int k){
      int n = weights.size();
      int sum = 0;
      int count = 0;
      for(int i=0 ; i<n ; i++){
            
            sum+= weights[i];
            if(sum > k){
                count++;
                sum = weights[i];
            }
      }

      if(sum <= k) count++;

      if(count <= days) return true;
      return false;

    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = INT_MIN;
            int n = weights.size();
        for(int i=0 ; i<n ; i++){
            if(l < weights[i]){
                l = weights[i];
            }
        }
    
        int h = 0;
        for(int i=0 ; i<n ; i++){
            h += weights[i];
        }
        
        int ans = -1;
        while(l <= h){
            int mid = l+(h-l)/2;
            if(ispossible(weights , days , mid)){
                ans = mid;
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }

        return ans;
    }
};