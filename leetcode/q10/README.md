# [10. 正则表达式匹配](https://leetcode.cn/problems/regular-expression-matching/) ❌

| Language              | Status |
|:----------------------|:-------|
| <a id="C++">C++</a>   | ✅      |
| <a id="Rust">Rust</a> | ❌      |
| Go                    | ❌      |
| Java                  | ❌      |
| Python                | ❌      |


### C++

#### Solution1 

```cpp
class Solution1 {
 public:
    bool isMatch(std::string s, std::string p) {
        int m = s.size(), n = p.size();
        memo_ = std::vector<std::vector<int>>(m, std::vector<int>(n, -1));
        // 指针i, j 从0开始
        return dp(s, 0, p, 0);
    }

 private:
    bool dp(const std::string& s, int i, const std::string& p, int j) {
        int m = s.size(), n = p.size();
        // base case
        if (j == n) {
            return i == m;
        }
        if (i == m) {
            if ((n - j) % 2 == 1) {
                return false;
            }
            for (; j + 1 < n; j += 2) {
                if (p[j + 1] != '*') {
                    return false;
                }
            }
            return true;
        }

        // 查找备忘录
        if (memo_[i][j] != -1) {
            return memo_[i][j];
        }

        bool res = false;

        if (s[i] == p[j] || p[j] == '.') {
            if (j < n - 1 && p[j + 1] == '*') {
                res = dp(s, i, p, j + 2) || dp(s, i + 1, p, j);
            } else {
                res = dp(s, i + 1, p, j + 1);
            }
        } else {
            if (j < n - 1 && p[j + 1] == '*') {
                res = dp(s, i, p, j + 2);
            } else {
                res = false;
            }
        }

        // 记入备忘录
        memo_[i][j] = res;
        return res;
    }

 private:
    std::vector<std::vector<int>> memo_;
};
```

#### Solution2

```cpp
class Solution2 {
 public:
    bool isMatch(std::string s, std::string p) {
        int m = s.size();
        int n = p.size();

        auto matches = [&](int i, int j) {
            if (i == 0) {
                return false;
            }
            if (p[j - 1] == '.') {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        std::vector<std::vector<int>> f(m + 1, std::vector<int>(n + 1));
        f[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    f[i][j] |= f[i][j - 2];
                    if (matches(i, j - 1)) {
                        f[i][j] |= f[i - 1][j];
                    }
                } else {
                    if (matches(i, j)) {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }
        return f[m][n];
    }
};
```