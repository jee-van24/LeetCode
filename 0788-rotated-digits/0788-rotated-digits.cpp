class Solution {
public:
    bool check(int num,unordered_set<int>&invalid,unordered_set<int>&changeable){
        bool changed=false;
        while(num!=0){
            int rem=num%10;
            if(invalid.count(rem)){
                return false;
            }
            if(changeable.count(rem)){
               changed=true;
            }
            num/=10;
        }
        return changed;

    }
    int rotatedDigits(int n) {
        int res=0;
        unordered_set<int>invalid={3,4,7};
        unordered_set<int>changeable={2,5,6,9};
        for(int i=1;i<=n;i++){
            if(check(i,invalid,changeable)){
                res++;
            }
        }
        return res;
    }
};