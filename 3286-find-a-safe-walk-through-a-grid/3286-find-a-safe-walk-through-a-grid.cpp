class Solution {
public:
    int delrow[4] = {-1, 0, 1, 0};
    int delcol[4] = {0, 1, 0, -1};

    bool isValid(int r, int c, int n, int m) {
        return r >= 0 && r < n && c >= 0 && c < m;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        // Lose health if starting cell is unsafe
        health -= grid[0][0];
        if (health <= 0)
            return false;

        priority_queue<vector<int>> pq;
        // {remainingHealth, row, col}
        pq.push({health, 0, 0});

        vector<vector<int>> best(n, vector<int>(m, -1));
        best[0][0] = health;

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int h = cur[0];
            int r = cur[1];
            int c = cur[2];

            if (r == n - 1 && c == m - 1)
                return true;

            // Ignore outdated states
            if (h < best[r][c])
                continue;

            for (int i = 0; i < 4; i++) {
                int nr = r + delrow[i];
                int nc = c + delcol[i];

                if (!isValid(nr, nc, n, m))
                    continue;

                int newHealth = h - grid[nr][nc];

                if (newHealth <= 0)
                    continue;

                if (newHealth > best[nr][nc]) {
                    best[nr][nc] = newHealth;
                    pq.push({newHealth, nr, nc});
                }
            }
        }

        return false;
    }
};