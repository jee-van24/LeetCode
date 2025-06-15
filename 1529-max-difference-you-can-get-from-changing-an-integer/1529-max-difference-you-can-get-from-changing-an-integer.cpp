class Solution {
public:
    int maxDiff(int num) {
        string str1 = to_string(num); // for max
        string str2 = to_string(num);
        char max_to_replace = '\0';
        for (int i = 0; i < str1.size(); i++) {
            if (str1[i] != '9') {
                max_to_replace = str1[i]; // digit to replace with 9 found
                break;
            }
        }
        if (max_to_replace != '\0') {
            for (int i = 0; i < str1.size(); i++) {
                if (str1[i] == max_to_replace) {
                    str1[i] = '9';
                }
            }
        }
        char min_to_replace = '\0';
        if (str2[0] != '1') {
            min_to_replace=str2[0];
            for (int i = 0; i < str2.size(); i++) {
                if (str2[i] == min_to_replace) {
                    str2[i] = '1';
                }
            }
        }else {
            for (int i = 1; i < str2.size(); i++) {
                if (str2[i] != '1' && str2[i] != '0') {
                    min_to_replace = str2[i];
                    break;
                }
            }
            if(min_to_replace!='\0'){
             for (int i = 0; i < str2.size(); i++) {
                if (str2[i] == min_to_replace) {
                    str2[i] = '0';
                }
             }
            }
        
        }
        int max = stoi(str1);
        int min = stoi(str2);
        return max - min;
    }
};