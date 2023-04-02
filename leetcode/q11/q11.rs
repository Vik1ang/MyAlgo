struct Solution;

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
