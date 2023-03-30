#include <string>

namespace Q5 {
class Solution {
 public:
    std::string longestPalindrome(std::string s) {
        std::string res;
        for (int i = 0; i < s.length(); i++) {
            // 以s[i]为中心的最长回文子串
            std::string s1 = palindrome(s, i, i);
            // 以s[i]和s[i+1]为中心的最长回文子串
            std::string s2 = palindrome(s, i, i + 1);

            res = res.length() > s1.length() ? res : s1;
            res = res.length() > s2.length() ? res : s2;
        }

        return res;
    }

 private:
    inline std::string palindrome(const std::string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }
};
}  // namespace Q5
