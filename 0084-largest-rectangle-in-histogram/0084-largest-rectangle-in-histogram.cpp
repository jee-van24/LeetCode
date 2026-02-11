class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<pair<int, int>> stack;
        int ret = 0;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i++) {
            int left = i;
            if (!stack.empty()) {
                int height = stack.back().first;
                while (!stack.empty() && stack.back().first >= heights[i]) {
                    height = min(height, stack.back().first);
                    left = min(left, stack.back().second);
                    ret = max(ret, height * (i - 1 - left + 1));
                    stack.pop_back();
                }

                ret = max(ret, heights[i] * (i - left + 1));
            }
            stack.emplace_back(heights[i], left);
        }

        return ret;
    }
};