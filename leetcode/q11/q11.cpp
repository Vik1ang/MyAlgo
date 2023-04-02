#include <vector>

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