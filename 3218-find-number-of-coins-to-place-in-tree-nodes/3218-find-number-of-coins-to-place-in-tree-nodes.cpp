class Solution {
public:
    int dfs(int node,vector<vector<int>> &graph,int par,vector<int> &subtree){
        int ans=1;
        for(auto it: graph[node]){
            if(it==par) continue;
            ans+=dfs(it,graph,node,subtree);
        }
        return subtree[node]=ans;
    }
    void find(int node,vector<vector<int>> &graph,int par,multiset<long long> &costs,vector<long long> &coin,vector<int> &subtree,vector<int> &cost){
        for(auto &it: graph[node]){
            if(it==par) continue;
            multiset<long long> temp;
            find(it,graph,node,temp,coin,subtree,cost);
            if(temp.size()>=5){
                int lastsecond=*(++temp.begin());
                costs.insert(lastsecond);
            }
            if(temp.size()>=4){
                int last=*(temp.begin());
                costs.insert(last);
            }
            if(temp.size()>=3){
                int third=*(++(++temp.rbegin()));  
                costs.insert(third);
            }
            if(temp.size()>=2){
                int second=*(++temp.rbegin());
                costs.insert(second);
            }
            if(temp.size()>=1){
                int first=*temp.rbegin();
                costs.insert(first);
            }
            while(costs.size()>5){
                costs.erase((++(++costs.begin())));
            }
        }
        costs.insert(cost[node]);
        if(subtree[node]>=3){
            long long first=*costs.rbegin();
            long long second=*(++costs.rbegin());
            long long third=*(++(++costs.rbegin()));
            long long last=*(costs.begin());
            long long lastsecond=*(++costs.begin());
            coin[node]=max(0LL,max(first*second*third,first*last*lastsecond));
        }
        else{
            coin[node]=1;
        }    
    }
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n=cost.size();
        vector<vector<int>> graph(n);
        for(auto &it: edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        multiset<long long> costs;
        vector<int> subtree(n);
        vector<long long> coins(n);
        dfs(0,graph,-1,subtree);
        find(0,graph,-1,costs,coins,subtree,cost);
        return coins;
    }
};