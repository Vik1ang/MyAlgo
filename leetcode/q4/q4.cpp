#include <vector>

class Solution {
 public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int left = (n + m + 1) / 2;
        int right = (n + m + 2) / 2;
        // 将奇数和偶数的情况合并, 奇数的情况下两个相等的中位数就是答案
        return (getKth(nums1, 0, n - 1, nums2, 0, m - 1, left) + getKth(nums1, 0, n - 1, nums2, 0, m - 1, right)) * 0.5;
    }

 private:
    inline int getKth(const std::vector<int>& nums1, int start1, int end1, const std::vector<int>& nums2, int start2, int end2,
               int k) {
        int len1 = end1 - start1 + 1;
        int len2 = end2 - start2 + 1;
        // 让 len1 的长度小于 len2, 这样就能保证如果有数组空了,一定是 len1
        if (len1 > len2) {
            return getKth(nums2, start2, end2, nums1, start1, end1, k);
        }
        if (len1 == 0) {
            return nums2[start2 + k - 1];
        }

        if (k == 1) {
            return std::min(nums1[start1], nums2[start2]);
        }

        int i = start1 + std::min(len1, k / 2) - 1;
        int j = start2 + std::min(len2, k / 2) - 1;

        if (nums1[i] > nums2[j]) {
            return getKth(nums1, start1, end1, nums2, j + 1, end2, k - (j - start2 + 1));
        } else {
            return getKth(nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1));
        }
    }
};