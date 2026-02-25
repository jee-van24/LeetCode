class Solution {
public:
    int cntones(string &s){
        int res = 0;
        for(char ch : s)
            if(ch == '1') res++;
        return res;
    }

    string tobin(int n){
        if(n == 0) return "0";
        string res;
        while(n != 0){
            res.push_back((n % 2) + '0');
            n /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    vector<int> sortByBits(vector<int>& arr) {

        map<int, vector<string>> mp;

        for(int x : arr){
            string s = tobin(x);
            mp[cntones(s)].push_back(s);
        }

        vector<int> res;

        for(auto &p : mp){
            auto &v = p.second;

            sort(v.begin(), v.end(), [](const string &a, const string &b){
                return stoi(a, nullptr, 2) < stoi(b, nullptr, 2);
            });

            for(auto &s : v)
                res.push_back(stoi(s, nullptr, 2));
        }

        return res;
    }
};