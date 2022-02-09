import sys
import os


def initRustCode(filename: str):
    solution_file_path = "./codes/rust/src/solutions/"
    mod_file_path = "./codes/rust/src/solutions/mod.rs"
    with open(mod_file_path, "r") as f:
        lines = f.readlines()
        for line in lines:
            line = line.strip()
            if line[6:-1] == filename:
                print("file exist! exit.")
                exit(0)
    with open(mod_file_path, "a") as f:
        f.write("mod s_{};\n".format(filename))
    rust_test_template = """
#[cfg(test)]
mod tests {{
    use super::*;
    #[test]
    fn test_{}() {{
        // assert_eq!();
    }}
}}
""".format(filename)
    ans_file_path = solution_file_path + "s_{}.rs".format(filename)
    if os.path.exists(ans_file_path):
        print("[+] File exists, exit!")
        return
    with open(ans_file_path, "w") as f:
        f.write("pub struct Solution {}" + "\n"*3)
        f.write(rust_test_template)


def initCppCode(filename: str):
    cpp_main_template = """
int main ()
{
    Solution sol;


    return 0;
}
"""
    ans_file_path = "./codes/cpp/{}.cpp".format(filename)
    if os.path.exists(ans_file_path):
        print("[+] File exists, exit!")
        return
    with open(ans_file_path, 'w') as f:
        f.write('#include "global.hpp"' + '\n' * 3)
        f.write(cpp_main_template)


def initCode(language: str, filename: str):
    language = language.lower()
    if language == "rust":
        initRustCode(filename)
    elif language == "cpp":
        initCppCode(filename)
    else:
        exit(0)


if __name__ == '__main__':
    # Usage: python init.py rust 1748
    language = sys.argv[1].lower()
    filename = sys.argv[2]
    initCode(language, filename)
