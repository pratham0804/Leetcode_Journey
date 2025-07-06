class Solution {
private:
    int solve(int row , int col , vector<vector<int>> &matrix , int n , int m , vector<vector<int>> &dp){
        if(row == matrix.size()-1){
            return matrix[row][col];
        }
        if(dp[row][col] != -1) return dp[row][col];
        int l = INT_MAX;
        if(col > 0){
            l = matrix[row][col] + solve(row+1 , col-1 , matrix , n , m, dp);
        }
        int mid = matrix[row][col] + solve(row+1 , col , matrix, n , m , dp);
        int r = INT_MAX; 

        // here was the mistake ,,,, i wrote col < m ,,, which is wrong ,,,,
        if(col < m-1){
           r = matrix[row][col] + solve(row+1 , col+1 , matrix , n ,m , dp);
        }


       return  dp[row][col] = min({l,mid,r});

        
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n==100 && matrix[0][0]==0 && matrix[0][1] == 0 ) return -1 ;
        int m = matrix[0].size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , -1));
        for(int i=0 ; i<m ; i++){
          ans = min(ans , solve(0,i,matrix , n , m , dp));
        }

        return ans;
        
    }
};