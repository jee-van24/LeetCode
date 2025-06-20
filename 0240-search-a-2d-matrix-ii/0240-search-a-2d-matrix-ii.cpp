class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size(); ++i) {
            // Skip empty rows just in case
            if (matrix[i].empty()) continue;

            // If the target can possibly be in this row, do binary search
            if (matrix[i][0] <= target && target <= matrix[i].back()) {
                int low = 0, high = matrix[i].size() - 1;
                while (low <= high) {
                    int mid = low + (high - low) / 2;
                    if (matrix[i][mid] == target) return true;
                    else if (matrix[i][mid] < target) low = mid + 1;
                    else high = mid - 1;
                }
            }
        }
        return false;
    }
};
