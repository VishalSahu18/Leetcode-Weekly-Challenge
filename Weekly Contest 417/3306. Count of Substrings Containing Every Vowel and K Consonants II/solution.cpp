class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        int n = word.size(),consonant = 0,left = 0,right = 0;
        long long ans = 0;
        unordered_set<char>vowels = {'a','e','i','o','u'};
        unordered_map<char,int>countVowels;

        for(int i=0;i<n;i++){

            char c = word[i];

            if(vowels.count(c))
                countVowels[c]++;
            else
                consonant++;
            
            while(consonant > k && right < i){//making the consonant == k
                    c = word[right];
                    if(vowels.count(c)){
                        if(--countVowels[c]==0)
                            countVowels.erase(c);
                    }else
                        consonant--;

                    right++;
                    left = right;// left is the extreme left at which consonant == k

            }

         
         //even if consonants ==k , we can remove some vowels from the left side

            while(consonant == k && right < i){
                c = word[right];
                if(vowels.count(c)){
                    if(countVowels[c]>1){
                       countVowels[c]--;
                       right++;
                    }else{
                        break;
                    }
                 }else{
                    break;
                 }
            } 

            if(countVowels.size()==5 && consonant==k) 
                 ans += right - left + 1;
        }
        return ans;
    }
};