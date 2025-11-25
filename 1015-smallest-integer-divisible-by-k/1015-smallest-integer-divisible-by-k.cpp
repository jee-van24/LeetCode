class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k==1)return 1;
        if(k==2||k==5)return -1;
        int len=1;
        long long num=1;
        int reminder=1;
        unordered_set<int>seen;
        while(true){
            if(reminder%k==0)break;
            num=reminder*10+1;
            reminder=num%k;
            if(seen.count(reminder))return -1;
            seen.insert(reminder);
            len++;
        }
        return len;
    }
};