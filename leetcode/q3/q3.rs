use std::collections::HashSet;

struct Solution;

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