class Solution {
public:
    bool isValid(string word) {
        bool vowel=false,consonant=false;
        if(word.size()<3)return false;
        for(auto ch:word){
            if(!isalnum(ch))return false;
            //now it must be a digit or an alphabet
            if(!isdigit(ch)){
                ch=tolower(ch);
                if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
                    vowel=true;
                }else{
                    consonant=true;
                }
            }
        }
        if(vowel==true&&consonant==true)return true;
        return false;
    }
};