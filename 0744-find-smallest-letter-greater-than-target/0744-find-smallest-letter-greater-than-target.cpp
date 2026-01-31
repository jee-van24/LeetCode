class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char res='?';
        int left=0,right=letters.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(letters[mid]>target){
                res=letters[mid];
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        if(res=='?'){
            return letters[0];
        }
        return res;
    }
};