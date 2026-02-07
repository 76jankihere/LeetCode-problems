class Solution(object):
    def minimumCost(self, nums):
        m1 = 10**9
        m2 = 10**9
        for x in nums[1:]:
            if x < m1:
                m2 = m1
                m1 = x
            elif x < m2:
                m2 = x
        return nums[0] + m1 + m2
