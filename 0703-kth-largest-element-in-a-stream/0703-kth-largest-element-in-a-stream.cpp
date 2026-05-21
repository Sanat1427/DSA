class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;

    KthLargest(int k, vector<int>& nums) {
        K = k;

        for (int x : nums) {
            if (pq.size() < K) {
                pq.push(x);
            }
            else if (x > pq.top()) {
                pq.pop();
                pq.push(x);
            }
        }
    }

    int add(int val) {

        if (pq.size() < K) {
            pq.push(val);
        }
        else if (val > pq.top()) {
            pq.pop();
            pq.push(val);
        }

        return pq.top();
    }
};