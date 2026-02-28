int concatenatedBinary(int n) {
    long long MOD = 1e9 + 7;
    long long result = 0;
    int bits = 0;

    for (int i = 1; i <= n; i++) {
        // When i is a power of 2, it gains one more bit
        if ((i & (i - 1)) == 0) {
            bits++;
        }
        result = ((result << bits) | i) % MOD;
    }

    return (int)result;
}
