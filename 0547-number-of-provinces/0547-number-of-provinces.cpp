class Solution {
public:
   void bfs(int node ,vector<vector<int>>&adj,vector<int>&vis){
            vis[node]=1;
            queue<int>q;
            q.push(node);
            while(!q.empty()){
                int curr = q.front();
                q.pop();
                for(auto it : adj[curr]){
                    if(vis[it]==0){
                        vis[it]=1;
                        q.push(it);
                    }
                }
            }
   }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>>adj(n);
        vector<int>vis(n,0);
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[i].push_back(i);
                }
            }
        }
        int cnt =0;
        for(int i =0;i<n;i++){
            if(vis[i]==0){
                cnt++;
                bfs(i,adj,vis);
            }
        }
        return cnt;
    }
};