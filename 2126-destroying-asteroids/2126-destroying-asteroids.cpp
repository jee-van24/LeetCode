class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long init=mass;
        for(int i=0;i<asteroids.size();i++){
            if(init<asteroids[i])return false;
            init+=asteroids[i];
        }
        return true;
    }
};