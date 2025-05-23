class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> ans(2);
        int n = mat.size();
        int m = mat[0].size();
        
        int maxi = 0;
        int mi = 0;
        
        for(int i = 0; i < n; i++) {
            int countone = 0;
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1) {
                    countone++;
                }
            }
            if(countone > maxi) {
                maxi = countone;
                mi = i;
            }
        }

        ans[0] = mi;
        ans[1] = maxi;

        return ans;
    }
};
