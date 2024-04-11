class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        string result = "";
        
        for (char digit : num) {
            while (result.length() > 0 && result.back() > digit && k > 0) {
                result.pop_back();
                k--;
            }
            if (result.length() == 0 && digit == '0')
                continue; // Skip leading zeros
            result.push_back(digit);
        }
        
        // If k is still greater than 0, remove remaining digits from the end
        while (k > 0 && !result.empty()) {
            result.pop_back();
            k--;
        }
        
        // Handle case where all digits are removed
        if (result.empty())
            return "0";
        
        return result;
    }
    
};