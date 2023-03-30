struct Solution;

impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let n = nums1.len();
        let m = nums2.len();
        let left = (n + m + 1) / 2;
        let right = (n + m + 2) / 2;

        (get_kth(&nums1, 0, n - 1, &nums2, 0, m - 1, left) + get_kth(&nums1, 0, n - 1, &nums2, 0, m - 1, right)) as f64 / 2.0
    }
}

fn get_kth(nums1: &Vec<i32>, start1: usize, end1: usize, nums2: &Vec<i32>, start2: usize, end2: usize, k: usize) -> i32 {
    let len1 = end1 - start1 + 1;
    let len2 = end2 - start2 + 1;

    if len1 > len2 {
        return get_kth(nums2, start2, end2, nums1, start1, end1, k);
    }

    if len1 == 0 {
        return nums2[start2 + k - 1] as i32;
    }

    if k == 1 {
        return std::cmp::min(nums1[start1], nums2[start2]);
    }

    let i = start1 + std::cmp::min(len1, k / 2) - 1;
    let j = start2 + std::cmp::min(len2, k / 2) - 1;

    return if nums1[i] > nums2[j] {
        get_kth(nums1, start1, end1, nums2, j + 1, end2, k - (j - start2 + 1))
    } else {
        get_kth(nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1))
    };
}