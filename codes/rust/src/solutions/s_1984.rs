pub struct Solution {}

impl Solution {
    pub fn minimum_difference(mut nums: Vec<i32>, k: i32) -> i32 {
        if k == 1 {
            return 0;
        }
        nums.sort_unstable();
        nums.windows(k as usize)    // 这里的 windows 返回一个 iter, 对 next unwrap 之后是 &[a,b,...]
            .into_iter()
            .map(|x| (x[0] - x[x.len() - 1]).abs())
            .min()
            .unwrap()
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_1984() {
        assert_eq!(Solution::minimum_difference(vec![9,4,1,7], 2), 2);
        assert_eq!(Solution::minimum_difference(vec![87063, 61094, 44530, 21297, 95857, 93551, 9918], 6), 74560);
    }
}
