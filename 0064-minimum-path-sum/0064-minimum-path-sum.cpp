class Solution {
private:
    int solve(int n , int m , vector<vector<int>> &grid , vector<vector<int>> &dp){
        // if((n == 0 &&  m != 0 ) || (n != 0 && m == 0) ){
        //     return 0;
        // }

        if(n == 0 && m == 0){
            return grid[n][m];
        }

        
        
        if(dp[n][m] != -1) return dp[n][m];
        
        int l = INT_MAX;
        
        if(n > 0){
          l = grid[n][m] + solve(n-1, m , grid , dp);
        }
        int r = INT_MAX;
        if(m > 0){
          r = grid[n][m] + solve(n,m-1 , grid , dp);
        }

        return dp[n][m] = min(l,r);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(n == 1 && m == 1) return grid[0][0];
        vector<vector<int>> dp(n , vector<int>(m , -1));
       return  solve(n-1 , m-1 , grid ,dp);
        
        
    }
};