class Solution {
public:
    string getHint(string secret, string guess) {
        int correct=0;
        if(secret==guess){
            return to_string(secret.size())+"A"+to_string(0)+"B";
        }
        unordered_map<char,int>map1,map2;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                correct++;
            }else{
                map1[secret[i]]++;
                map2[guess[i]]++;
            }
        }
        int incorrect=0;
        for(auto &p:map1){
            auto ch=p.first;
            auto freq=p.second;
            if(map2.count(ch)){
                if(map2[ch]==freq){
                    incorrect+=freq;
                }else{
                    incorrect+=min(freq,map2[ch]);
                }
            }    
        }
       
        cout<<incorrect<<endl;
        cout<<correct;
        return to_string(correct)+"A"+to_string(incorrect)+"B";
    }
};