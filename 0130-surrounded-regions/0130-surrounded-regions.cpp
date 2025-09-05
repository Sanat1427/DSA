class Solution {
    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, 1, 0, -1};

    bool isvalid(int i, int j, int n, int m) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<bool>>& vis) {
        int n = board.size();
        int m = board[0].size();

        vis[row][col] = true;

        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (isvalid(nrow, ncol, n, m) && board[nrow][ncol] == 'O' && !vis[nrow][ncol]) {
                dfs(nrow, ncol, board, vis);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

      
        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && board[0][j] == 'O')
                dfs(0, j, board, vis);
            if (!vis[n - 1][j] && board[n - 1][j] == 'O')
                dfs(n - 1, j, board, vis);
        }

      
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && board[i][0] == 'O')
                dfs(i, 0, board, vis);
            if (!vis[i][m - 1] && board[i][m - 1] == 'O')
                dfs(i, m - 1, board, vis);
        }

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !vis[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};
