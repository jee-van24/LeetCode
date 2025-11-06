class Solution {
public:
    void convert(int n,string &bin){
        if(n==0){
          return;
        }else{
            convert(n/2,bin);
            char rem=(n%2)+'0';
            bin.push_back(rem);
        }
    }
    int minBitFlips(int start, int goal) {
        string s1;
        string s2;
        convert(start,s1);
        convert(goal,s2);
        int res=0;
        if(s1.size()==s2.size()){
            for(int i=0;i<s1.size();i++){
                if(s1[i]!=s2[i]){
                    res++;
                }
            }
        }else{
            if(s1.size()<s2.size()){
                while(s1.size()!=s2.size()){
                     s1.insert(s1.begin()+0,'0');
                }
            }else{
                while(s1.size()!=s2.size()){
                    s2.insert(s2.begin()+0,'0');
                }
            }
            for(int i=0;i<s1.size();i++){
                if(s1[i]!=s2[i]){
                    res++;
                }
            }
        }
        return res;
    }
};