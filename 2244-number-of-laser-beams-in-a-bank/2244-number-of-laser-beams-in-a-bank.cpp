class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int m = bank[0].size();

        vector<int> a(n,0);
        for(int i=0 ; i<n ;i++){
            for(int j=0 ; j<m ; j++){

                if(bank[i][j] == '1'){

                    a[i]++;
                }
            }
        }


        int ans = 0;
        int i;
        for( i=0 ;i<n ; i++){
            if(a[i] != 0){
                break;
            }
        }
        
        if(i == n-1){
            return 0;
        }
        
        int curr = a[i];
        if(i != n-1){
            
            for(int j = i+1 ; j<n ; j++){
                if(a[j] != 0){
                  ans += (curr*a[j]);
                  curr = a[j];
                }
            }

        }

        return ans;
    }
};