class Solution {
public:
    string sortVowels(string s) {
        vector<char>arr;
        vector<int>idx;
        unordered_set<char>set={'A','E','I','O','U','a','e','i','o','u'};
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(set.find(ch)!=set.end()){
                idx.push_back(i);
                arr.push_back(ch);
            }
        }
        sort(arr.begin(),arr.end());
        for(auto ch:arr){
            cout<<ch<<" ";
        }
        cout<<endl;
        for(auto i:idx){
            cout<<i<<" ";
        }
        int j=0;
        for(int i=0;i<idx.size();i++){
            auto id=idx[i];
            s[id]=arr[j];
            j++;
        }
        return s;
    }
};