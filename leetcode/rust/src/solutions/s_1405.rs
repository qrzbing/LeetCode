pub struct Solution {}

impl Solution {
    pub fn longest_diverse_string(a: i32, b: i32, c: i32) -> String {
        // 初始化字符 pair
        let mut ch = vec![(a, 'a'), (b, 'b'), (c, 'c')];
        let mut ans = vec![];
        loop {
            // 每次排序
            ch.sort_unstable();
            // 如果数量最大的字符数量为 0，退出
            if ch[2].0 == 0 {
                break;
            }
            let len = ans.len();
            // 贪心处理
            if len >= 2 && ans[len - 1] == ans[len - 2] && ans[len - 1] == ch[2].1 {
                if ch[1].0 > 0 {
                    ch[1].0 -= 1;
                    ans.push(ch[1].1);
                } else {
                    ch[2].0 -= 1;
                }
            } else {
                ch[2].0 -= 1;
                ans.push(ch[2].1);
            }
        }
        // 学习：collect 会消费迭代器并创建一个新的 String
        ans.iter().collect()
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_1405() {
        assert_eq!(Solution::longest_diverse_string(1, 1, 7), "ccbccacc");
    }
}
