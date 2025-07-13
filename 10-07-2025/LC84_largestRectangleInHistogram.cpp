class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int n = heights.size();
        int maxArea = 0;

        for (int i = 0; i <= n; ++i) {
            int height = (i == n) ? 0 : heights[i];
            while (!s.empty() && heights[s.top()] > height) {
                int h = heights[s.top()];
                s.pop();
                int ps = s.empty() ? -1 : s.top();
                int width = i - ps - 1;
                maxArea = max(maxArea, h * width);
            }
            s.push(i);
        }

        return maxArea;
    }
};
