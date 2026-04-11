class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        map<int,int>mp;
        string dir;
        for(int i=0;i<positions.size();i++){
            int pos=positions[i];
            mp[pos]=i;
        }
        struct Robot{
            int pos;
            int health;
            char dir;
            int idx;
        };
        vector<int>sortedhealths,sortedpositions;
        for(auto &p:mp){
            int idx=p.second;
            sortedpositions.push_back(positions[idx]);
            sortedhealths.push_back(healths[idx]);
            dir+=directions[idx];
        }
        positions=sortedpositions;
        healths=sortedhealths;
        directions=dir;
        stack<Robot>st;
        for(int i=0;i<positions.size();i++){
            bool f=true;
            while(!st.empty()&&(st.top().dir=='R'&&directions[i]=='L')){
                if(st.top().health<healths[i]){
                    st.pop();
                    healths[i]--;
                }else if(st.top().health>healths[i]){
                    st.top().health--;
                    f=false;
                    break;
                }else{
                    st.pop();
                    f=false;
                    break;
                }
            }
            if(f){
                st.push({positions[i],healths[i],directions[i],mp[positions[i]]});
            }
        }
        vector<int>temp(positions.size(),0);
        while(!st.empty()){
            auto r=st.top();
            int health=r.health;
            int idx=r.idx;
            temp[idx]=health;
            st.pop();
        }
        vector<int>res;

        for(int i=0;i<temp.size();i++){
            if(temp[i]>0)res.push_back(temp[i]);
        }
        return res;
    }
};