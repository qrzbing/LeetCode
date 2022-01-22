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
