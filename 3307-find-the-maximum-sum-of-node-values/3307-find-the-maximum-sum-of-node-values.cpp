class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long base = 0;
        long long sumPos = 0;
        int cntPos = 0;
        long long minPos = LLONG_MAX;

        long long bestNonpos = LLONG_MIN;
        bool sawNonpos = false;
        for (int x : nums) {
            base += x;
            long long d = (long long)(x ^ k) - x;
            if (d > 0) {
                ++cntPos;
                sumPos += d;
                if (d < minPos) minPos = d;
            } else {
                if (!sawNonpos || d > bestNonpos) {
                    bestNonpos = d;
                    sawNonpos = true;
                }
            }
        }
        if ((cntPos & 1) == 0) {
            return base + sumPos;
        }
        long long loss = minPos;
        if (sawNonpos) {
            loss = min(loss, -bestNonpos);
        }
        return base + sumPos - loss;
    }
};