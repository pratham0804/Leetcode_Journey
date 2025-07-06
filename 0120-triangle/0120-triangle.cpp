class Solution {
private:
    int solve(int row , int col  , vector<vector<int>> & triangle , vector<vector<int>> &dp){
        if(row == triangle.size()-1){
            return triangle[row][col];
        }

        if(dp[row][col] != -1) return dp[row][col];
        int l = triangle[row][col] +  solve(row+1 , col , triangle , dp);
        int r = triangle[row][col] +  solve(row+1 , col+1 , triangle , dp);

        return dp[row][col] = min(l,r);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // int m = triangle[0].size();
        int m = triangle[n-1].size(); // dimensions par dhyan de ,, dp matrix banate time use them properly ...... 

        vector<vector<int>> dp(n+1 , vector<int>(m+1,-1));

        return solve(0,0 , triangle , dp);
    }
};