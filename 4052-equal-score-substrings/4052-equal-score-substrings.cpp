class Solution {
public:
    bool scoreBalance(string s) {
        vector<int> prefixsum(s.size(), -1);
        prefixsum[0] = s[0] - 'a' + 1;
        for (int i = 1; i < s.size(); i++) {
            int curr = s[i] - 'a' + 1;
            prefixsum[i] = curr + prefixsum[i - 1];
        }
        for (auto num : prefixsum) {
            cout << num << " ";
        }
        cout << endl;
        int n=prefixsum.size();
        for(int i=0;i<prefixsum.size();i++){
            int curr=prefixsum[i];
            if(prefixsum[n-1]-prefixsum[i]==curr){
                return true;
            }
        }
       
       
        return false;
    }
};