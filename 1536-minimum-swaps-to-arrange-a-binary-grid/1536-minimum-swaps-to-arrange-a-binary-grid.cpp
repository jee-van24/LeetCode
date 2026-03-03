class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> trailing(n);

        // Step 1: Count trailing zeros
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = n - 1; j >= 0; j--) {
                if(grid[i][j] == 0)
                    count++;
                else
                    break;
            }
            trailing[i] = count;
        }

        int swaps = 0;

        // Step 2: Greedy placement
        for(int i = 0; i < n; i++) {

            int need = n - 1 - i;
            int j = i;

            // Find first row that satisfies condition
            while(j < n && trailing[j] < need)
                j++;

            if(j == n)
                return -1;

            // Bubble row j up to i
            while(j > i) {
                swap(trailing[j], trailing[j-1]);
                swaps++;
                j--;
            }
        }

        return swaps;
    }
};