#include <string>
#include <vector>

class Solution {
 public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> res;
        if (digits.empty()) {
            return res;
        }
        // 数字到字母的映射
        std::vector<std::string> mappings = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        backtrack(digits, mappings, res, 0, "");

        return res;
    }

 private:
    void backtrack(const std::string& digits, const std::vector<std::string>& mappings, std::vector<std::string>& res,
                   int start, std::string path) {
        if (path.length() == digits.length()) {
            res.push_back(path);
            return;
        }

        for (int i = start; i < digits.length(); ++i) {
            int digit = digits[i] - '0';
            for (int j = 0; j < mappings[digit].length(); ++j) {
                path.push_back(mappings[digit][j]);
                backtrack(digits, mappings, res, i + 1, path);
                path.pop_back();
            }
        }
    }
};