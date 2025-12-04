class Solution {
public:
    void dfs(int idx, unordered_set<string>&seen,string s,int currlen,int &res){
        if(idx==s.size()){
            res=max(res,currlen);
            return;
        }
        for(int i=idx;i<s.size();i++){
            string curr=s.substr(idx,i-idx+1);
            if(seen.find(curr)!=seen.end())continue;
            seen.insert(curr);
            currlen++;
            dfs(i+1,seen,s,currlen,res);
            currlen--;
            seen.erase(curr);
        }
    }
    int maxUniqueSplit(string s) {
        unordered_set<string>seen;
        int res=0;
        dfs(0,seen,s,0,res);
        return res;
    }
};