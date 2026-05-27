class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int>last,first;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(ch>='A'&&ch<='Z'){
                if(!first.count(toupper(ch))){
                    first[toupper(ch)]=i;
                }
            }else{
                last[ch]=i;
            }
        }
        int res=0;
        for(char ch='a';ch<='z';ch++){
            if(first.count(toupper(ch))&&last.count(ch)){
                if(first[toupper(ch)]>last[ch]){
                    res++;
                }
            }
        }
        return res;
    }
};