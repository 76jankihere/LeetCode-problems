# 8. String to Integer (atoi)

**Difficulty:** Medium

---

## Problem Description

Implement the `myAtoi(string s)` function, which converts a string to a 32-bit signed integer.

The algorithm for `myAtoi(string s)` is as follows:

1. **Whitespace:** Ignore any leading whitespace `(" ")`.
2. **Signedness:** Determine the sign by checking if the next character is `'-'` or `'+'`, assuming positivity if neither present.
3. **Conversion:** Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is `0`.
4. **Rounding:** If the integer is out of the 32-bit signed integer range `[-2^31, 2^31 - 1]`, then round the integer to remain in the range. Specifically, integers less than `-2^31` should be rounded to `-2^31`, and integers greater than `2^31 - 1` should be rounded to `2^31 - 1`.

Return the integer as the final result.

---

## Examples

### Example 1

**Input:** `s = "42"`  
**Output:** `42`

**Explanation:**
```
Step 1: "42"  (no leading whitespace)
         ^
Step 2: "42"  (no '+' or '-')
         ^
Step 3: "42"  ("42" is read in)
           ^
```

---

### Example 2

**Input:** `s = " -042"`  
**Output:** `-42`

**Explanation:**
```
Step 1: "   -042"  (leading whitespace ignored)
            ^
Step 2: "   -042"  ('-' is read, result is negative)
             ^
Step 3: "   -042"  ("042" is read in, leading zeros ignored)
                ^
```

---

### Example 3

**Input:** `s = "1337c0d3"`  
**Output:** `1337`

**Explanation:**
```
Step 1: "1337c0d3"  (no leading whitespace)
         ^
Step 2: "1337c0d3"  (no '+' or '-')
         ^
Step 3: "1337c0d3"  ("1337" is read; stops at non-digit 'c')
             ^
```

---

### Example 4

**Input:** `s = "0-1"`  
**Output:** `0`

**Explanation:**
```
Step 1: "0-1"  (no leading whitespace)
         ^
Step 2: "0-1"  (no '+' or '-')
         ^
Step 3: "0-1"  ("0" is read; stops at non-digit '-')
          ^
```

---

### Example 5

**Input:** `s = "words and 987"`  
**Output:** `0`

**Explanation:**  
Reading stops at the first non-digit character `'w'`. Since no digits were read, the result is `0`.

---

## Constraints

- `0 <= s.length <= 200`
- `s` consists of English letters (lower-case and upper-case), digits (`0-9`), `' '`, `'+'`, `'-'`, and `'.'`

---

## Key Insight — Step-by-Step Parsing with Overflow Check

Follow the 4 algorithm steps exactly, and check for overflow **before** multiplying:

- `INT_MAX = 2147483647` → clamp to this if overflow positive
- `INT_MIN = -2147483648` → clamp to this if overflow negative
- Before `result = result * 10 + digit`, check if `result > INT_MAX / 10` or last digit causes overflow

---

## C Solution

```c
#include <limits.h>

int myAtoi(char* s) {
    int i = 0;
    int sign = 1;
    int result = 0;

    // Step 1: Skip leading whitespace
    while (s[i] == ' ') i++;

    // Step 2: Check for sign
    if (s[i] == '-') {
        sign = -1;
        i++;
    } else if (s[i] == '+') {
        i++;
    }

    // Step 3: Read digits until non-digit or end
    while (s[i] >= '0' && s[i] <= '9') {
        int digit = s[i] - '0';

        // Step 4: Check overflow before updating result
        if (result > INT_MAX / 10 ||
           (result == INT_MAX / 10 && digit > 7)) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        result = result * 10 + digit;
        i++;
    }

    return sign * result;
}
```

---

## Walkthrough

### Example 1: `s = "42"`

| Step | Action | i | result | sign |
|------|--------|---|--------|------|
| Whitespace | none | 0 | 0 | +1 |
| Sign | none | 0 | 0 | +1 |
| Digit `4` | result = 4 | 1 | 4 | +1 |
| Digit `2` | result = 42 | 2 | 42 | +1 |

Return `1 * 42 = 42` ✅

### Example 2: `s = " -042"`

| Step | Action | i | result | sign |
|------|--------|---|--------|------|
| Whitespace | skip 3 spaces | 3 | 0 | +1 |
| Sign `'-'` | sign = -1 | 4 | 0 | -1 |
| Digit `0` | result = 0 | 5 | 0 | -1 |
| Digit `4` | result = 4 | 6 | 4 | -1 |
| Digit `2` | result = 42 | 7 | 42 | -1 |

Return `-1 * 42 = -42` ✅

### Example 3: `s = "1337c0d3"`

| Step | Action | i | result |
|------|--------|---|--------|
| Digits `1337` | read until `'c'` | 4 | 1337 |
| `'c'` | stop | — | — |

Return `1337` ✅

---

## Complexity Analysis

| | Value |
|---|---|
| **Time Complexity** | O(n) — single pass through the string |
| **Space Complexity** | O(1) — only a few variables used |
