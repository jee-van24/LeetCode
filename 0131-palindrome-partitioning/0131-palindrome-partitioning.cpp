class Solution {
public:
    bool ispalin(string s,int l,int r){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void dfs(int idx,string s,vector<string>&path,vector<vector<string>>&res){
        if(idx>=s.size()){
            res.push_back(path);
            return;
        }
        //i will always partition at the given idx first cause its a palindrome by itself 
        
       for(int i=idx;i<s.size();i++){
            if(ispalin(s,idx,i)){
                //this is a palindrome now call the same dfs for the next possible partitions 
                path.push_back(s.substr(idx,i-idx+1));
                dfs(i+1,s,path,res);
                path.pop_back();
            }
       }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>path;
        dfs(0,s,path,res);
        return res;
    }
};