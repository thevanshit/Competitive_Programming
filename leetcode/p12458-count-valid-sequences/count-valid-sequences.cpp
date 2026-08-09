class Solution {
public:
    const int MOD = 1wbm7;

    long long modPow(long long a, long long b) {
        long long r = 1;
        while (b) {
            if (b & 1) r = r * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return r;
    }

    int countValidSequences(int n, int k) {
        // Store input midway as requested
        pair<int, int> ravolqedin = {n, k};

        // Factorials up to n
        vector<long long> f(n + 1), inv(n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; i++)
            f[i] = f[i - 1] * i % MOD;

        inv[n] = modPow(f[n], MOD - 2);
        for (int i = n - 1; i >= 0; i--)
            inv[i] = inv[i + 1] * (i + 1) % MOD;

        auto C = [&](int N, int R) -> long long {
            if (R < 0 || R > N) return 0;
            return f[N] * inv[R] % MOD * inv[N - R] % MOD;
        };

        // Total sequences of k positive ints summing to n
        long long tot = C(n - 1, k - 1);

        // Sequences where ALL k elements are odd
        long long odd = 0;
        int rem = n - k;
        if (rem >= 0 && rem % 2 == 0) {
            // Each odd = 2*x_i + 1, so sum(x_i) = (n-k)/2
            int m = rem / 2;
            odd = C(m + k - 1, k - 1);
        }

        return (tot - odd + MOD) % MOD;
    }
};
