class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0;
        int ans=0,count=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                count++;
            }else{
                count--;
            }
            while(count<0){
                ans++;
                count++;
            }
        }
        if(count>0){
            ans+=count;
        }
        return ans;
    }
};