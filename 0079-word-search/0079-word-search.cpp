class Solution {
    bool check(int i, int j ,vector<vector<char>>& v, string s,int k ){
        int n = v.size();
        int m = v[0].size();
        if(k==s.length())
            return true;
        if(i<0 || j<0 || i>=n || j>=m || s[k]!=v[i][j])
            return false;

        bool ans = false;
        char x = v[i][j];
        v[i][j] = ' ';

        if(i-1>=0)
            ans = ans || check(i-1, j, v, s, k+1);
        if(i+1<n)
            ans = ans || check(i+1, j, v, s, k+1);
        if(j-1>=0)
            ans = ans || check(i, j-1, v, s, k+1);
        if(j+1<m)
            ans = ans || check(i, j+1, v, s, k+1);

        v[i][j] = x;
        return ans;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        if(n==1 && m==1 && word.size()==1){
            if(board[0][0]==word[0])
            return true;
            else 
            return false;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == word[0]) {
                    if(check(i, j, board, word, 0))
                        return true;
                }
            }
        }
        return false;
    }
};
