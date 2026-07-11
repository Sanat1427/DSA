class Solution {
public:
    void bfs(int node, vector<vector<int>>& adj, vector<int>& vis,
             vector<int>& component) {
        queue<int> q;
        q.push(node);
        vis[node] = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            component.push_back(u);

            for (auto v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vector<int> component;

                bfs(i, adj, vis, component);

                int nodes = component.size();
                int edgeCount = 0;

                // Sum of degrees
                for (int node : component) {
                    edgeCount += adj[node].size();
                }

                edgeCount /= 2; // Every edge counted twice

                if (edgeCount == nodes * (nodes - 1) / 2)
                    ans++;
            }
        }

        return ans;
    }
};