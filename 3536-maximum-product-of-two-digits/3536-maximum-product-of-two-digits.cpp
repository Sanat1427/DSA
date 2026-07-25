class Solution {
public:
    int maxProduct(int n) {
        vector<int> r;
        while (n > 0) {
            int d = n % 10;
            r.push_back(d);
            n /= 10;
        }
        if (r.size() < 2) return 0;
        sort(r.begin(), r.end());
        int size = r.size();
        return r[size - 1] * r[size - 2];
    }
};