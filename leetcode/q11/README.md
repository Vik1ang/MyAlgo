# [11. 盛最多水的容器](https://leetcode.cn/problems/container-with-most-water/) ❌

| Language              | Status |
|:----------------------|:-------|
| <a id="C++">C++</a>   | ✅      |
| <a id="Rust">Rust</a> | ✅      |
| Go                    | ❌      |
| Java                  | ❌      |
| Python                | ❌      |


### C++

```cpp
namespace Q11 {
class Solution {
 public:
    int maxArea(std::vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int res = 0;
        while (left < right) {
            // [left, right] 之间的矩形面积
            int cur_area = std::min(height[left], height[right]) * (right - left);
            res = std::max(res, cur_area);

            // 双指针移动较低的一边
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return res;
    }
};
}  // namespace Q11

```

### Rust

```rust
impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let mut left = 0;
        let mut right = height.len() - 1;
        let mut res = 0;

        while left < right {
            let area = min(height[left], height[right]) * (right - left) as i32;
            res = max(res, area);

            if height[left] < height[right] {
                left += 1;
            } else {
                right -= 1;
            }
        }

        res
    }
}
```