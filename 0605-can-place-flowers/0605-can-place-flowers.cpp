class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        int count = 0;

        if (size == 1) {
            if (flowerbed[0] == 0) count++;
        } else {
            if (flowerbed[0] == 0 && flowerbed[1] == 0) {
                flowerbed[0] = 1;
                count++;
            }

            for (int i = 1; i < size - 1; i++) {
                if (flowerbed[i] == 1) {
                    continue;
                } else {
                    if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                        flowerbed[i] = 1;
                        count++;
                        i++; // skip next spot
                    }
                }
            }

            if (flowerbed[size - 1] == 0 && flowerbed[size - 2] == 0) {
                flowerbed[size - 1] = 1;
                count++;
            }
        }

        return count >= n;
    }
};
