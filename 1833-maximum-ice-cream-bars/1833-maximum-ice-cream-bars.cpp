class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        int ans =0;
        sort(costs.begin(),costs.end());
        for(int cost:costs){
            if(cost<=coins){
                coins-=cost;
                ans++;
            }
        }
        return ans;
    }
};