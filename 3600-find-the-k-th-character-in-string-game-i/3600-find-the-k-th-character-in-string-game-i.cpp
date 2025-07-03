class Solution {
public:
    char kthCharacter(int k) {
        string word="a";
        int i=1;
        while(word.size()<k){
            string temp=word;
            for(int j=0;j<temp.size();j++){
                char curr=temp[j];
                char next=(temp[j] - 'a' + 1) % 26 + 'a';
                word+=next;
            }
            i++;
        }
        return word[k-1];//since i will be equal to k when the loop ends
    }
};