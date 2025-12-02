class Solution {
    vector<int> delrow = {-1,-1,-1,0,0,1,1,1};
    vector<int> delcol = {-1,0,1,-1,1,-1,0,1};

    bool isValid(int row, int col, int n, int m) {
        if (row < 0 || row >= n) return false;
        if (col < 0 || col >= m) return false;
        return true;
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

    
        if (grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;

      
        if (n == 1 && m == 1) return 1;  

        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        dist[0][0] = 1;              
        q.push({1, {0, 0}});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;

          
            if (row == n - 1 && col == m - 1) return dis;

            for (int i = 0; i < 8; i++) {   
                int newrow = row + delrow[i];
                int newcol = col + delcol[i];

                if (isValid(newrow, newcol, n, m) &&
                    grid[newrow][newcol] == 0 &&
                    dis + 1 < dist[newrow][newcol]) {

                    dist[newrow][newcol] = dis + 1;
                    q.push({dis + 1, {newrow, newcol}});
                }
            }
        }
        return -1;
    }
};
