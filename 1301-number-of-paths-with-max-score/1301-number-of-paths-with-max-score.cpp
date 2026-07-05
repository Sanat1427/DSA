class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int mod = 1e9+7;
        vector<vector<long long>> score(n, vector<long long>(n, -1));
        vector<vector<long long>> ways(n, vector<long long>(n, 0));
        
        score[n-1][n-1] = 0;
        ways[n-1][n-1] = 1;
        
        vector<pair<int,int>> di = {{-1,0}, {0,-1}, {-1,-1}};
        
        for(int i = n-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(score[i][j] == -1 || board[i][j] == 'X') continue;
                
                for(auto it : di){
                    int nr = i + it.first;
                    int nc = j + it.second;

                    // 1. Check bounds and ensure it's not an obstacle
                    if(nr >= 0 && nc >= 0 && board[nr][nc] != 'X') {
                        
                        // 2. Safely calculate the value (using '0' without a space)
                        int val = (board[nr][nc] == 'E' || board[nr][nc] == 'S') ? 0 : board[nr][nc] - '0';
                        
                       
                        if(score[i][j] + val > score[nr][nc]){
                            score[nr][nc] = score[i][j] + val;
                            ways[nr][nc] = ways[i][j];
                        }
                        else if(score[i][j] + val == score[nr][nc]){
                            ways[nr][nc] = (ways[nr][nc] + ways[i][j]) % mod;
                        }
                    }
                }
            }
        }

        if (ways[0][0] == 0) return {0, 0};
        return {(int)score[0][0], (int)ways[0][0]};
    }
};