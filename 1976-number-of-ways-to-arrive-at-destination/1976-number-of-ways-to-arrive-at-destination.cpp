class Solution {
public:
       int mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
     
        vector<vector<pair<int,int>>>adj(n);
        vector<long long>mini(n,LLONG_MAX);
        vector<int>ways(n,0);
        for(auto it : roads){
            int u = it[0];
            int v = it[1];
            int t = it[2];
            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }
         priority_queue<
    pair<long long,int>,
    vector<pair<long long,int>>,
    greater<pair<long long,int>>
> pq;
         mini[0]=0;
         ways[0]=1;
         pq.push({0,0});
         while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            long long t = it.first;
            int node = it.second;
            for(auto it : adj[node]){
                int v = it.first;
                int tt= it.second;
                if(mini[v]>tt+t){
                    mini[v]=tt+t;
                    ways[v]=ways[node];
                    pq.push({tt+t,v});
                }
                else if (mini[v]==tt+t){
                    ways[v]=(ways[v]+ways[node])%mod;
                }
            }
         }
         return ways[n-1]%mod;
    }
};