pub struct Solution {}

impl Solution {
    pub fn single_non_duplicate(nums: Vec<i32>) -> i32 {
        let mut l = 0;
        let mut r = nums.len() - 1;
        while l < r {
            let m = (l + r) / 2;
            if (m % 2 == 1 && nums[m] == nums[m - 1]) || (m % 2 == 0 && nums[m] == nums[m + 1]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        nums[l]
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_540() {
        assert_eq!(
            2,
            Solution::single_non_duplicate(vec![1, 1, 2, 3, 3, 4, 4, 8, 8])
        );
        assert_eq!(
            10,
            Solution::single_non_duplicate(vec![3, 3, 7, 7, 10, 11, 11])
        );
    }
}
