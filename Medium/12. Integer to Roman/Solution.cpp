#include <string>
#include <vector>

class Solution {
public:
    string intToRoman(int num) {
        // Pair values with their Roman numeral representations in descending order
        std::vector<std::pair<int, std::string>> romanMap = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };
        
        std::string result = "";
        
        for (const auto& [value, symbol] : romanMap) {
            // While the current value can be subtracted from num
            while (num >= value) {
                result += symbol;
                num -= value;
            }
        }
        
        return result;
    }
};
