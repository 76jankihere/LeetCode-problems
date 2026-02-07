class Solution {
    public boolean isPalindrome(int x) {
        // Special cases:
        // 1. Negative numbers are never palindromes (e.g., -121 != 121-)
        // 2. Numbers ending in 0 are not palindromes, unless the number is 0 itself.
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        // When the length is odd, we can get rid of the middle digit by revertedNumber/10
        // e.g., for 121, at the end of the loop x = 1, revertedNumber = 12
        // x == revertedNumber/10 (1 == 1) returns true.
        return x == revertedNumber || x == revertedNumber / 10;
    }
}
