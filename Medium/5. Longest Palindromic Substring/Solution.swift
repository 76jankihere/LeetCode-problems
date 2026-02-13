class Solution {
    func longestPalindrome(_ s: String) -> String {
        let chars = Array(s)
        let n = chars.count
        if n < 2 { return s }

        var start = 0
        var maxLen = 1

        func expand(_ left: Int, _ right: Int) {
            var l = left
            var r = right

            while l >= 0 && r < n && chars[l] == chars[r] {
                if r - l + 1 > maxLen {
                    maxLen = r - l + 1
                    start = l
                }
                l -= 1
                r += 1
            }
        }

        for i in 0..<n {
            expand(i, i)       // odd-length
            expand(i, i + 1)   // even-length
        }

        let startIdx = s.index(s.startIndex, offsetBy: start)
        let endIdx = s.index(startIdx, offsetBy: maxLen)
        return String(s[startIdx..<endIdx])
    }
}
