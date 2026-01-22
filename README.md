# 3507. Minimum Pair Removal to Sort Array I

**Difficulty:** Easy  
**Language:** Python  
**Topic:** Array, Simulation  

---

## 🧠 Problem Summary

You are given an array `nums`.  
Repeatedly remove the **adjacent pair with the minimum sum** (leftmost if tie)  
and replace it with their sum.

Return the **minimum number of operations** needed to make the array **non-decreasing**.

---

## 💡 Approach

- The operation is **forced**, so we simulate it step by step.
- While the array is not non-decreasing:
  - Find the leftmost adjacent pair with the minimum sum.
  - Replace the pair with their sum.
  - Count the operation.

Array size ≤ 50, so direct simulation is efficient.

---

## ⏱️ Complexity

- **Time:** `O(n³)` in worst case (small constraints)
- **Space:** `O(1)` extra space

---

## ✅ Example

**Input**
nums = [5,2,3,1]

**Output**
2


---

## 🧩 Code

```python
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
🔗 LeetCode Link

https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/


---

## 4️⃣ Commit & push to GitHub

```bash
git add .
git commit -m "Add solution for LeetCode 3507 - Minimum Pair Removal"
git push origin main

### 📌 LeetCode Practice
- Solved daily LeetCode problems and documented solutions on GitHub
- Focus on clean code, clarity, and interview-ready explanations
