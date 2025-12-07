#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long largestPrime(long long n) {
        if (n < 2) return 0;

        int limit = (int)n;
        vector<bool> isPrime(limit + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (long long i = 2; i * i <= limit; i++) {
            if (isPrime[i]) {
                for (long long j = i * i; j <= limit; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        vector<long long> prime;
        for (int i = 2; i <= limit; i++) {
            if (isPrime[i]) prime.push_back(i);
        }

        long long sum = 0;
        int last = -1;

        for (int i = 0; i < (int)prime.size(); i++) {
            if (sum + prime[i] > n) break;
            sum += prime[i];
            last = i;
        }

        for (int i = last; i >= 0 && (sum < 2 || sum > n || !isPrime[sum]); i--) {
            sum -= prime[i];
        }

        if (sum >= 2 && sum <= n && isPrime[sum]) return sum;
        return 0;
    }
};
