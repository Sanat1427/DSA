class Solution {
public:
    unordered_map<string, vector<string>> parent;
    vector<vector<string>> ans;
    vector<string> path;

    void dfs(string word, string &beginWord) {
        path.push_back(word);

        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            path.pop_back();
            return;
        }

        for (auto &par : parent[word]) {
            dfs(par, beginWord);
        }

        path.pop_back();
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        if (!st.count(endWord))
            return {};

        queue<string> q;
        q.push(beginWord);

        bool found = false;

        while (!q.empty() && !found) {

            int size = q.size();
            unordered_set<string> visitedThisLevel;

            while (size--) {

                string word = q.front();
                q.pop();

                string original = word;

                for (int i = 0; i < word.size(); i++) {

                    char old = word[i];

                    for (char ch = 'a'; ch <= 'z'; ch++) {

                        word[i] = ch;

                        if (st.count(word)) {

                            // First time discovered in this level
                            if (!visitedThisLevel.count(word)) {
                                visitedThisLevel.insert(word);
                                q.push(word);
                            }

                            // Store parent
                            parent[word].push_back(original);

                            if (word == endWord)
                                found = true;
                        }
                    }

                    word[i] = old;
                }
            }

            // Remove only after finishing current level
            for (auto &w : visitedThisLevel)
                st.erase(w);
        }

        if (!found)
            return {};

        dfs(endWord, beginWord);

        return ans;
    }
};