class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<vector<int>>s;
        int n=heights.size();
        vector<int>prev(n),next(n);
        
        for(int i=n-1;i>=0;i--){
            while(!s.empty()&&s.top()[1]>heights[i]){
                s.pop();
            }
            if(!s.empty()){
                next[i]=s.top()[0];
            }else{
                next[i]=n;
            }
            s.push({i,heights[i]});
        }
        cout<<"next: ";
        for(auto n:next){
            cout<<n<<" ";
        }
        cout<<endl;
        while(!s.empty()){
            s.pop();
        }
        for(int i=0;i<n;i++){
            while(!s.empty()&&s.top()[1]>=heights[i]){
                s.pop();
            }
            if(!s.empty()){
                prev[i]=s.top()[0];
            }else{
                prev[i]=-1;
            }
            s.push({i,heights[i]});
        }
        cout<<"prev :";
        for(auto n:prev){
            cout<<n<<" ";
        }
        int res=0;
        for(int i=0;i<n;i++){
            int left=prev[i]+1;
            int right=next[i]-1;
            int len=right-left+1;
            res=max(res,heights[i]*len);
        }
        return res;
    }
};