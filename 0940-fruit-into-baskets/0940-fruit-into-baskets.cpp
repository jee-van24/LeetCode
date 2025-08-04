class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int total = 0;
        int left = 0;
        unordered_map<int, int> collected;

        for (int right = 0; right < fruits.size(); right++) {
            int curr = fruits[right];
            collected[curr]++;

            while (collected.size() > 2) {
                collected[fruits[left]]--;
                if (collected[fruits[left]] == 0) {
                    collected.erase(fruits[left]);
                }
                left++;
            }

            total = max(total, right - left + 1);
        }

        return total;
    }
};
