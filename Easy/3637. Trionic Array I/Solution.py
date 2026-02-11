class Solution(object):
    def isTrionic(self, nums):
        n = len(nums)
        if n < 3:
            return False
        
        i = 0
        
        # 1. Strictly Increasing segment [0...p]
        while i + 1 < n and nums[i] < nums[i+1]:
            i += 1
        
        # p must be greater than 0
        if i == 0 or i == n - 1:
            return False
            
        # 2. Strictly Decreasing segment [p...q]
        p_index = i
        while i + 1 < n and nums[i] > nums[i+1]:
            i += 1
            
        # q must be greater than p
        if i == p_index or i == n - 1:
            return False
            
        # 3. Strictly Increasing segment [q...n-1]
        q_index = i
        while i + 1 < n and nums[i] < nums[i+1]:
            i += 1
            
        # If we reached the end, it's a valid Trionic array
        return i == n - 1
