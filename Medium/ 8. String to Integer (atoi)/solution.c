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
