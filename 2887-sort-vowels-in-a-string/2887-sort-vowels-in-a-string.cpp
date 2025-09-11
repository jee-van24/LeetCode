class Solution {
public:
    string sortVowels(string s) {
        vector<char>arr;
        unordered_set<char>set={'A','E','I','O','U','a','e','i','o','u'};
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(set.find(ch)!=set.end()){
                arr.push_back(ch);
            }
        }
        sort(arr.begin(),arr.end());
        for(auto ch:arr){
            cout<<ch<<" ";
        }
        int j=0;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(set.find(ch)!=set.end()){
                s[i]=arr[j];
                j++;
            }
        }
        return s;
    }
};