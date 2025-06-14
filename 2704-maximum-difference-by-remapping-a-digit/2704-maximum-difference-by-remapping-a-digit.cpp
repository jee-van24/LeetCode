class Solution {
public:
    int minMaxDifference(int num) {
        string str1 = to_string(num);
        string str2 = to_string(num);
        char max_to_replace = '\0';
        char min_to_replace = str2[0];

        for (int i = 0; i < str1.size(); i++) {
            if (str1[i] != '9') {
                max_to_replace = str1[i]; //digit found
                break;
            }
        }

        if (max_to_replace != '\0') {
            for (int i = 0; i < str1.size(); i++) {
                if (str1[i] == max_to_replace) {
                    str1[i] = '9'; //max pbtained 
                }
            }
        }

        for (int i = 0; i < str2.size(); i++) {
            if (str2[i] == min_to_replace) {
                str2[i] = '0'; //min obtained 
            }
        }

        int max = stoi(str1);
        int min = stoi(str2);
        return max - min;
    }
};
