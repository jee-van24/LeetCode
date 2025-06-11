class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0, high = matrix.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (matrix[mid][0] <= target && target <= matrix[mid].back()) {
                int curr_start = 0, curr_end = matrix[mid].size() - 1;
                while (curr_start <= curr_end) {
                    int curr_mid = curr_start + (curr_end - curr_start) / 2;
                    if (matrix[mid][curr_mid] == target) {
                        return true;
                    } else if (matrix[mid][curr_mid] < target) {
                        curr_start = curr_mid + 1;
                    } else {
                        curr_end = curr_mid - 1;
                    }
                }
                return false;
            } else if (matrix[mid][0] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return false;
    }
};
