pub struct Solution {}

impl Solution {
    pub fn sum_of_unique(nums: Vec<i32>) -> i32 {
        let mut cnt = vec![0; 101];
        for num in nums {
            cnt[num as usize] += 1;
        }
        let mut ret = 0;
        for (i, &n) in cnt.iter().enumerate() {
            if n == 1 {
                ret += i as i32;
            }
        }
        ret
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_1748() {
        assert_eq!(4, Solution::sum_of_unique(vec![1, 2, 3, 2]));
        assert_eq!(0, Solution::sum_of_unique(vec![1, 1, 1, 1]));
        assert_eq!(15, Solution::sum_of_unique(vec![1, 2, 3, 4, 5]));
    }
}
