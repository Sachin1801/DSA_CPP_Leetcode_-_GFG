class Solution {
public:
    static unordered_map<char, int> values;
    int romanToInt(string s) {
        char lastSymbol = s[s.size() - 1];
        int lastValue = values[lastSymbol];
        int total = lastValue;

        for (int i = s.size() - 2; i >= 0; i--) {
            char currentSymbol = s[i];
            int currentValue = values[currentSymbol];
            if (currentValue < lastValue) {
                total -= currentValue;
            } else {
                total += currentValue;
            }
            lastValue = currentValue;
        }
        return total;
    }
};

unordered_map<char, int> Solution::values = {
    {'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50},
    {'X', 10},   {'V', 5},   {'I', 1}};