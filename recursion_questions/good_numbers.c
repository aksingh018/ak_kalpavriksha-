long long mod = 1000000007;
long long emp(long long base, long long power) {
    if (power == 0) {
        return 1;
    }

    if (power % 2 == 0) {
        long long ans = emp((base * base) % mod, power / 2);
        return ans % mod;
    } else {
        long long ans = emp((base * base) % mod, power / 2);
        return (ans * base) % mod;
    }
}

int countGoodNumbers(long long n) {
    long long even = emp(5, (n + 1)/2);
    long long prime = emp(4, n/2);

    return (even * prime) % mod;
}