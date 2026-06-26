class Solution {
public:
    vector<int>toposort(int n , vector<vector<int>>&adj){
        vector<int>ind(n,0);
        vector<int>ans;
        queue<int>q;
        for(int i =0;i<n;i++){
            for(auto it : adj[i]){
                ind[it]++;
            }
        }
        for(int i =0;i<n;i++){
            if(ind[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it :adj[node]){
                ind[it]--;
                if(ind[it]==0)
                  q.push(it);
            }
        }
        return ans;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>topo;
        for(auto it :prerequisites ){
            adj[it[1]].push_back(it[0]);
        }
        topo= toposort(numCourses,adj);
        if(topo.size()==numCourses)
        return topo;
        return {};
    }
};