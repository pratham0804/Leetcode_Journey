class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0); // Add a sentinel to flush out stack at end
        int max_area = 0;
        vector<int> stack;

        for (int i = 0; i < heights.size(); ++i) {
            while (!stack.empty() && heights[i] < heights[stack.back()]) {
                int h = heights[stack.back()];
                stack.pop_back();
                int w = stack.empty() ? i : i - stack.back() - 1;
                max_area = max(max_area, h * w);
            }
            stack.push_back(i);
        }

        return max_area;
    }
};