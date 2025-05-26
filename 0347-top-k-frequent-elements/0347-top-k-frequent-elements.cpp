class Solution {

public:
    struct myCompare {
        bool operator()(const pair<int,int> &a ,const pair<int,int> &b){
            return a.second > b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        if(n == 1){
            ans.push_back(nums[0]);
            return ans;
        }

        sort(nums.begin(),nums.end());

        priority_queue<pair<int,int> , vector<pair<int,int>> , myCompare> pq;
        
        int count = 1;
        for(int i=1 ; i<n ; i++){
            if(nums[i] == nums[i-1]){
                 count++;
             }
             else{
                pq.push({nums[i-1],count});
                count = 1;
             }

        }

        // last element ke liye 
        pq.push({nums[n - 1], count});


        while(pq.size()  >  k){
            pq.pop();
        }


    
          while(pq.empty() == false){
            auto it  =  pq.top();
             ans.push_back(it.first);
             pq.pop();
          }

        return ans;

    }
};