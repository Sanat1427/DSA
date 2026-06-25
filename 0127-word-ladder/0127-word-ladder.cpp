class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
         queue<pair<string,int>>q;
         q.push({beginWord,1});
         unordered_set<string>st(wordList.begin(),wordList.end());
         st.erase(beginWord);
         while(!q.empty()){
            auto curr = q.front();
            q.pop();
            string word = curr.first;
            int step = curr.second;
            if(word==endWord)
            return step;
            for(int i =0;i<word.size();i++){
                char original = word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,step+1});
                    }
                }
                word[i]=original;

            }
         }
         return 0;
    }
};