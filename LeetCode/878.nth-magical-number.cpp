int countMultiples(long long x, long long a, long long b) {
    // get # of multiples of a or b in range [1, x]
    long long lcm = a * b / __gcd(a, b);
    return x/a + x/b - x/lcm;
}

class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        // a = 2, b = 3 in our example
        long long lo = 1, hi = min(a, b) * 1LL * n, mod = 1e9 + 7;
        while(lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (countMultiples(mid, a, b) < n)
                lo = mid + 1;
            else
                hi = mid;
        }
        return hi % mod;
    }
};
