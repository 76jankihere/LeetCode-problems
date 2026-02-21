# 761. Special Binary String

**Difficulty:** Hard

---

## Problem Description

**Special binary strings** are binary strings with the following two properties:

- The number of `0`'s is equal to the number of `1`'s.
- Every **prefix** of the binary string has at least as many `1`'s as `0`'s.

You are given a **special binary** string `s`.

A **move** consists of choosing two consecutive, non-empty, special substrings of `s`, and swapping them. Two strings are consecutive if the last character of the first string is exactly one index before the first character of the second string.

Return *the lexicographically largest resulting string possible* after applying the mentioned operations on the string.

---

## Examples

### Example 1

**Input:** `s = "11011000"`  
**Output:** `"11100100"`

**Explanation:**  
The strings `"10"` (at index 1) and `"1100"` (at index 3) are swapped.  
This is the lexicographically largest string possible after some number of swaps.

---

### Example 2

**Input:** `s = "10"`  
**Output:** `"10"`

---

## Constraints

- `1 <= s.length <= 50`
- `s[i]` is either `'0'` or `'1'`
- `s` is a special binary string

---

## Key Insight

A special binary string always starts with `1` and ends with `0`.  
It maps perfectly to a **valid parentheses string** where `1 = '('` and `0 = ')'`.

The structure of any special binary string is: `1` + [inner special string] + `0`.

So the problem reduces to:
1. **Split** the input into its top-level special substrings.
2. **Recursively** sort the inner content of each special substring.
3. **Sort** the top-level special substrings in **descending order** (to get the lexicographically largest result).
4. **Concatenate** them.

Sorting in descending order works because longer/richer special strings are lexicographically larger (e.g., `"1100"` > `"10"`).

---
