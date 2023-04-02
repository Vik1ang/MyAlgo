# [5. 最长回文子串](https://leetcode.cn/problems/longest-palindromic-substring/) ❌

| Language              | Status |
|:----------------------|:-------|
| <a id="C++">C++</a>   | ✅      |
| <a id="Rust">Rust</a> | ✅      |
| Go                    | ❌      |
| Java                  | ❌      |
| Python                | ❌      |


### C++

```cpp
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

```

### Rust

```rust
impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        let mut res = String::new();

        for i in 0..s.len() {
            // 以s[i]为中心的最长回文子串
            let s1 = palindrome(&s, i, i);
            // 以s[i]和s[i+1]为中心的最长回文子串
            let s2 = palindrome(&s, i, i + 1);

            if s1.len() > res.len() {
                res = s1;
            }
            if s2.len() > res.len() {
                res = s2;
            }
        }

        res
    }
}

fn palindrome(s: &str, mut left: usize, mut right: usize) -> String {
    let s_arr = s.as_bytes();
    while left > 0 && right < s.len() && s_arr[left - 1] == s_arr[right] {
        left -= 1;
        right += 1;
    }

    return String::from(&s[left..right]);
}
```