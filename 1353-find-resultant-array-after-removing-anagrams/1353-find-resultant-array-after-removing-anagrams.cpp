class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>res;
        res.push_back(words[0]);
        string prev=words[0];
        sort(prev.begin(),prev.end());
        //for now the map has the frequency of chars of the first word
        for(int i=1;i<words.size();i++){
            auto currword=words[i];
            auto sortedcurrword=currword;
            sort(sortedcurrword.begin(),sortedcurrword.end());
            if(sortedcurrword!=prev){
                // it is not a anagram 
                //add this to the result and make it the last prev
                res.push_back(currword);
                prev=sortedcurrword;

            }
        }
        return res;

    }
};