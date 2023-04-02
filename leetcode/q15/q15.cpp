#include <algorithm>
#include <vector>

int main() {}

namespace Q15 {
class Solution {
 public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        size_t len = nums.size();
        // 当前长度小于3直接退出
        if (len < 3) {
            return res;
        }
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < len; ++i) {
            // 如果遍历的起始元素大于0, 就直接退出
            // 最小的数都大于0了, 后面的数都大于0, 三数之和肯定大于0
            if (nums[i] > 0) {
                break;
            }

            // 去重, 当前的起始值等于前一个元素, 那么得到的结果将会和前一次相同
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            size_t left = i + 1;
            size_t right = len - 1;
            while (left < right) {
                // 三数之和
                int sum = nums[i] + nums[left] + nums[right];
                // 如果等于0, 将结果对应的索引位置加入结果集
                if (sum == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});

                    // 移动左右指针, 把重复的去掉

                    // 去重, 因为i不变,  l取的数的值与前一个数相同, 所以不用在计算, 直接跳
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    // 去重, 因为i不变,  r取的数的值与前一个数相同, 所以不用在计算, 直接跳
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }

                    // 移动左右指针
                    left++;
                    right--;
                } else if (sum < 0) {
                    // 如果小于0, 将左指针右移
                    left++;
                } else {
                    // 如果大于0, 将右指针左移
                    right--;
                }
            }
        }
        
        return res;
    }
};
}  // namespace Q15