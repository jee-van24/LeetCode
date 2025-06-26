class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == ' '){
                while(i >= 0 && s[i] == ' '){
                    i--;
                }
            }
            if (i < 0) break;

            int j = i;
            while(j >= 0 && s[j] != ' '){
                j--;
            }

            for(int k = j + 1; k <= i; k++){
                res += s[k];
            }
            res += ' ';
            i = j + 1;  // Optional adjustment; your original i = j - 1 also works
        }

        if (!res.empty() && res.back() == ' ') {
            res.pop_back();
        }

        return res;
    }
};
