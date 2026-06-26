class Solution {
public:
vector<int>toposort(int n , vector<vector<int>>&adj){
    vector<int>ind(n,0);
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
    vector<int>ans;
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto it : adj[node]){
            ind[it]--;
            if(ind[it]==0){
                q.push(it);
            }
        }
    }
    return ans;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>adjrev(n);// reverse the graph
        for(int i =0;i<n;i++){
            for(auto it : graph[i]){
                adjrev[it].push_back(i);
            }
        }
         vector<int>ans = toposort(n, adjrev);
         sort(ans.begin(),ans.end());
         return ans;
    }
};