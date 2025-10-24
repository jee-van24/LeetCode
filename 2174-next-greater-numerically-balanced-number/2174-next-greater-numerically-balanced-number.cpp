class Solution {
public:
    int nextBeautifulNumber(int n) {
        string num = to_string(n);
        int check = 0;
        if(n==0){
            return 1;
        }

        if (num.size() == 1) {
            return 22;          
        } else if (num.size() == 2) {
            check = 22;
        } else if (num.size() == 3) {
            check = 122;     
        } else if (num.size() == 4) {
            check = 1333;       
        } else if (num.size() == 5) {
            check = 14444;     
        } else if (num.size() == 6) {
            check = 122333;    
        } else if (num.size() == 7) {
            check = 1224444;   
        }
        if(check>n){
            return check;
        }
        while (true) {
            check++;  // check next number
            string str = to_string(check);

            int freq[7] = {0};
            bool skip=false;      
            for (auto ch : str) {
                if(ch>'6'){
                    skip=true;
                    break;
                }
                int d = ch - '0';
                freq[d]++;
            }
            if(skip){
                continue;
            }

            // now check if digit frequency equals its value
            bool flag = true;
            for (auto ch : str) {
                int d = ch - '0';
                if (freq[d] != d) {
                    flag = false;
                    break;
                }
            }

            if (flag && check > n) {
                return check;
            }
        }
        return 0;
    }
};
