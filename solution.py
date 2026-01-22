class Solution(object):
    def minimumPairRemoval(self, nums):
        def nondecreasing(a):
            for i in range(len(a) - 1):
                if a[i] > a[i + 1]:
                    return False
            return True

        ops = 0

        while not nondecreasing(nums):
            best_i = 0
            best_sum = nums[0] + nums[1]

            for i in range(1, len(nums) - 1):
                s = nums[i] + nums[i + 1]
                if s < best_sum:
                    best_sum = s
                    best_i = i

            nums[best_i] = best_sum
            nums.pop(best_i + 1)
            ops += 1

        return ops
