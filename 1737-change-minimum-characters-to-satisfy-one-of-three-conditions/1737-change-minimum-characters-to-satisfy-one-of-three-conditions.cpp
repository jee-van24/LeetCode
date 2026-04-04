class Solution {
public:
    int res = INT_MAX;
    int minCharacters(string a, string b) {
        vector<int>v1(26,0),v2(26,0);
        //a<b
        int tot1=INT_MAX;
        for(auto ch:a)v1[ch-'a']++;
        for(auto ch:b)v2[ch-'a']++;
        for(char ch='a';ch<'z';ch++){
            char bound=ch;
            int cnt1=0;
            int idx=ch-'a';
            for(int i=0;i<26;i++){
                if(i>idx&&v1[i]!=0){
                    cnt1+=v1[i];
                }
            }
            //there should be no chars in b less than ch
            for(int i=0;i<26;i++){
                if(i<=idx&&v2[i]!=0){
                    cnt1+=v2[i];
                }
            }
            tot1=min(tot1,cnt1);
        }
        //b<a
        int tot2=INT_MAX;
        for(char ch='a';ch<'z';ch++){
            char bound=ch;
            int cnt2=0;
            int idx=ch-'a';
            for(int i=0;i<26;i++){
                if(i>idx&&v2[i]!=0){
                    cnt2+=v2[i];
                }
            }
            //there should be no chars in a less than ch
            for(int i=0;i<26;i++){
                if(i<=idx&&v1[i]!=0){
                    cnt2+=v1[i];
                }
            }
            tot2=min(tot2,cnt2);
        }
        //cond 3 : make each having 1 dist ch
        int tot3=INT_MAX;
        for(char ch='a';ch<='z';ch++){
            int cnt3=0;
            cnt3+=(int)a.size()-v1[ch-'a'];
            cnt3+=(int)b.size()-v2[ch-'a'];
            tot3=min(tot3,cnt3);
        }
        res=min({tot1,tot2,tot3});
        return res;
    }
};