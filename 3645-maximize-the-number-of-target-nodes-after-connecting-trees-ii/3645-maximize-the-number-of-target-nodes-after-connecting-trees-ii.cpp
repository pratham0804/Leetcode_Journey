class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> g1(n), g2(m);
        for(auto &e: edges1) {
            g1[e[0]].push_back(e[1]);
            g1[e[1]].push_back(e[0]);
        }
        for(auto &e: edges2) {
            g2[e[0]].push_back(e[1]);
            g2[e[1]].push_back(e[0]);
        }
        auto bfs = [&](int N, vector<vector<int>>& g, vector<char>& parity, array<int,2>& cnt) {
            parity.assign(N,0);
            cnt = {0,0};
            vector<char> vis(N);
            vector<int> q; q.reserve(N);
            int qi = 0;
            q.push_back(0);
            vis[0] = 1; cnt[0] = 1;
            while(qi < (int)q.size()) {
                int u = q[qi++];
                for(int v: g[u]) if(!vis[v]) {
                    vis[v] = 1;
                    parity[v] = parity[u]^1;
                    cnt[parity[v]]++;
                    q.push_back(v);
                }
            }
        };
        vector<char> p1, p2;
        array<int,2> c1, c2;
        bfs(n, g1, p1, c1);
        bfs(m, g2, p2, c2);
        int best2 = max(c2[0], c2[1]);
        vector<int> ans(n);
        for(int i = 0; i < n; i++) 
            ans[i] = c1[p1[i]] + best2;
        return ans;
    }
};