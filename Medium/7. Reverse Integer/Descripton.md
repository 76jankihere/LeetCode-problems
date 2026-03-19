# 7. Reverse Integer
 
**Difficulty:** Medium
 
---
 
## Problem Description
 
Given a signed 32-bit integer `x`, return `x` *with its digits reversed*. If reversing `x` causes the value to go outside the signed 32-bit integer range `[-2^31, 2^31 - 1]`, then return `0`.
 
> **Assume the environment does not allow you to store 64-bit integers (signed or unsigned).**
 
---
 
## Examples
 
### Example 1
 
**Input:** `x = 123`  
**Output:** `321`
 
---
 
### Example 2
 
**Input:** `x = -123`  
**Output:** `-321`
 
---
 
### Example 3
 
**Input:** `x = 120`  
**Output:** `21`
 
---
 
## Constraints
 
- `-2^31 <= x <= 2^31 - 1`
 
---
 
## Key Insight — Check Overflow Before It Happens
 
Since we **cannot use 64-bit integers**, we must check for overflow **before** multiplying.
 
The 32-bit integer range is:
- `INT_MAX = 2147483647` (2^31 - 1)
- `INT_MIN = -2147483648` (-2^31)
 
At each step before doing `result = result * 10 + digit`, check:
- If `result > INT_MAX / 10` → overflow on multiply
- If `result == INT_MAX / 10` AND `digit > 7` → overflow (since INT_MAX ends in 7)
- Mirror checks for negative side (INT_MIN ends in 8)
 
---
