class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourangle=30*hour+0.5*minutes;
        double minangle=6*minutes;
        double res=abs(hourangle-minangle);
        if(res>180){
            return 360-res;
        }
        return res;
    }
};