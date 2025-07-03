class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        while (word.size() < k) {
            size_t oldSize = word.size();
            for (size_t i = 0; i < oldSize && word.size() < k; ++i) {
                char next = (word[i] - 'a' + 1) % 26 + 'a';
                word += next;
            }
        }
        return word[k - 1];
    }
};
