# 12. Integer to Roman

**Difficulty:** <img src="https://img.shields.io/badge/-Medium-orange" vertical-align="middle" />
**Language:** `C++`
**Topics:** `Hash Table`, `Math`, `String`

---

### 📝 Problem Description
Seven different symbols represent Roman numerals with the following values:

| Symbol | Value |
| :--- | :--- |
| I | 1 |
| V | 5 |
| X | 10 |
| L | 50 |
| C | 100 |
| D | 500 |
| M | 1000 |

Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral has the following rules:

* If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, subtract its value, and convert the remainder.
* If the value starts with 4 or 9 use the **subtractive form** representing one symbol subtracted from the following symbol.

### 💡 Examples

**Example 1:**
> **Input:** `num = 3749`  
> **Output:** `"MMMDCCXLIX"`  
> **Explanation:** > 3000 = MMM (1000+1000+1000)
>  700 = DCC (500+100+100)
>   40 = XL (50-10)
>    9 = IX (10-1)

**Example 2:**
> **Input:** `num = 58`  
> **Output:** `"LVIII"`  
> **Explanation:** 50 = L, 8 = VIII.

**Example 3:**
> **Input:** `num = 1994`  
> **Output:** `"MCMXCIV"`  
> **Explanation:** 1000 = M, 900 = CM, 90 = XC, 4 = IV.

---

### ⚙️ Constraints
- `1 <= num <= 3999`

---
