#include 

int minOperations(char* s, int k) {
    int n = strlen(s);
    int zeros = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') zeros++;
    }

    // Already all '1's
    if (zeros == 0) return 0;

    int remainder = zeros % k;

    if (remainder == 0) {
        // Each operation flips exactly k zeros, no leftover
        return zeros / k;
    } else {
        int ones = n - zeros;
        int padding_needed = k - remainder;

        // Not enough '1's to pad the last operation
        if (ones < padding_needed) return -1;

        // zeros/k full ops + 1 op for remainder zeros (padded with ones)
        // + 1 op to re-flip those padded ones back to '1'
        return zeros / k + 2;
    }
}
