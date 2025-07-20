class Solution {
public:
    string removeDigit(string number, char digit) {
        int pos = -1;
        for (int i = 0; i < number.size(); i++) {
            if (number[i] == digit) {
                pos = i;

                if (i + 1 < number.size() && number[i + 1] > digit) {
                    return number.substr(0, i) + number.substr(i + 1);
                }
            }
        }
        return number.substr(0, pos) + number.substr(pos + 1);
    }
};