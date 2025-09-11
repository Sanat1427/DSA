class Solution {
    vector<int>toposort(int n , vector<vector<int>>&adjrev){
        vector<int>indegree(n,0);
        queue<int>q;

        for(int i =0;i<n;i++){
            for(auto it: adjrev[i]){
                indegree[it]++;
            }
        }
        for(int i =0;i<n;i++){
        if(indegree[i]==0)
        q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(auto it: adjrev[node]){
                indegree[it]--;

                if(indegree[it]==0)
                q.push(it);
            }
        }
        return ans;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<vector<int>>adjrev(n);
        
        for(int i =0;i<n;i++){
            for(auto it : graph[i]){
                adjrev[it].push_back(i);
            }
        }
    vector<int>result=toposort(n,adjrev);
    sort(result.begin(),result.end());
    return result;
    }
};