# [17. 电话号码的字母组合](https://leetcode.cn/problems/letter-combinations-of-a-phone-number/) ❌

| Language              | Status |
|:----------------------|:-------|
| <a id="C++">C++</a>   | ✅      |
| <a id="Rust">Rust</a> | ✅      |
| Go                    | ❌      |
| Java                  | ❌      |
| Python                | ❌      |


### C++

```cpp
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
```

### Rust

```rust
struct Solution;

impl Solution {
    pub fn letter_combinations(digits: String) -> Vec<String> {
        let mut res = vec![];
        if digits.is_empty() {
            return res;
        }
        let mappings: &[&str] = &["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"];
        let mut path = String::new();
        backtrack(&digits, mappings, &mut res, 0, &mut path);
        res
    }
}

fn backtrack(digits: &str, mappings: &[&str], res: &mut Vec<String>, start: usize, path: &mut String) {
    if path.len() == digits.len() {
        res.push(path.clone());
        return;
    }

    let digit = digits.chars().nth(start).unwrap().to_digit(10).unwrap() as usize;

    for ch in mappings[digit].chars() {
        path.push(ch);
        backtrack(digits, mappings, res, start + 1, path);
        path.pop();
    }
}
```