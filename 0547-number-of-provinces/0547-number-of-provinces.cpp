class Solution {
public:
    void bfs(int node, vector<vector<int>>& adjls, vector<int>& vis) {
        vis[node] = 1;
        queue<int> q;
        q.push(node);

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            for (int it : adjls[i]) {
                if (vis[it] != 1) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjls(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }

        vector<int> vis(n, 0);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                cnt++;
                bfs(i, adjls, vis);
            }
        }

        return cnt;
    }
};
