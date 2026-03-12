class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int res=0;
        priority_queue<int>maxheap;
        vector<int>map(26,0);
        for(int i=0;i<tasks.size();i++){
            map[tasks[i]-'A']++;
        }
        for(auto n:map){
            if(n>0)maxheap.push(n);
        }
        while(!maxheap.empty()){
            vector<int>temp;
            //try to take the highest n+1 tasks
            for(int i=0;i<n+1;i++){
                if(!maxheap.empty()){
                    int maxf=maxheap.top();
                    maxheap.pop();
                    maxf--;
                    temp.push_back(maxf);   
                }
            }
            for(auto n:temp){
                if(n>0){
                 maxheap.push(n);
                }
            }
            if(maxheap.empty()){
                res+=temp.size();
            }else{
                res+=n+1;
            }
            
        }
        return res;
    }
};