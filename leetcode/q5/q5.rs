struct Solution;

impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        let mut res = String::new();

        for i in 0..s.len() {
            // 以s[i]为中心的最长回文子串
            let s1 = palindrome(&s, i, i);
            // 以s[i]和s[i+1]为中心的最长回文子串
            let s2 = palindrome(&s, i, i + 1);

            if s1.len() > res.len() {
                res = s1;
            }
            if s2.len() > res.len() {
                res = s2;
            }
        }

        res
    }
}

fn palindrome(s: &str, mut left: usize, mut right: usize) -> String {
    let s_arr = s.as_bytes();
    while left > 0 && right < s.len() && s_arr[left - 1] == s_arr[right] {
        left -= 1;
        right += 1;
    }

    return String::from(&s[left..right]);
}

fn main() {
    Solution::longest_palindrome(String::from("babad"));
    println!("Hello, world!");
}
