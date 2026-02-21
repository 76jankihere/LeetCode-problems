class Solution {
    public int countPrimeSetBits(int left, int right) {
        int count = 0;
        int primeMask = (1 << 2) | (1 << 3) | (1 << 5) | (1 << 7)
                      | (1 << 11) | (1 << 13) | (1 << 17) | (1 << 19);
        
        for (int n = left; n <= right; n++) {
            int bits = Integer.bitCount(n);
            if ((primeMask >> bits & 1) == 1) {
                count++;
            }
        }
        return count;
    }
}
