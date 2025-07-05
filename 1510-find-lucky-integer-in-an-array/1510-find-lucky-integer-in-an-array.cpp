class Solution {
public:
    int findLucky(vector<int>& arr) {
        int ans = -1;
       // sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++) {
            int freq = count(arr.begin(), arr.end(), arr[i]);
            if (freq == arr[i]) {
                ans = max(ans, freq);
            }
        }
        return ans;
    }
};