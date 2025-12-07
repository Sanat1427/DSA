class Solution {
public:
#define P pair<long long , int>
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9+7;
      vector<vector<pair<int,int>>> adj(n);
        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});  }
            
            vector<long long>mintime(n,LLONG_MAX);
            vector<int>ways(n,0);
            priority_queue<P,vector<P>,greater<P>>pq;
            mintime[0]=0;
            ways[0]=1;
            pq.push({0,0});
            while(!pq.empty()){
                auto p = pq.top();
                pq.pop();
                long long time = p.first;
                int node = p.second;
                for(auto it : adj[node]){
                    int adjnode = it.first;
                    int traveltime = it.second;
                    if(time+traveltime<mintime[adjnode]){
                        mintime[adjnode]=time+traveltime;
                        ways[adjnode]=ways[node];
                        pq.push({mintime[adjnode],adjnode});
                    }
                    else if(mintime[adjnode]==time+traveltime){
                        ways[adjnode]=(ways[adjnode]+ways[node])%mod;
                    }
                }

            }
            return ways[n-1]%mod;
    }
};