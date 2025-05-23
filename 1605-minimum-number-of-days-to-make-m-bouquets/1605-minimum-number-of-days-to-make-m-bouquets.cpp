class Solution {
private:
    bool isPossible(vector<int> &bloomDay , int k , int m , int mid){
        int n = bloomDay.size();
        int count = 0;
        int bcount = 0;
        for(int i=0 ; i<n ; i++){
            if(bloomDay[i] <= mid){
                count++;
                if(count == k){
                bcount++;
                count = 0;
                }
            }
            else{
                count = 0;
            }

            
        }


        if(bcount >= m) return true;
        return false;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n  = bloomDay.size();
        int l = INT_MAX;
        for(int i=0 ; i<n ; i++){
            if(bloomDay[i] < l){
                l = bloomDay[i];
            }
        }

        int h = INT_MIN;
        for(int i=0 ;i < n ; i++){
            if(bloomDay[i] > h){
                h = bloomDay[i];            }
        }
        int ans = -1;
        while(l <= h){
            int mid = l+(h-l)/2;
            if(isPossible(bloomDay,k,m,mid)){
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