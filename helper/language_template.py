python_solution_template = """\
from typing import List
from collections import defaultdict
from functools import cmp_to_key
""" + "\n" * 3 + """
if __name__ == '__main__':
    sol = Solution()
"""

cpp_solution_template = """#include "global.hpp"
""" + "\n"*3 + """
int main ()
{
    Solution sol;
    // assert(sol.Func() == xx);

    return 0;
}
"""

rust_solution_template = """pub struct Solution {{}}
""" + "\n" * 3 + """
#[cfg(test)]
mod tests {{
    use super::*;
    #[test]
    fn test_{}() {{
        // assert_eq!();
    }}
}}
"""
