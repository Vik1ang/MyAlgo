# [1. 两数之和](https://leetcode.cn/problems/two-sum/)

| Language              | Status |
|:----------------------|:-------|
| <a id="C++">C++</a>   | ✅      |
| <a id="Rust">Rust</a> | ❌      |
| Go                    | ❌      |
| Java                  | ❌      |
| Python                | ❌      |


### C++

```cpp
namespace Q1 {
class Solution {
 public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> hash_map;
        for (int i = 0; i < nums.size(); i++) {
            auto it = hash_map.find(target - nums[i]);
            if (it != hash_map.end()) {
                return {it->second, i};
            }
            hash_map[nums[i]] = i;
        }
        return {};
    }
};
}  // namespace Q1
```

### Rust

```rust
```