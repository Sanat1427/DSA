class Solution {
public:
#define P pair <int, pair<int,int>>
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
     
      vector<int>mindist(n,1e9);
      queue<P>q;
     vector<vector<pair<int,int>>> adj(n);
      for(auto it : flights){
        int u = it[0];
        int v = it[1];
        int p = it[2];
        adj[u].push_back({v,p});
      
      }
        mindist[src]=0;
        q.push({0,{src,0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stop = it.first;
            int node = it.second.first;
            int dis = it.second.second;
            if(stop>k) continue;
            for(auto i :adj[node]){
                int an = i.first;
                int wt = i.second;
                if(dis+wt<mindist[an]&& stop<=k){
                    mindist[an]=dis+wt;
                    q.push({stop+1,{an,dis+wt}});
                }
                
            }

        }

       if(mindist[dst]==1e9)
       return -1;
       return mindist[dst];

    }
};