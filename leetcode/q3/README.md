# [3. 无重复字符的最长子串](https://leetcode.cn/problems/longest-substring-without-repeating-characters/) ❌

| Language              | Status |
|:----------------------|:-------|
| <a id="C++">C++</a>   | ✅      |
| <a id="Rust">Rust</a> | ✅      |
| Go                    | ❌      |
| Java                  | ❌      |
| Python                | ❌      |


### C++

```cpp
namespace Q3 {
class Solution {
 public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> window;

        int left = 0, right = 0;
        int res = 0;

        while (right < s.size()) {
            char c = s[right];
            right++;
            // 进行窗口内数据的一系列更新
            window[c]++;
            // 判断左侧窗口是否要收缩
            while (window[c] > 1) {
                char d = s[left];
                left++;
                // 进行窗口内数据的一系列更新
                window[d]--;
            }
            // 在这里更新答案
            res = std::max(res, right - left);
        }

        return res;
    }
};
}  // namespace Q3
```

### Rust

```rust
impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode {
            next: None,
            val,
        }
    }
}

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut window = HashSet::new();
        let mut left = 0;
        let mut right = 0;
        let mut res = 0;
        let mut s_arr: Vec<char> = s.chars().collect();

        s_arr.iter().enumerate().for_each(|(i, ch)| {
            while window.contains(ch) {
                window.remove(&s_arr[left as usize]);
                left += 1;
            }
            window.insert(ch);
            res = res.max(right - left + 1);
            right += 1;
        });

        res
    }
}
```