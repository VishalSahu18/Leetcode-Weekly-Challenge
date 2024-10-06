class Solution {
public:
    char kthCharacter(int k) {
        
        string word = "a",curr;
        int idx;

        while(word.size()<k){
            curr = "";
            for(char x : word)
                curr += (++x);
            word+= curr;
        }

        return word[k-1];
    }
};