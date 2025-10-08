

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = spells.size();
        int m = potions.size();
        vector<int> result(n, 0);

        for (int i = 0; i < n; i++) {
            long long minPotion = (success + spells[i] - 1) / spells[i];
            auto it = lower_bound(potions.begin(), potions.end(), minPotion);
            result[i] = potions.end() - it;
        }
        return result;
    }
};
