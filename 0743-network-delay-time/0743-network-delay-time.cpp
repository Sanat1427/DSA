class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it : times){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
        }
        vector<int>dist(n+1,1e9);
        dist[k]=0;
          priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
          pq.push({0,k});
          while(!pq.empty()){
            auto it= pq.top();
            pq.pop();
            int node = it.second;
            int dis = it.first;
           
            for(auto adjnode :adj[node]){
                int v= adjnode.first;
                int wt = adjnode.second;
                if(dist[v]>dis+wt){
                    dist[v]=dis+wt;
                    pq.push({dis+wt,v});
                }
            }
          }
          // taking max(ans,dist[i]) since the node which will take maximum will be last node to be reached..
           int ans =0;
           for(int i =1;i<=n;i++){
            if(dist[i]==1e9)return -1;
            ans = max(ans,dist[i]);
           }
           return ans;
    }
};