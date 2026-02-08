class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        memo = {}

        def dp(i, j):
            # Check if result is already in memo
            if (i, j) in memo:
                return memo[(i, j)]
            
            # Base case: if we reached the end of the pattern
            if j == len(p):
                return i == len(s)

            # Check if the first characters match
            first_match = i < len(s) and (p[j] == s[i] or p[j] == '.')

            # Handle '*' wildcard
            if j + 1 < len(p) and p[j+1] == '*':
                # Case 1: Skip '*' and the preceding character (matches zero elements)
                # Case 2: Use '*' (if first characters match) and stay at p[j]
                res = dp(i, j + 2) or (first_match and dp(i + 1, j))
            else:
                # No wildcard, move both pointers if first characters match
                res = first_match and dp(i + 1, j + 1)

            memo[(i, j)] = res
            return res

        return dp(0, 0)
