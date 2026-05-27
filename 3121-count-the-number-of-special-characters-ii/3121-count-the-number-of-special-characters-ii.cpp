class Solution {
public:
    int numberOfSpecialChars(string word) {

        int n = word.size();

        int hash1[26];
        int hash2[26];

        for(int i = 0; i < 26; i++) {
            hash1[i] = -1;
            hash2[i] = -1;
        }

        for(int i = 0; i < n; i++) {

            if(islower(word[i])) {
                hash1[word[i] - 'a'] = i;
            }

            if(isupper(word[i])) {

                int idx = word[i] - 'A';

               
                if(hash2[idx] == -1) {
                    hash2[idx] = i;
                }
                else {
                    hash2[idx] = min(hash2[idx], i);
                }
            }
        }

        int cnt = 0;

        for(int i = 0; i < 26; i++) {

            if(hash1[i] != -1 &&
               hash2[i] != -1 &&
               hash1[i] < hash2[i]) {

                cnt++;
            }
        }

        return cnt;
    }
};