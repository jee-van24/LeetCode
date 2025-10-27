class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        unordered_map<string,pair<int,int>>map;
        for (int i = 0; i < bank.size(); i++) {
            int cnt = 0;
            for (char ch : bank[i]) {
                if (ch == '1') cnt++;
            }
            map[to_string(i) + bank[i]]={i,cnt};
        }
        int res=0;
        int left=0;
        for(int right=1;right<bank.size();right++){
            int prevcnt=map[to_string(left)+bank[left]].second;
            int currcnt=map[to_string(right)+bank[right]].second;
            if(prevcnt!=0&&currcnt!=0){
                res+=prevcnt*currcnt;
                left=right;
            }else if(prevcnt!=0&&currcnt==0){
                continue;
            }else if(prevcnt==0&&currcnt!=0){
                left=right;
            }
        }
        cout<<res;
        return res;
    }
};