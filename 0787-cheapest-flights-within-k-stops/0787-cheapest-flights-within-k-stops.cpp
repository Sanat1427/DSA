class Solution {
    #define P pair<int, pair<int,int>>
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       
     
vector<vector<pair<int, int>>> adj(n);
         for(auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int>mindist(n,1e9);
        mindist[src]=0;
        queue<P>q;
        q.push({0,{src,0}});
        while(!q.empty()){
            auto p = q.front();
            int stops = p.first;
            int node = p.second.first;
            int dist = p.second.second;
            q.pop();
            if(stops>k) continue;
            for(auto it:adj[node]){
                int adjnode = it.first;
                int edgewt= it.second;
                if(dist+edgewt<mindist[adjnode] && stops<=k){
                    mindist[adjnode]=dist+edgewt;
                    q.push({stops+1,{adjnode,dist+edgewt}});
                }
            }
        }
        if(mindist[dst]==1e9)
        return -1;
        return mindist[dst];
    }
};