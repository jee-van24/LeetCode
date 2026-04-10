class Robot {
public:
    vector<vector<int>>pos;
    bool firststep=false;
    int idx=0;
    Robot(int width, int height) {
        //east
        for(int x=0;x<width;x++){
            pos.push_back({x,0,1});
        }
        //north
        for(int y=1;y<height;y++){
            pos.push_back({width-1,y,0});
        }
        //west
        for(int x=width-2;x>=0;x--){
            pos.push_back({x,height-1,3});
        }
        //south
        for(int y=height-2;y>0;y--){
            pos.push_back({0,y,2});
        }
        
        pos[0][2]=2;
    }
    
    void step(int num) {
        firststep=true;
        idx=(idx+num)%pos.size();
    }
    
    vector<int> getPos() {
        return {pos[idx][0],pos[idx][1]};
    }
    
    string getDir() {
        if(!firststep)return "East";
        int n=pos[idx][2];
        if(n==1)return "East";
        else if(n==2)return "South";
        else if(n==3)return "West";
        else return "North";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */