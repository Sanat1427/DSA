class Solution {
    void marked(int row, int col, vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // up
        for (int i = row - 1; i >= 0; i--) {
            if (grid[i][col] == 1 || grid[i][col] == 2)
                break;
            grid[i][col] = 3; // mark as guarded
        }
        // down
        for (int i = row + 1; i < m; i++) {
            if (grid[i][col] == 1 || grid[i][col] == 2)
                break;
            grid[i][col] = 3;
        }
        // left
        for (int j = col - 1; j >= 0; j--) {
            if (grid[row][j] == 1 || grid[row][j] == 2)
                break;
            grid[row][j] = 3;
        }
        // right
        for (int j = col + 1; j < n; j++) {
            if (grid[row][j] == 1 || grid[row][j] == 2)
                break;
            grid[row][j] = 3;
        }
    }

public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (auto& it : guards)
            grid[it[0]][it[1]] = 1; // guard
        for (auto& it : walls)
            grid[it[0]][it[1]] = 2; // wall

        for (auto& it : guards)
            marked(it[0], it[1], grid);

        int cnt = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 0)
                    cnt++;

        return cnt;
    }
};
