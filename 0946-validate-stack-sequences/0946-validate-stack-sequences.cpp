class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed==popped)return true;
        stack<int>s;
        int i=0,j=0;
        while(j!=popped.size()&&i<pushed.size()){
           s.push(pushed[i]);
           i++;
           while(!s.empty()&&s.top()==popped[j]){
            s.pop();
            j++;
           }
        }
        return j==popped.size();
    }
};