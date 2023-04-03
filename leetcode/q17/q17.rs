struct Solution;

impl Solution {
    pub fn letter_combinations(digits: String) -> Vec<String> {
        let mut res = vec![];
        if digits.is_empty() {
            return res;
        }
        let mappings: &[&str] = &["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"];
        let mut path = String::new();
        backtrack(&digits, mappings, &mut res, 0, &mut path);
        res
    }
}

fn backtrack(digits: &str, mappings: &[&str], res: &mut Vec<String>, start: usize, path: &mut String) {
    if path.len() == digits.len() {
        res.push(path.clone());
        return;
    }

    let digit = digits.chars().nth(start).unwrap().to_digit(10).unwrap() as usize;

    for ch in mappings[digit].chars() {
        path.push(ch);
        backtrack(digits, mappings, res, start + 1, path);
        path.pop();
    }
}