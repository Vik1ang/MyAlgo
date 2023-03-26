use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut hash_map = HashMap::with_capacity(nums.len());

        for i in 0..nums.len() {
            if let Some(k) = hash_map.get(&(target - nums[i])) {
                if *k != i {
                    return vec![*k as i32, i as i32];
                }
            }
            hash_map.insert(nums[i], i);
        }

        panic!("No two sum solution");
    }
}