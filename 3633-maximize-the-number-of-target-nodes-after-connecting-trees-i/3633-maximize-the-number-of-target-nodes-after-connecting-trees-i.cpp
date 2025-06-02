class Solution {
public:
    int dfs(int node, int k, vector<vector<int>>& adj, vector<int>& vis, int par){
        vis[node] = 1;
        int cnt = 1;
        if (k > 0) {
            for (auto it : adj[node]) {
                if (it != par) {
                    cnt += dfs(it, k - 1, adj, vis, node);
                }
            }
        }
        return cnt;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n1 = edges1.size() + 1, n2 = edges2.size() + 1;
        vector<vector<int>> adj1(n1);
        vector<vector<int>> adj2(n2);

        for (auto it : edges1) {
            adj1[it[0]].push_back(it[1]);
            adj1[it[1]].push_back(it[0]);
        }
        for (auto it : edges2) {
            adj2[it[0]].push_back(it[1]);
            adj2[it[1]].push_back(it[0]);
        }

        if (k == 0) {
            return vector<int>(n1, 1);
        }

        // Find max targets at distance k-1 in second tree
        int maxi = 0;
        for (int i = 0; i < n2; i++) {
            vector<int> vis(n2, 0);
            int cnt = dfs(i, k - 1, adj2, vis, -1);
            maxi = max(maxi, cnt);
        }

        vector<int> ans(n1);
        for (int i = 0; i < n1; i++) {
            vector<int> vis(n1, 0);
            int cnt = dfs(i, k, adj1, vis, -1);
            ans[i] = cnt + maxi;
        }

        return ans;
    }
};