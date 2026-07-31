class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char>st;
        unordered_set<char>set;
        unordered_map<char,int>map;
        for(auto ch:s){
            map[ch]++;
        }
        for(int i=0;i<s.size();i++){
            map[s[i]]--;
            if(set.count(s[i])){
                //already included in the stack , so no point of including it again 
                continue;
            }
            //have to decide to whether to include it now or in the future if possible
            
            while(!st.empty()&&st.top()>s[i]&&map[st.top()]>0){
                set.erase(st.top());
                st.pop();
            }
            st.push(s[i]);
            set.insert(s[i]);
        }
        string res;
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};