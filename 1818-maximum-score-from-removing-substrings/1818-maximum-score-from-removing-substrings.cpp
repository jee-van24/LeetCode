class Solution {
public:
    int total(string& s, char first, char second, int& val) {
        string temp = "";
        int score = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (!temp.empty() && temp.back() == first && c == second) {
                temp.pop_back(); // remove 'a'
                score += val;
            } else {
                temp += c;
            }
        }
        s=temp;
        return score;
    }
    int maximumGain(string s, int x, int y) {
        int score1=0,score2=0;
        if (x > y) {
           score1 = total(s, 'a', 'b', x);
         score2 = total(s, 'b', 'a', y);
        } else {
             score1 = total(s, 'b', 'a', y);
            score2 = total(s, 'a', 'b', x);
            
        }
        return score1+score2;
    }
};