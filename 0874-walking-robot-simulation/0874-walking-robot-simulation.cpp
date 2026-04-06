class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        char dir='n';//initial
        unordered_set<string>s;
        unordered_map<char,vector<char>>map;
        map['n'].push_back('l');
        map['n'].push_back('r');
        map['d'].push_back('r');
        map['d'].push_back('l');
        map['l'].push_back('d');
        map['l'].push_back('n');
        map['r'].push_back('n');
        map['r'].push_back('d');
        for(auto &v:obstacles){
            string str;
            str+=to_string(v[0]);
            str+=",";
            str+=to_string(v[1]);
            s.insert(str);
        }
        int res=0;
        int dist=0;
        int x=0,y=0;
        for(int i=0;i<commands.size();i++){
            dist=0;
            if(commands[i]==-1){
                dir=map[dir][1];
                continue;
            }else if(commands[i]==-2){
                dir=map[dir][0];
            }else{
                //its a num between 1-9 move in that direction
                for(int j=0;j<commands[i];j++){
                    if(dir=='n'){
                        int newy=y+1;
                        if(!s.count(to_string(x)+","+to_string(newy))){
                            dist=(x*x)+(newy*newy);
                            res=max(res,dist);
                            y=newy;
                        }else{
                            break;
                        }
                    }else if(dir=='d'){
                        int newy=y-1;
                        if(!s.count(to_string(x)+","+to_string(newy))){
                            dist=(x*x)+(newy*newy);
                            res=max(res,dist);
                            y=newy;
                        }else{
                            break;
                        }
                    }else if(dir=='l'){
                        int newx=x-1;
                        if(!s.count(to_string(newx)+","+to_string(y))){
                            dist=(newx*newx)+y*y;
                            res=max(res,dist);
                            x=newx;
                        }else{
                            break;
                        }
                    }else{
                        int newx=x+1;
                        if(!s.count(to_string(newx)+","+to_string(y))){
                            dist=(newx*newx)+y*y;
                            res=max(res,dist);
                            x=newx;
                        }else{
                            break;
                        }

                    }
                }
            }
        }
        return res;
    }
};