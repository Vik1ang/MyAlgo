#include <unordered_map>
#include <vector>

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
