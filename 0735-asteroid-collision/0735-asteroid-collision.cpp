class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        vector<int>res;
        stack<int>s;
        for(int i=0;i<nums.size();i++){
            if(s.empty()){
                s.push(nums[i]);
            }else if(nums[i]>0){
                s.push(nums[i]);
            }else if(nums[i]<0){
                if(s.top()<0){
                    s.push(nums[i]);
                }else{

                    while(!s.empty()&&(s.top()>0&&s.top()<abs(nums[i]))){
                        s.pop();
                    }
                    if(s.empty()){
                        s.push(nums[i]);
                    }else if(s.top()>0&&s.top()==abs(nums[i])){
                        s.pop();
                    }else if(s.top()==nums[i]||s.top()<0){
                        s.push(nums[i]);
                    }
                }
            }
        }
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};