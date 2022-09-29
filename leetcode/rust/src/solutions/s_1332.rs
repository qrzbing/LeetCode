pub struct Solution {}

impl Solution {
    pub fn remove_palindrome_sub(s: String) -> i32 {
        let s: Vec<char> = s.chars().collect();
        let (mut l, mut r) = (0, s.len() - 1);
        while l < r {
            if s[l] != s[r] {
                return 2;
            }
            l += 1;
            r -= 1;
        }
        1
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_1332() {
        assert_eq!(1, Solution::remove_palindrome_sub("ababa".to_string()));
        assert_eq!(2, Solution::remove_palindrome_sub("abb".to_string()));
        assert_eq!(2, Solution::remove_palindrome_sub("baabb".to_string()));
    }
}
