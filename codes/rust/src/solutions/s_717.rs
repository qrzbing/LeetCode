pub struct Solution {}

impl Solution {
    pub fn is_one_bit_character(bits: Vec<i32>) -> bool {
        let mut i = 0;
        while i < bits.len() {
            if bits[i] == 1 {
                if i == bits.len() - 1 || i + 1 == bits.len() - 1 {
                    return false;
                } else {
                    i += 2;
                }
            } else {
                i += 1;
            }
        }
        true
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_717() {
        // assert_eq!();
    }
}
