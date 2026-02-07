class Solution {
    func findMedianSortedArrays(_ nums1: [Int], _ nums2: [Int]) -> Double {
        // Ensure nums1 is the shorter array to optimize binary search
        if nums1.count > nums2.count {
            return findMedianSortedArrays(nums2, nums1)
        }
        
        let m = nums1.count
        let n = nums2.count
        var low = 0
        var high = m
        
        while low <= high {
            let partitionX = (low + high) / 2
            let partitionY = (m + n + 1) / 2 - partitionX
            
            let maxLeftX = (partitionX == 0) ? Int.min : nums1[partitionX - 1]
            let minRightX = (partitionX == m) ? Int.max : nums1[partitionX]
            
            let maxLeftY = (partitionY == 0) ? Int.min : nums2[partitionY - 1]
            let minRightY = (partitionY == n) ? Int.max : nums2[partitionY]
            
            if maxLeftX <= minRightY && maxLeftY <= minRightX {
                if (m + n) % 2 == 0 {
                    return Double(max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0
                } else {
                    return Double(max(maxLeftX, maxLeftY))
                }
            } else if maxLeftX > minRightY {
                high = partitionX - 1
            } else {
                low = partitionX + 1
            }
        }
        
        return 0.0
    }
}
